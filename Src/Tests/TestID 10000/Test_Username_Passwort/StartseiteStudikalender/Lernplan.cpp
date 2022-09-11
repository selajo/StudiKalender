#include "Lernplan.h"


//Author: Josef Lanzl

Lernplan::Lernplan() {
    EndDatum = QDate::currentDate();
    AktuelleWoche = EndDatum;
    Termine.clear();
    Studienfaecher.clear();
}

Lernplan::~Lernplan() {
    EndDatum = QDate::currentDate();
    AktuelleWoche = EndDatum;
    Termine.clear();
    Termine.shrink_to_fit();
    Studienfaecher.clear();
    Studienfaecher.shrink_to_fit();
}


void Lernplan::LernplanLoeschen(QSqlQuery Query, int idNutzer) {
    Query.prepare("DELETE FROM Termin WHERE idNutzer_fk = :idNutzer AND Datum >= :heute AND TeilLernplan = '1'");
    Query.bindValue(":idNutzer", idNutzer);
    Query.bindValue(":heute", QDate::currentDate());

    if(!Query.exec()) {
        throw "Connection error";
    }
}

//alle Termine in einer Woche
void Lernplan::TermineInWoche(QSqlQuery Query, QDate DatumWochenBeginn, QDate DatumWochenEnde,int idNutzer){
    QTime AchtUhr;
    AchtUhr.setHMS(8, 0, 0); //Untere Grenze des Lernplans
    QTime ZehnUhr;
    ZehnUhr.setHMS(22, 0, 0); //Obere Grenze des Lernplans

    Termin t;
    this->Termine.clear(); //Sichergehen das Keine Werte drinnen stehen
    this->Termine.shrink_to_fit();

    Query.prepare("SELECT Datum, Beginn, Ende, idTermin, TeilLernplan, Terminname FROM Termin "
                  "WHERE idNutzer_fk = :idNutzer AND Datum BETWEEN :DBeginn AND :DEnde "
                  "AND Ende > '8:0:0' AND Beginn < '22:0:0' ORDER BY Datum, Beginn"); //Durchsucht die Tabelle
    Query.bindValue(":idNutzer", idNutzer);
    Query.bindValue(":DBeginn", DatumWochenBeginn);
    Query.bindValue(":DEnde", DatumWochenEnde);

    if(!Query.exec()) {
        throw "Connection error";
    }
    else {
        if(!Query.first()) {
            //Keine Termine
            while(DatumWochenBeginn <= DatumWochenEnde) {
                //Alles mit Unter- und Obergrenze füllen
                t.Datum = DatumWochenBeginn;
                t.Beginn = AchtUhr;
                t.Ende = AchtUhr;
                t.TerminName = "Untere Grenze";
                t.TeilLernplan = 0;
                Termine.push_back(t);

                t.Beginn = ZehnUhr;
                t.Ende = ZehnUhr;
                t.TerminName = "Obere Grenze";
                t.TeilLernplan = 0;
                Termine.push_back(t);

                DatumWochenBeginn = DatumWochenBeginn.addDays(1);
            }
        }
        else {
            while(DatumWochenBeginn < Query.value(0).toDate()) {
                //Alle ersten freien Tage mit Unter- und Obergrenze füllen
                t.Datum = DatumWochenBeginn;
                t.Beginn = AchtUhr;
                t.Ende = AchtUhr;
                t.TerminName = "Untere Grenze";
                t.TeilLernplan = 0;
                Termine.push_back(t);

                t.Beginn = ZehnUhr;
                t.Ende = ZehnUhr;
                t.TerminName = "Obere Grenze";
                t.TeilLernplan = 0;
                Termine.push_back(t);

                DatumWochenBeginn = DatumWochenBeginn.addDays(1);
            }

            Query.previous();
            while(Query.next()) {
                t.Datum = DatumWochenBeginn;
                t.Beginn = AchtUhr;
                t.Ende = AchtUhr;
                t.TerminName = "Untere Grenze";
                t.TeilLernplan = 0;
                Termine.push_back(t);

                while(Query.value(0).toDate() == DatumWochenBeginn) {
                    t.Datum = Query.value(0).toDate();
                    t.Beginn = Query.value(1).toTime();
                    t.Ende = Query.value(2).toTime();
                    t.idTermin = Query.value(3).toInt();
                    t.TeilLernplan = Query.value(4).toInt();
                    t.TerminName = Query.value(5).toString();
                    this->Termine.push_back(t);
                    if(!Query.next()) {
                        break;
                    }
                }

                t.Beginn = ZehnUhr;
                t.Ende = ZehnUhr;
                t.TerminName = "Obere Grenze";
                t.TeilLernplan = 0;
                Termine.push_back(t);

                DatumWochenBeginn = DatumWochenBeginn.addDays(1);
                Query.previous();
            }

            while(DatumWochenBeginn <= DatumWochenEnde) {
                //Alle restlichen freien Tage mit Unter- und Obergrenze füllen
                t.Datum = DatumWochenBeginn;
                t.Beginn = AchtUhr;
                t.Ende = AchtUhr;
                t.TerminName = "Untere Grenze";
                t.TeilLernplan = 0;
                Termine.push_back(t);

                t.Beginn = ZehnUhr;
                t.Ende = ZehnUhr;
                t.TerminName = "Obere Grenze";
                t.TeilLernplan = 0;
                Termine.push_back(t);

                DatumWochenBeginn = DatumWochenBeginn.addDays(1);
            }


        }
        return;
    }
}



