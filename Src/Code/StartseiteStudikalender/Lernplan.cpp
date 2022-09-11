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


void Lernplan::LernplanLoeschen(int idNutzer) {
    QSqlQuery Query;

    Query.prepare("DELETE FROM Termin WHERE idNutzer_fk = :idNutzer AND Datum >= :heute AND TeilLernplan = '1'");
    Query.bindValue(":idNutzer", idNutzer);
    Query.bindValue(":heute", QDate::currentDate());

    if(!Query.exec()) {
        throw "Connection error";
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

int Lernplan::RechneStunden(QDate start, QDate ende, int idNutzer) {
    //Hier wird die Zeit der Termine + Lernplan berechnet
    Kalender k;
    k.TermineInWoche(start, ende, idNutzer);
    this->Termine = k.Termine;

    SetZeroSeconds();
    prepareTermine();

    k.StudienfachVonNutzer(idNutzer);
    this->Studienfaecher = k.Studienfaecher;

    if(this->Studienfaecher[0]._Eigenstunden == -1) {
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

bool Lernplan::checkStunden(QDate start, QDate ende, int idNutzer) {
    int zeit = RechneStunden(start, ende, idNutzer);

    if(zeit > (7*14*60) || zeit < 0) {
        return false;
    }
    else {
        return true;
    }

}

bool Lernplan::LernplanErstellenStart(int idNutzer) {
    QDate StartWoche = QDate::currentDate();
    this->AktuelleWoche = StartWoche.addDays(6);

    while(this->AktuelleWoche <= this->EndDatum) {
        if(!LernplanErstellenWoche(StartWoche, this->AktuelleWoche, idNutzer)) {
            return false;
        }
        StartWoche = StartWoche.addDays(7);
        this->AktuelleWoche = StartWoche.addDays(6);
    }
    return true;
}

bool Lernplan::LernplanErstellenWoche(QDate DatumWochenBeginn, QDate DatumWochenEnde, int idNutzer) {
    if(!checkStunden(DatumWochenBeginn, DatumWochenEnde, idNutzer)) {
        return false;
    }
    else {
        QDate Datum = DatumWochenBeginn;
        while(Datum <= DatumWochenEnde) {
            LernplanErstellenTag(Datum, idNutzer);
            Datum = Datum.addDays(1);
        }
        return true;
    }
}

void Lernplan::LernplanErstellenTag(QDate Datum, int idNutzer) {
    QSqlQuery Query;

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

                            t.TerminInsert( "Lernen " + i->_Bezeichnung, Datum, LStart, LZiel, "Lernplan-Termin für das Fach " + i->_Bezeichnung, NullH, 1,0, 1, idNutzer);

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
                            t.TerminInsert( "Lernen " + i->_Bezeichnung, Datum, LStart, LZiel, "Lernplan-Termin für das Fach " + i->_Bezeichnung, NullH, 1,0, 1, idNutzer);

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
                            t.TerminInsert( "Lernen " + i->_Bezeichnung, Datum, LStart, LZiel, "Lernplan-Termin für das Fach " + i->_Bezeichnung, NullH, 1, 0,1, idNutzer);

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


