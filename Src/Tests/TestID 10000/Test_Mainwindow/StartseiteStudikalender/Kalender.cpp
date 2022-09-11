#include "Kalender.h"
#include "Datenbank.h"


//alle Termine in einer Woche
void Kalender::TermineInWoche(QDate DatumWochenBeginn, QDate DatumWochenEnde,int idNutzer){
    QSqlQuery Query;

    AchtUhr.setHMS(8, 0, 0); //Untere Grenze des Lernplans
    ZehnUhr.setHMS(22, 0, 0); //Obere Grenze des Lernplans

    Termin t;
    this->Termine.clear(); //Sichergehen das Vector leer
    this->Termine.shrink_to_fit();

    Query.prepare("SELECT Datum, Beginn, Ende, idTermin, TeilLernplan, Terminname FROM Termin "
                  "WHERE idNutzer_fk = :idNutzer AND Datum BETWEEN :DBeginn AND :DEnde "
                  "AND Ende > '8:0:0' AND Beginn < '22:0:0' ORDER BY Datum, Beginn");
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

                setUntereGrenze(&t);
                setObereGrenze(&t);

                DatumWochenBeginn = DatumWochenBeginn.addDays(1);
            }
        }
        else {
            while(DatumWochenBeginn < Query.value(0).toDate()) {
                //Alle ersten freien Tage mit Unter- und Obergrenze füllen
                t.Datum = DatumWochenBeginn;

                setUntereGrenze(&t);
                setObereGrenze(&t);

                DatumWochenBeginn = DatumWochenBeginn.addDays(1);
            }

            Query.previous();
            while(Query.next()) {
                t.Datum = DatumWochenBeginn;
                setUntereGrenze(&t);

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

                setObereGrenze(&t);

                DatumWochenBeginn = DatumWochenBeginn.addDays(1);
                Query.previous();
            }

            while(DatumWochenBeginn <= DatumWochenEnde) {
                //Alle restlichen freien Tage mit Unter- und Obergrenze füllen
                t.Datum = DatumWochenBeginn;

                setUntereGrenze(&t);
                setObereGrenze(&t);

                DatumWochenBeginn = DatumWochenBeginn.addDays(1);
            }


        }
        return;
    }
}

void Kalender::setUntereGrenze(Termin *t) {
    t->Beginn = AchtUhr;
    t->Ende = AchtUhr;
    t->TerminName = "Untere Grenze";
    t->TeilLernplan = 0;
    Termine.push_back(*t);
}

void Kalender::setObereGrenze(Termin *t) {
    t->Beginn = ZehnUhr;
    t->Ende = ZehnUhr;
    t->TerminName = "Obere Grenze";
    t->TeilLernplan = 0;
    Termine.push_back(*t);
}

//Funktion, die alle Studienfächer des Nutzers in QVector speichern
void Kalender::StudienfachVonNutzer(int idNutzer) {
    QSqlQuery Query;

    this->Studienfaecher.clear();
    this->Studienfaecher.shrink_to_fit();
    Studienfach s;

    Query.prepare("SELECT Bezeichnung, Eigenstunden FROM studienfach WHERE idNutzer_fk = :idNutzer ORDER BY idStudienfach");
    Query.bindValue(":idNutzer", idNutzer);

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

bool Kalender::CheckLernplan(int idNutzer) {
    QSqlQuery Query;

    Query.prepare("SELECT TeilLernplan FROM Termin "
                  "WHERE idNutzer_fk = :idNutzer AND Datum > :heute");
    Query.bindValue(":heute", QDate::currentDate());
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


//Author: André Zimmer
void Kalender::getTermin(QDate Datum) {
    QSqlQueryModel * model = new QSqlQueryModel();

    NProfil *NP = NProfil::getInstance();

    int idNutzer_fk = NP->idNutzer;

    model->setQuery("SELECT  * FROM Termin ORDER BY Beginn"); //Durchsucht die Tabelle


    for (int i = 0; i < model->rowCount(); ++i) {// Geht alle Termine durch und sucht den Passenden
     int id = model->record(i).value("idTermin").toInt();
     QString name = model->record(i).value("Terminname").toString();
     QDate date =model->record(i).value("Datum").toDate();
     QTime beginn= model->record(i).value("Beginn").toTime();
     QTime ende= model->record(i).value("Ende").toTime();
     QString beschreibung= model->record(i).value("Beschreibung").toString();
     int idnutzer_fk =model->record(i).value("idNutzer_fk").toInt();

    if(idNutzer_fk==idnutzer_fk&&Datum==date){//Vergleiche ob es der richtige Tag und Nutzer ist

        //Daten in die QListen schreiben:
        BLidTermin.append(id);
        BLTerminname.append(name);
        BLDatum.append(date);
        BLBeginn.append(beginn);
        BLEnde.append(ende);
        BLBeschreibung.append(beschreibung);
    }

    }
}
