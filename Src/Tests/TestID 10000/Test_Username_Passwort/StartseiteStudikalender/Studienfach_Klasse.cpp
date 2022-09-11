#include "Studienfach_Klasse.h"

//LöschFunktion
 bool Studienfach::DeleteStudienfach(QSqlQuery Query, int idStudienfach){

    Query.prepare("DELETE FROM Studienfach WHERE idStudienfach = :idStudienfach");
            Query.bindValue(":idStudienfach", idStudienfach);

            if(!Query.exec()) {
                throw "Connection error";
            }
            else {
                return true;
            }
}

//UpdateFunktion
bool Studienfach::UpdateStudienfach(QSqlQuery Query,int idStudienfach, QString Name, int ECTS, int SWS, int Eigenstunden){
    Query.prepare("UPDATE studienfach SET Bezeichnung =:Name, ECTS =:ECTS, SWS=:SWS, Eigenstunden=:Eigenstunden WHERE idStudienfach =:idStudienfach" );
    Query.bindValue(":Name",Name);
    Query.bindValue(":ECTS", ECTS);
    Query.bindValue(":SWS", SWS);
    Query.bindValue(":Eigenstunden", Eigenstunden);
    Query.bindValue(":idStudienfach", idStudienfach);

    if(!Query.exec()) {
             throw std::runtime_error("Connection error");
         }
         else {
             return true;
         }
}

//Studienfachwerte in die Attribute laden
 bool Studienfach::StudienfachLaden(QSqlQuery Query, QString Name, int idNutzer_fk){
    int StudienfachiD = get_idStudienfach(Name,idNutzer_fk);
    if(StudienfachiD>0){
        Query.prepare("Select idStudienfach, Bezeichnung, ECTS,SWS,Eigenstunden, idNutzer_FK WHERE idStudienfach =:StudienfachID");
        Query.bindValue(":StudienfachID",StudienfachiD);
        if(!Query.exec()) {
                   throw "Connection error";
               }
        else {
            Query.first();
            this->_idStudienfach=Query.value(0).toInt();
            this->_Bezeichnung=Query.value(1).toString();
            this->_ECTS=Query.value(2).toInt();
            this->_SWS=Query.value(3).toInt();
            this->_Eigenstunden=Query.value(4).toInt();
            this->_idNutzer_FK=Query.value(5).toInt();

            return true;

        }

    }
    else{
        return false;
    }
}


//Funktion zum ermitterln des idStudienfach
 int Studienfach::get_idStudienfach(QString Name, int idNutzer_fk){

    QSqlQueryModel model;
    model.setQuery("SELECT  * FROM studienfach");

    for (int i = 0; i < model.rowCount(); ++i) {// Geht alle Termine durch und sucht den Passenden
        int id = model.record(i).value("idStudienfach").toInt();
        QString name = model.record(i).value("Bezeichnung").toString();
        //int ects =model.record(i).value("ECTS").toInt();
        //int sws= model.record(i).value("SWS").toInt();
       // int eigenstunden= model.record(i).value("Eigenstunden").toInt();
        int idnutzer_fk =model.record(i).value("idNutzer_fk").toInt();

        if(name==Name&&idNutzer_fk==idnutzer_fk){ //Vergleicht ob ein Termin mit den Werten übereinstimmt
            return id;
        }
}

return 0;
}

//Konstruktor der alles auf einen ungültigen Wert setzt
Studienfach::Studienfach(){
    this->_idStudienfach = -1;
    this->_Bezeichnung =" ";
    this->_ECTS=-1;
    this->_SWS=-1;
    this->_Eigenstunden=-1;
    this->_idNutzer_FK=-1;
}

//Funktion zum Einfügen eines Studienfaches
bool Studienfach::insert_Studienfach(QSqlQuery Query, QString Name, int ECTS, int SWS, int Eigenstunden, int idNutzer_fk){

Query.prepare("INSERT INTO studienfach (Bezeichnung, ECTS, SWS, Eigenstunden, idNutzer_FK)" " Values (:Name, :ECTS, :SWS, :Eigenstunden, :idNutzer_fk)");
Query.bindValue(":Name",Name);
Query.bindValue(":ECTS",ECTS);
Query.bindValue(":SWS", SWS);
Query.bindValue(":Eigenstunden",Eigenstunden);
Query.bindValue(":idNutzer_fk",idNutzer_fk);

if(!Query.exec()){
    throw std::runtime_error("Connection error");
}
else{
    return true;
}

}

//Liefert Werte von Studienfach
 bool Studienfach::StudienfachwertevonID(QSqlQuery Query, int ID){

    Query.prepare("SELECT * FROM studienfach WHERE idStudienfach =:i");
    Query.bindValue(":i",ID);

    if(!Query.exec()){
        throw "Connection error";
    }
    else {
        Query.first();
        this->_idStudienfach=Query.value(0).toInt();
        this->_Bezeichnung=Query.value(1).toString();
        this->_ECTS=Query.value(2).toInt();
        this->_SWS=Query.value(3).toInt();
        this->_Eigenstunden=Query.value(4).toInt();
        this->_idNutzer_FK = Query.value(5).toInt();

        return true;

    }
}
