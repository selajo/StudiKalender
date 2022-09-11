#ifndef SQL_TERMIN_BEFEHLE_H
#define SQL_TERMIN_BEFEHLE_H

/*
 * Author: André Zimmer
 *
 */

#include <QtSql>
#include <QSqlDatabase>
#include <iostream>


class Termin{
 public:
    int idTermin;
    QString TerminName;
    QDate Datum;
    QTime Beginn;
    QTime Ende;
    QTime Erinnerung;
    bool Erledigung;
    int idNutzer_fk;

    Termin();
    bool TerminInsert(QSqlQuery Query, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung, int idNutzer_fk);
    bool CheckTerminID(QSqlQuery Query, int ID_Termin);
    int get_idTermin( QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk);
    bool LoescheTermin2(QSqlQuery Query,int ID_Termin);
    bool LoescheTermin1(QSqlQuery Query, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk);
    bool TerminUpdate(QSqlQuery Query,int idTermin, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung);

    bool TerminLaden(QSqlQuery,QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idTermin_fk);
    bool TerminCheckVorhanden(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idTermin_fk);
    bool TerminwertevonID(QSqlQuery Query, int ID);
};

//Konstruktor der Alle Werte auf 0 setzt
inline Termin::Termin(){
    this->TerminName = "0";
    this->idTermin =-1;
    this->Erledigung = false;
    this->idNutzer_fk =-1;
}

//Termin Einfügen
inline bool Termin::TerminInsert(QSqlQuery Query, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung, int idNutzer_fk){//Noch nicht Vollstängdig

   Query.prepare("INSERT INTO Termin(Terminname, Datum, Beginn, Ende, Beschreibung, Erinnerung,  Erledigung, idNutzer_fk)" "Values(:Terminname, :Datum, :Beginn, :Ende, :Beschreibung, :Erinnerung, :Erledigung, :idNutzer_fk)");
   Query.bindValue(":Terminname",TerminN);
   Query.bindValue(":Datum", Datum);
   Query.bindValue(":Beginn", Beginn);
   Query.bindValue(":Ende", Ende);
   Query.bindValue(":Beschreibung", Beschreibung);
   Query.bindValue(":Erinnerung",Erinnerung);
   Query.bindValue(":Erledigung", Erledigung);
   Query.bindValue(":idNutzer_fk", idNutzer_fk);

   if(!Query.exec()){
       throw std::runtime_error("Connection error");
   }
   else{
       return true;
   }

    }

//Check ob eine bestimmte idTermin vorhanden ist
inline bool Termin::CheckTerminID(QSqlQuery Query, int ID_Termin){
   Query.prepare("SELECT * FROM Termin WHERE idTermin=:idTermin");
   Query.bindValue(":idTermin", ID_Termin);
   if(!Query.exec()) {
           throw std::runtime_error("Connection error");
       }
       else {
           if(!Query.first()) {
               return false;
           }
           else {
               return true;
           }
       }
}


//Sucht die TerminID zu den Daten heraus
inline int Termin::get_idTermin(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk){

              QSqlQueryModel model;

       model.setQuery("SELECT  * FROM Termin");

       for (int i = 0; i < model.rowCount(); ++i) {// Geht alle Termine durch und sucht den Passenden
           int id = model.record(i).value("idTermin").toInt();
           QString name = model.record(i).value("Terminname").toString();
           QDate date =model.record(i).value("Datum").toDate();
           QTime beginn= model.record(i).value("Beginn").toTime();
           QTime ende= model.record(i).value("Ende").toTime();
           int idnutzer_fk =model.record(i).value("idNutzer_fk").toInt();

           if(name==TerminN&&Datum==date&&Beginn==beginn&&Ende==ende&&idNutzer_fk==idnutzer_fk){ //Vergleicht ob ein Termin mit den Werten übereinstimmt
               return id;
           }
}

return 0;
}