//Funktion, die alle Studienfächer des Nutzers in QVector speichern
void Lernplan::StudienfachVonNutzer(QSqlQuery Query, int idNutzer_fk){
    this->Studienfaecher.clear();
    this->Studienfaecher.shrink_to_fit();
    Studienfach s;

    Query.prepare("SELECT Bezeichnung, Eigenstunden FROM studienfach WHERE idNutzer_fk = :idNutzer ORDER BY idStudienfach");
    Query.bindValue(":idNutzer", idNutzer_fk);

    if(!Query.exec()) {
        throw "Connection error";
    }
    else {
        if(!Query.first()) {
            s._Bezeichnung = "";
            s._Eigenstunden = -1;
            Studienfaecher.push_back(s);
        }
        else {
            //Geh erst mal Query.first durc
            s._Bezeichnung = Query.value(0).toString();
            s._Eigenstunden = Query.value(1).toInt() * 60;
            Studienfaecher.push_back(s);

            //Hier die next
            while(Query.next()) {
                s._Bezeichnung = Query.value(0).toString();
                s._Eigenstunden = Query.value(1).toInt() * 60;
                Studienfaecher.push_back(s);
            }
            return;
        }
    }
}

void Lernplan::SetZeroSeconds() {
    int h, m;
    //Sekunden auf 0 setzen
    for(auto i = this->Termine.begin(); i != this->Termine.end(); i++) {
        h = i->Beginn.hour();
        m = i->Beginn.minute();
        i->Beginn.setHMS(h, m, 0);

        h = i->Ende.hour();
        m = i->Ende.minute();
        i->Ende.setHMS(h, m, 0);
    }
}

void Lernplan::prepareTermine() {
    int h;
    //Alle vor 8 Uhr: Beginn auf 8:0:0
    for(auto i = this->Termine.begin(); i != this->Termine.end(); i++) {
        h = i->Beginn.hour();
        if(h < 8) {
            i->Beginn.setHMS(8, 0, 0);
        }
    }

    //Alle nach 22 Uhr: Ende auf 22:0:0
    for(auto i = this->Termine.begin(); i != this->Termine.end(); i++) {
        h = i->Ende.hour();
        if(h >= 22) {
            i->Ende.setHMS(22, 0, 0);
        }
    }

    for(auto i = this->Termine.begin(); i != this->Termine.end(); i++) {
        for(auto j = i + 1; j != this->Termine.end(); j++) {
            //unterschiedliche Termine an gleichem Datum
            if(i->Datum.day() == j->Datum.day()) {

                //Termin von j ist in oder gleich i
                if(j->Beginn >= i->Beginn && j->Ende <= i->Ende) {
                    j->Beginn = i->Ende;
                }

                //Termin von i schneidet sich mit j
                if(i->Beginn <= j->Beginn && i->Ende > j->Beginn && j->Ende > i->Ende) {
                    j->Beginn = i->Ende;
                }


            }
            else {

            }
        }

    }
}

