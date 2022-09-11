#include "Nutzerprofil.h"

//Author: Josef Lanzl

NProfil::NProfil() {
    //Profil wird mit 'ungültigen' Werten gefüllt

    this->Email = "";
    this->Passwort = "";
    this->idNutzer = -1;
    this->Nutzername = "";
}




NProfil::~NProfil() {
    //Profil wird wieder mit 'ungültigen' Werten gefüllt

    this->idNutzer = -1;
    this->Email = "";
    this->Nutzername = "";
    this->Passwort = "";
}


bool NProfil::ProfilCheckEmail(QString EMail) {
    QSqlQuery Query;

    Query.prepare("SELECT * FROM Profil "
                  "WHERE EMail = :EMail");
    Query.bindValue(":EMail", EMail);

    if(!Query.exec()) {
        throw "Connection error";
    }
    else {
        if(!Query.first()) {
            //Email gibt es noch nicht im System
            return false;
        }
        else {
            //Email gibt es schon im System
            return true;
        }
    }
}


bool NProfil::ProfilCheckNutzername(QString NutzerN) {
    QSqlQuery Query;

    Query.prepare("SELECT * FROM Profil "
                  "WHERE Nutzername = :NutzerN");
    Query.bindValue(":NutzerN", NutzerN);

    if(!Query.exec()) {
        throw "Connection Error";
    }
    else {
        if(!Query.first()) {
            //Nutzename ist noch nicht im System vorhanden
            return false;
        }
        else {
            //Nutzername schon im System vorhanden
            return true;
        }
    }
}



bool NProfil::ProfilCheckPasswort(QString NutzerN, QString Passw) {
    QSqlQuery Query;

    Query.prepare("SELECT * FROM Profil "
                  "WHERE Nutzername = :NutzerN AND Passwort = :Passw");
    Query.bindValue(":NutzerN", NutzerN);
    Query.bindValue(":Passw", Passw);

    if(!Query.exec()) {
        throw "Connection error";
    }
    else {
        if(!Query.first()) {
            //Nutzername und Passwort stimmen im System nicht überein
            return false;
        }
        else {
            //Nutzername und Passwort stimmen im System überein
            return true;
        }
    }
}

bool NProfil::ProfilCheckVorhanden(QString NutzerN, QString EMail) {
    if(ProfilCheckEmail(EMail) || ProfilCheckNutzername(NutzerN)) {
        //Email oder Nutzername schon im System vorhanden
        return true;
    }
    else {
        //Email und Nutzername noch nicht im System vorhanden
        return false;
    }
}


bool NProfil::ProfilUpdatePasswort(QString NutzerN, QString Passw, QString NewPassw) {
    if(ProfilCheckPasswort(NutzerN, Passw)) {
        QSqlQuery Query;

        Query.prepare("UPDATE Profil SET Passwort = :NewPassw WHERE Nutzername = :NutzerN");
        Query.bindValue(":NewPassw", NewPassw);
        Query.bindValue(":NutzerN", NutzerN);

        if(!Query.exec()) {
            throw Query.lastError().text().toStdString();
        }
        else {
            //Passwort erfolgreich geändert
            return true;
        }
    }
    else {
        //Nutzername und Passwort stimmen nicht überein
        //Passwort unverändert
        return false;
    }
}

bool NProfil::ProfilLoeschen(QString Passw, QString F1, QString F2) {
    QSqlQuery Query;

    Query.prepare("SELECT * FROM Profil WHERE Nutzername = :NutzerN AND Passwort = :Passw AND EMail = :Email AND Sicherheitsfrage1 = :F1 AND Sicherheitsfrage2 = :F2");
    Query.bindValue(":NutzerN", this->Nutzername);
    Query.bindValue(":Email", this->Email);
    Query.bindValue(":Passw", Passw);
    Query.bindValue(":F1", F1);
    Query.bindValue(":F2", F2);

    if(!Query.exec()) {
        throw "Connection error";
    }
    else {

        if(Query.first()) {

            Query.prepare("DELETE FROM Profil WHERE Nutzername = :NutzerN AND EMail = :Email");
            Query.bindValue(":NutzerN", this->Nutzername);
            Query.bindValue(":Email", this->Email);

            if(!Query.exec()) {
                throw "Connection error";
            }
            else {
                //Nutzer erfolgreich gelöscht
                return true;
            }
        }
        else {
            //Authetifizierungsdaten stimmen nicht mit Nutzername überein
            return false;
        }
    }
}

bool NProfil::ProfilInsert(QString NutzerN, QString Passw, QString EMail, QString SichF1, QString SichF2) {
    if(!ProfilCheckVorhanden(NutzerN, EMail)) {
        QSqlQuery Query;

        Query.prepare("INSERT INTO Profil (Nutzername, Passwort, EMail, Sicherheitsfrage1, Sicherheitsfrage2)"
                      "Values (:Nutzername, :Passwort, :EMail, :Sicherheitsfrage1, :Sicherheitsfrage2)");
        Query.bindValue(":Nutzername", NutzerN);
        Query.bindValue(":Passwort", Passw);
        Query.bindValue(":EMail", EMail);
        Query.bindValue(":Sicherheitsfrage1", SichF1);
        Query.bindValue(":Sicherheitsfrage2", SichF2);

        if(!Query.exec()) {
            throw "Connection error";
        }
        else {
            //Profil erfolgreich hinzugefügt
            return true;
        }
    }
    else {
        //Nutzername oder Email schon im System vorhanden
        return false;
    }
}