//LöschFunktion wo nur idTermin nötig ist
inline bool Termin::LoescheTermin2(QSqlQuery Query,int ID_Termin){

    if(CheckTerminID(Query,ID_Termin)){//Gibt es diesen Termin überhaupt?
    Query.prepare("DELETE FROM Termin WHERE idTermin =:idTermin");
    Query.bindValue(":idTermin",ID_Termin);
    if(!Query.exec()) {
                throw std::runtime_error("Connection error");
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
}

//Aufruf zum Löschen eines Termines
inline bool Termin::LoescheTermin1(QSqlQuery Query, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk){
    int i = get_idTermin(TerminN,Datum,Beginn, Ende, idNutzer_fk);
    if(i>0){
        LoescheTermin2(Query,i);
        return true;
    }
    else
        return false;
}


inline bool Termin::TerminUpdate(QSqlQuery Query,int idTermin, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung){


    if(/*CheckTerminID(Query,idTermin)*/true){
        Query.prepare("UPDATE Termin SET Terminname =:Terminname, Datum =:Datum, Beginn=:Beginn, Ende=:Ende, Beschreibung=:Beschreibung, Erinnerung=:Erinnerung, Erledigung=:Erledigung WHERE idTermin =:idTermin" );
        Query.bindValue(":Terminname",TerminN);
        Query.bindValue(":Datum", Datum);
        Query.bindValue(":Beginn", Beginn);
        Query.bindValue(":Ende", Ende);
        Query.bindValue(":Beschreibung", Beschreibung);
        Query.bindValue(":Erinnerung",Erinnerung);
        Query.bindValue(":Erledigung", Erledigung);
        Query.bindValue(":idTermin", idTermin);

           if(!Query.exec()) {
                    throw std::runtime_error("Connection error");
                }
                else {
                    return true;
                }
            }
            else {
                return false;
            }
}


inline bool Termin::TerminCheckVorhanden(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk){

    if(get_idTermin(TerminN,Datum,Beginn,Ende,idNutzer_fk)){
        return true; //Falls ein Termin vorhanden ist
    }
      return false;

}



//In die Prameter Laden
inline bool Termin::TerminLaden(QSqlQuery Query,QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idTermin_fk){
if(TerminCheckVorhanden(TerminN,Datum,Beginn,Ende,idNutzer_fk)){
    int i = get_idTermin(TerminN, Datum, Beginn, Ende, idTermin_fk);
    Query.prepare("SELECT * FROM Termin WHERE idTermin =: i");
    Query.bindValue(":i",i);

    if(!Query.exec()){
        throw "Connection error";
    }
    else {
        Query.first();
        this->idTermin=Query.value(0).toInt();
        this->TerminName=Query.value(1).toString();
        this->Datum=Query.value(2).toDate();
        this->Beginn=Query.value(3).toTime();
        this->Ende=Query.value(4).toTime();
        this->Erinnerung=Query.value(5).toTime();
        this->Erledigung=Query.value(6).toBool();
        this->idNutzer_fk=Query.value(7).toInt();
        return true;

    }
}

else{
    return false;
}

}

inline bool Termin::TerminwertevonID(QSqlQuery Query, int ID){

    Query.prepare("SELECT * FROM Termin WHERE idTermin =:i");
    Query.bindValue(":i",ID);

    if(!Query.exec()){
        throw "Connection error";
    }
    else {
        Query.first();
        this->idTermin=Query.value(0).toInt();
        this->TerminName=Query.value(1).toString();
        this->Datum=Query.value(2).toDate();
        this->Beginn=Query.value(3).toTime();
        this->Ende=Query.value(4).toTime();
        this->Erinnerung=Query.value(5).toTime();
        this->Erledigung=Query.value(6).toBool();
        this->idNutzer_fk=Query.value(7).toInt();
        return true;

    }
}








#endif // SQL_TERMIN_BEFEHLE_H