bool Lernplan::checkEndDatum(){
    //Überprüfe, ob gesetztes Datum überhaupt in der Zukunft liegt
    if(this->EndDatum <= QDate::currentDate().addDays(5)) {
        return false;
    }
    else {
        return true;
    }
}

int Lernplan::RechneStunden(QSqlQuery Query, QDate start, QDate ende, int idNutzer) {
    //Hier wird die Zeit der Termine + Lernplan berechnet

    TermineInWoche(Query, start, ende, idNutzer);
    SetZeroSeconds();
    prepareTermine();

    StudienfachVonNutzer(Query, idNutzer);

    if(this->Studienfaecher[0]._Eigenstunden == -1) {
        qDebug() << -1;
        return -1;
    }

    int zeit = 0;
    int hBeginn, minBeginn, hEnde, minEnde;
    int zeitTermin;

    for(auto i = this->Termine.begin(); i != this->Termine.end(); i++) {
        hBeginn = i->Beginn.hour();
        minBeginn = i->Beginn.minute();
        hEnde = i->Ende.hour();
        minEnde = i->Ende.minute();
        zeitTermin = (hEnde * 60 + minEnde) - (hBeginn * 60 + minBeginn);
        zeit += zeitTermin;
    }

    for(auto i = this->Studienfaecher.begin(); i != this->Studienfaecher.end(); i++) {
        zeit += i->_Eigenstunden;
    }

    return zeit;
}

bool Lernplan::checkStunden(QSqlQuery Query, QDate start, QDate ende, int idNutzer) {
    int zeit = RechneStunden(Query, start, ende, idNutzer);

    if(zeit > (7*14*60) || zeit < 0) {
        return false;
    }
    else {
        return true;
    }

}

bool Lernplan::CheckLernplan(QSqlQuery Query, int idNutzer) {
    Query.prepare("SELECT TeilLernplan FROM Termin "
                  "WHERE idNutzer_fk = :idNutzer AND Datum BETWEEN :heute AND :EndDatum");
    Query.bindValue(":heute", QDate::currentDate());
    Query.bindValue(":EndDatum", this->EndDatum);
    Query.bindValue(":idNutzer", idNutzer);
    if(!Query.exec()) {
        throw "Connection error";
    }
    else {
        if(!Query.first()) {
            //es existieren keine Termine, also auch keinen Lernplan
            return false;
        }
        else {
            if(Query.value(0).toInt() == 1) {
                //es existiert schon ein Lernplan
                return true;
            }
            while(Query.next()) {
                if(Query.value(0).toInt() == 1) {
                    return true;
                }
            }
            //Es gibt noch keinen Lernplan
            return false;
        }
    }
}

bool Lernplan::LernplanErstellenStart(QSqlQuery Query, int idNutzer) {
    QDate StartWoche = QDate::currentDate();
    this->AktuelleWoche = StartWoche.addDays(6);

    while(this->AktuelleWoche <= this->EndDatum) {
        if(!LernplanErstellenWoche(Query, StartWoche, this->AktuelleWoche, idNutzer)) {
            return false;
        }
        StartWoche = StartWoche.addDays(7);
        this->AktuelleWoche = StartWoche.addDays(6);
    }
    return true;
}