bool NProfil::ProfilLaden(QString NutzerN, QString Passw) {
    QSqlQuery Query;

    if(ProfilCheckPasswort(NutzerN, Passw)) {
        Query.prepare("SELECT idNutzer, Nutzername, EMail, Passwort FROM Profil WHERE Nutzername = :NutzerN");
        Query.bindValue(":NutzerN", NutzerN);

        if(!Query.exec()) {
            throw "Connection error";
        }
        else {
            Query.first();
            this->idNutzer = Query.value(0).toInt();
            this->Email = Query.value(2).toString();
            this->Passwort = Query.value(3).toString();
            this->Nutzername = Query.value(1).toString();

            //Profildaten erfolgreich den Attributen zugeschrieben
            return true;
        }
    }
    else {
        //Nutzername und Passwort stimmen nicht im System überein
        return false;
    }
}

bool NProfil::ProfilPasswortVergessen(QString NutzerN, QString Email, QString F1, QString F2, QString NewPassw) {
    QSqlQuery Query;

    Query.prepare("SELECT * FROM Profil WHERE Nutzername = :NutzerN AND EMail = :Email AND Sicherheitsfrage1 = :F1 AND Sicherheitsfrage2 = :F2");
    Query.bindValue(":NutzerN", NutzerN);
    Query.bindValue(":Email", Email);
    Query.bindValue(":F1", F1);
    Query.bindValue(":F2", F2);

    if(!Query.exec()) {
        throw "Connection error";
    }
    else {
        if(!Query.first()) {
            //Kein Nutzer mit eingegebenen Daten
            return false;
        }
        else {
            Query.prepare("UPDATE Profil SET Passwort = :NewPassw WHERE Nutzername = :NutzerN AND EMail = :Email AND Sicherheitsfrage1 = :F1 AND Sicherheitsfrage2 = :F2");
            Query.bindValue(":NewPassw", NewPassw);
            Query.bindValue(":NutzerN", NutzerN);
            Query.bindValue(":Email", Email);
            Query.bindValue(":F1", F1);
            Query.bindValue(":F2", F2);

            if(!Query.exec()) {
                throw "Connection error";
            }
            else {
                //Passwort erfolgreich verändert
                return true;
            }
        }
    }
}



void NProfil::ProfilUploadImage(QString NutzerN, QString url) {
    QSqlQuery Query;

    QByteArray bytes;
    QFile file(url);
    if(file.open(QIODevice::ReadOnly)) {
        bytes = file.readAll();
        file.close();
    }
    else {
        throw "File error";
    }

    Query.prepare("UPDATE Profil SET Image = :img WHERE Nutzername = :NutzerN");
    Query.bindValue(":img", bytes, QSql::In | QSql::Binary);
    Query.bindValue(":NutzerN", NutzerN);
    if(!Query.exec()) {
        throw "Connection error";
    }
}

bool NProfil::ProfilChangeEmail(QString NewEmail) {
    //Funktion darf nur aufgerufen werden, wenn Nutzer angemeldet
    QSqlQuery Query;

    if(!ProfilCheckEmail(NewEmail)) {
        Query.prepare("UPDATE Profil SET EMail = :NewEmail WHERE Nutzername = :NutzerN");
        Query.bindValue(":NutzerN", this->Nutzername);
        Query.bindValue(":NewEmail", NewEmail);


        if(!Query.exec()) {
            throw "Connection error";
        }
        else {
            //Erfolgreich Email geändert
            return true;
        }
    }
    else {
        //Es existiert schon ein Nutzer mit neu gewählten Email
        return false;
    }
}

QString NProfil::ProfilNutzernameVergessen(QString Email, QString F1, QString F2) {
    QSqlQuery Query;
    Query.prepare("SELECT Nutzername FROM Profil WHERE EMail = :Email AND Sicherheitsfrage1 = :F1 AND Sicherheitsfrage2 = :F2");
    Query.bindValue(":Email", Email);
    Query.bindValue(":F1", F1);
    Query.bindValue(":F2", F2);

    if(!Query.exec()) {
        throw "Connection error";
    }
    else {
        if(!Query.first()) {
            //Eingabekombination nicht im System vorhanden
            return "";
        }
        else {
            //Gib Nutzername, zur Ausgabe am Bildschirm, zurück
            return Query.value(0).toString();
        }
    }
}

QPixmap NProfil::ProfilGetImage() {
    QSqlQuery Query;
    Query.prepare("SELECT Image FROM Profil WHERE idNutzer = :NutzerN");
    Query.bindValue(":NutzerN", this->idNutzer);
    if(!Query.exec()) {
        throw "Connection error";
    }
    else {
        Query.first();
        QByteArray bytes = Query.value(0).toByteArray();
        QPixmap p;
        p.loadFromData(bytes, "JPG");
        return p;
    }
}

NProfil * NProfil::instance = 0;

NProfil * NProfil::getInstance(){
    if (instance == 0)
    {
        instance = new NProfil();
    }

    return instance;
}

