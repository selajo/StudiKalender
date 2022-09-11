#include "Termin_Klasse.h"

//Konstruktor der Alle Werte auf 0 setzt
 Termin::Termin(){
    this->TerminName = "0";
    this->idTermin =-1;
    this->Erledigung = false;
    this->idNutzer_fk =-1;
}

//Termin Einfügen
 bool Termin::TerminInsert(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung,int Wiederholungen, bool TeilLernplan, int idNutzer_fk){//Noch nicht Vollstängdig
if(!get_idTermin(TerminN,Datum,Beginn,Ende,idNutzer_fk)){
   QSqlQuery Query;
   Query.prepare("INSERT INTO Termin(Terminname, Datum, Beginn, Ende, Beschreibung, Erinnerung,  Erledigung, Wiederholungen, TeilLernplan, idNutzer_fk)" "Values(:Terminname, :Datum, :Beginn, :Ende, :Beschreibung, :Erinnerung, :Erledigung, :Wiederholungen, :TeilLernplan, :idNutzer_fk)");
   Query.bindValue(":Terminname",TerminN);
   Query.bindValue(":Datum", Datum);
   Query.bindValue(":Beginn", Beginn);
   Query.bindValue(":Ende", Ende);
   Query.bindValue(":Beschreibung", Beschreibung);
   Query.bindValue(":Erinnerung",Erinnerung);
   Query.bindValue(":Erledigung", Erledigung);
   Query.bindValue(":Wiederholungen", Wiederholungen);
   Query.bindValue(":TeilLernplan",TeilLernplan);
   Query.bindValue(":idNutzer_fk", idNutzer_fk);

   if(!Query.exec()){
       throw "Connection error";

   }
   else{
       return true;
   }

    }
 else {
 return false;
}

 }

//Check ob eine bestimmte idTermin vorhanden ist
 bool Termin::CheckTerminID(int ID_Termin){
   QSqlQuery Query;
   Query.prepare("SELECT * FROM Termin WHERE idTermin=:idTermin");
   Query.bindValue(":idTermin", ID_Termin);
   if(!Query.exec()) {
           throw "Connection error";
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
 int Termin::get_idTermin(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk){

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
 bool Termin::LoescheTermin2(int ID_Termin){

     QSqlQuery Query;

    if(CheckTerminID(ID_Termin)){//Gibt es diesen Termin überhaupt?
    Query.prepare("DELETE FROM Termin WHERE idTermin =:idTermin");
    Query.bindValue(":idTermin",ID_Termin);
    if(!Query.exec()) {
                throw "Connection error";
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
bool Termin::LoescheTermin1(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk){
    QSqlQuery Query;

    int i = get_idTermin(TerminN,Datum,Beginn, Ende, idNutzer_fk);
    if(i>0){
        LoescheTermin2(i);
        return true;
    }
    else
        return false;
}


 bool Termin::TerminUpdate(int idTermin, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung, int Wiederholungen){

     QSqlQuery Query;

        Query.prepare("UPDATE Termin SET Terminname =:Terminname, Datum =:Datum, Beginn=:Beginn, Ende=:Ende, Beschreibung=:Beschreibung, Erinnerung=:Erinnerung, Erledigung=:Erledigung, Wiederholungen=:Wiederholungen WHERE idTermin =:idTermin" );
        Query.bindValue(":Terminname",TerminN);
        Query.bindValue(":Datum", Datum);
        Query.bindValue(":Beginn", Beginn);
        Query.bindValue(":Ende", Ende);
        Query.bindValue(":Beschreibung", Beschreibung);
        Query.bindValue(":Erinnerung",Erinnerung);
        Query.bindValue(":Erledigung", Erledigung);
        Query.bindValue(":Wiederholugen", Wiederholungen);
        Query.bindValue(":idTermin", idTermin);

           if(!Query.exec()) {
                    throw "Connection error";
               return false;
                }
                else {
                    return true;
                }


}


bool Termin::TerminCheckVorhanden(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk){

    if(get_idTermin(TerminN,Datum,Beginn,Ende,idNutzer_fk)){
        return true; //Falls ein Termin vorhanden ist
    }
      return false;

}



//In die Prameter Laden
 bool Termin::TerminLaden(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idTermin_fk){
    QSqlQuery Query;
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
        this->Erinnerung=Query.value(6).toTime();
        this->Erledigung=Query.value(7).toBool();
        this->Wiederholungen=Query.value(8).toInt();
        this->idNutzer_fk=Query.value(10).toInt();
        return true;

    }
}

else{
    return false;
}

}

 bool Termin::TerminwertevonID( int ID){
    QSqlQuery Query;
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
        this->Beschreibung=Query.value(5).toString();
        this->Erinnerung=Query.value(6).toTime();
        this->Erledigung=Query.value(7).toBool();
        this->Wiederholungen=Query.value(8).toInt();
        this->idNutzer_fk=Query.value(10).toInt();
        return true;

    }
}

 QVector<Termin> Termin::TermineHeuteMitErinnerungen (int idNutzer_fk){

     QVector<Termin> aktTermine;
     aktTermine.clear();

     QDate Datum; //Suche nur die Erinnerungen vom heutigen Datum
     Datum= Datum.currentDate();
     QTime jTime;
     jTime.setHMS(0,0,0); //DefaultWert

      QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery("SELECT  * FROM Termin "); //Durchsucht die Tabelle

      for (int i = 0; i < model->rowCount(); ++i) {// Geht alle Termine durch und sucht den Passenden

       int id = model->record(i).value("idTermin").toInt();
       QString name = model->record(i).value("Terminname").toString();
       QDate date =model->record(i).value("Datum").toDate();
       QTime rem= model->record(i).value("Erinnerung").toTime();
       QTime beginn= model->record(i).value("Beginn").toTime();
       QTime ende= model->record(i).value("Ende").toTime();
       int idnutzer_fk =model->record(i).value("idNutzer_fk").toInt();


        if(idNutzer_fk==idnutzer_fk&&Datum == date && rem !=jTime ){
            QSqlQuery query;

            Termin newTermin;

            newTermin.idTermin = id;
            newTermin.TerminName = name;
            newTermin.Erinnerung = rem;
            newTermin.Datum =date;
            newTermin.Beginn= beginn;
            newTermin.Ende = ende;

            aktTermine.prepend(newTermin); //Termin in den Vektor laden
          //qDebug()<< id << name << date <<beginn << ende;
        }
      }

      return  aktTermine;
 }

 bool Termin::Update_Erinnerung_NULL( int ID_Termin)
 {
     QTime T(0,0,0);
    QSqlQuery Query;
   // Datenbank *db = Datenbank::getInstance();
    //db->connOpen();

     Query.prepare("UPDATE Termin SET  Erinnerung =:Erinnerung WHERE idTermin =:idTermin" );
     Query.bindValue(":Erinnerung", T);
     Query.bindValue(":idTermin", ID_Termin);

        if(!Query.exec()) {
                 throw "Connection error";
           // db->connClose();
             }
             else {
          //  db->connClose();
                 return true;
             }
 }