bool Lernplan::LernplanErstellenWoche(QSqlQuery Query, QDate DatumWochenBeginn, QDate DatumWochenEnde, int idNutzer) {
    if(!checkStunden(Query, DatumWochenBeginn, DatumWochenEnde, idNutzer)) {
        return false;
    }
    else {
        QDate Datum = DatumWochenBeginn;
        while(Datum <= DatumWochenEnde) {
            LernplanErstellenTag(Query, Datum, idNutzer);
            Datum = Datum.addDays(1);
        }
        return true;
    }
}

void Lernplan::LernplanErstellenTag(QSqlQuery Query, QDate Datum, int idNutzer) {
    QTime AchtUhr;
    AchtUhr.setHMS(8, 0, 0); //Untere Grenze des Lernplans
    QTime ZehnUhr;
    ZehnUhr.setHMS(22, 0, 0); //Obere Grenze des Lernplans

    QTime NullH;
    NullH.setHMS(0, 0, 0); //Keine Erinnerung

    int diff = 0;

    QTime LStart = AchtUhr;
    QTime LZiel;

    Termin t;


    for(auto j = Termine.begin(); j != Termine.end(); j++) {
        if(j->Datum == Datum) {

            if(LStart >= ZehnUhr) {
                return;
            }

            if(j->Beginn == AchtUhr) {
                LStart = j->Ende;
            }


            for(auto i = Studienfaecher.begin(); i != Studienfaecher.end(); i++) {

                if(j->TerminName == "Lernen " + i->_Bezeichnung && j->TeilLernplan == 1) {
                    i->_Eigenstunden = 0;
                }

                if(i->_Eigenstunden > 0) {
                    LZiel = LStart;

                    //Minutenunterschied ausrechnen
                    diff = (j->Beginn.hour() * 60 + j->Beginn.minute()) - (LStart.hour() * 60 + LStart.minute());

                    while(diff > 0) {

                        if(i == Studienfaecher.end() && i->_Eigenstunden == 0) {
                            //Alle Fächer durch: Ende
                            return;
                        }
                        else if(i->_Eigenstunden == 0){
                            //Fach ist durch: Weiter
                            continue;
                        }

                        //2-h-Blöcke erstellen
                        if(diff >= 2 * 60 && i->_Eigenstunden >= 120) {
                            LZiel = LZiel.addSecs(2 * 60 * 60);
                            diff -= 2 * 60;
                            i->_Eigenstunden -= 2 * 60;

                            t.TerminInsert(Query, "Lernen " + i->_Bezeichnung, Datum, LStart, LZiel, "Lernplan-Termin für das Fach " + i->_Bezeichnung, NullH, 1, 1, idNutzer);

                            LStart = LZiel;

                            if(i->_Eigenstunden == 0) {
                                break;
                            }
                        }
                        //Restblock erstellen
                        else if(diff > 0 && i->_Eigenstunden > diff){
                            LZiel = LZiel.addSecs(diff * 60);
                            i->_Eigenstunden -= diff;
                            diff = 0;
                            t.TerminInsert(Query, "Lernen " + i->_Bezeichnung, Datum, LStart, LZiel, "Lernplan-Termin für das Fach " + i->_Bezeichnung, NullH, 1, 1, idNutzer);

                            LStart = LZiel;

                            if(i->_Eigenstunden == 0) {
                                break;
                            }
                        }
                        else if(diff > 0 && i->_Eigenstunden <= diff) {
                            LZiel = LZiel.addSecs(i->_Eigenstunden * 60);
                            diff -= i->_Eigenstunden;
                            i->_Eigenstunden -= i->_Eigenstunden;
                            Termin t;
                            t.TerminInsert(Query, "Lernen " + i->_Bezeichnung, Datum, LStart, LZiel, "Lernplan-Termin für das Fach " + i->_Bezeichnung, NullH, 1, 1, idNutzer);

                            LStart = LZiel;
                            //Fach abgearbeitet: Nächstes Fach
                            break;
                        }

                    }
                }
            }
            LStart = j->Ende;
        }
    }
}


