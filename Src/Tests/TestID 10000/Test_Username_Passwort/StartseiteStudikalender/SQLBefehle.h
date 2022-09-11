#ifndef SQLBEFEHLE_H
#define SQLBEFEHLE_H

//Kommandos für Profil-Datenbank
/*
 * Author: Josef Lanzl
 *
 */

#include <QtSql>
#include <QSqlDatabase>

//Für Testzwecke
inline std::string CreateProfil(QSqlQuery Query) {
    try {
        Query.prepare("CREATE TABLE Profil("
                   "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "Nutzername varchar(15) NOT NULL,"
                   "Passwort varchar(15) NOT NULL,"
                   "EMail varchar(20) NOT NULL,"
                   "Sicherheitsfrage1 varchar(15) NOT NULL,"
                   "Sicherheitsfrage2 varchar(15) NOT NULL"
                   ");");
        if(!Query.exec()) {
            return "Connection error";
        }
        else {
            return "Erfolg";
        }
    }
    catch(std::exception &e) {
        return e.what();
    }
}


//Für Testzwecke
inline std::string DropProfil(QSqlQuery Query) {
    try {
        Query.exec("DROP TABLE Profil");
        return "success";
    }
    catch(const std::exception& e) {
        return e.what();
    }
}


/*
bool ProfilInsert2(QSqlQuery Query, QString NutzerN, QString Passw, QString EMail, QString SichF1, QString SichF2) {
    try {
        Query.prepare("INSERT INTO Profil (Nutzername, Passwort, EMail, Sicherheitsfrage1, Sicherheitsfrage2)"
                      "Values (:Nutzername, :Passwort, :EMail, :Sicherheitsfrage1, :Sicherheitsfrage2)");
        Query.bindValue(":Nutzername", NutzerN);
        Query.bindValue(":Passwort", Passw);
        Query.bindValue(":EMail", EMail);
        Query.bindValue(":Sicherheitsfrage1", SichF1);
        Query.bindValue(":Sicherheitsfrage2", SichF2);
        if(!Query.exec()) {
            throw std::exception();
        }

        return true;
    }
    catch(char const &e) {
        return false;
    }
}
*/


/*
std::string ProfilSelect(QSqlQuery Query, QString NutzerN) {
    try {
        Query.prepare("SELECT * FROM Profil WHERE Nutzername = :NutzerN");
        Query.bindValue(":NutzerN", NutzerN);
        if(!Query.exec()) {
            qDebug() << Query.lastError().text();
            return "Selection Error";
        }
        else {
            if(!Query.first()) {
                return "missing";
            }
            else {
                qDebug() << "found: " << endl;
                while (Query.next())
                {
                    qDebug() << Query.value("ID").toInt() << Query.value("Nutzername").toString() << Query.value("Passwort").toString() << Query.value("EMail").toString() << Query.value("Sicherheitsfrage1").toString() << Query.value("Sicherheitsfrage2").toString();
                }
            return "success";
            }
        }
    }
    catch(const std::exception& e) {
        return e.what();
    }
}

*/

//Checken ob Nutzername vorhanden, falls ja true
inline bool ProfilCheckNutzerName(QSqlQuery Query, QString NutzerN) {
    Query.prepare("SELECT * FROM Profil "
                  "WHERE Nutzername = :NutzerN");
    Query.bindValue(":NutzerN", NutzerN);


    if(!Query.exec()) {
        throw std::runtime_error("Connection Error");
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

//Checken ob Email schon vorhanden
inline bool ProfilCheckEMail(QSqlQuery Query, QString EMail) {
    Query.prepare("SELECT * FROM Profil "
                  "WHERE EMail = :EMail");
    Query.bindValue(":EMail", EMail);

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


//Passen Nutzername und Passwort zusammen
inline bool ProfilCheckPasswort(QSqlQuery Query, QString NutzerN, QString Passw) {

    Query.prepare("SELECT * FROM Profil "
                  "WHERE Nutzername = :NutzerN AND Passwort = :Passw");
    Query.bindValue(":NutzerN", NutzerN);
    Query.bindValue(":Passw", Passw);

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

//Check ob Email oder Nutzer vorhanden
inline bool ProfilCheckVorhanden(QSqlQuery Query, QString NutzerN, QString EMail) {
    if(ProfilCheckEMail(Query, EMail) || ProfilCheckNutzerName(Query, NutzerN)) {
        return true;
    }
    else {
        return false;
    }
}

//Passwort ändern
inline bool ProfilUpdatePasswort(QSqlQuery Query, QString NutzerN, QString Passw, QString NewPassw) {
    if(ProfilCheckPasswort(Query, NutzerN, Passw)) {

        Query.prepare("UPDATE Profil"
                      "SET Passwort = :NewPassw"
                      "WHERE Nutzername =: NutzerN");
        Query.bindValue(":NewPassw", NewPassw);
        Query.bindValue(":NutzerN", NutzerN);

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



inline bool ProfilLoeschen(QSqlQuery Query, QString NutzerN, QString Passw) {
    if(ProfilCheckPasswort(Query, NutzerN, Passw)) {

        Query.prepare("DELETE FROM Profil"
                      "WHERE Nutzername = :NutzerN");
        Query.bindValue(":NutzerN", NutzerN);

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


//Profil zu Datenbank hinzufügen
inline bool ProfilInsert(QSqlQuery Query, QString NutzerN, QString Passw, QString EMail, QString SichF1, QString SichF2) {
    if(!ProfilCheckVorhanden(Query, NutzerN, EMail)) {

        Query.prepare("INSERT INTO Profil (Nutzername, Passwort, EMail, Sicherheitsfrage1, Sicherheitsfrage2)"
                      "Values (:Nutzername, :Passwort, :EMail, :Sicherheitsfrage1, :Sicherheitsfrage2)");
        Query.bindValue(":Nutzername", NutzerN);
        Query.bindValue(":Passwort", Passw);
        Query.bindValue(":EMail", EMail);
        Query.bindValue(":Sicherheitsfrage1", SichF1);
        Query.bindValue(":Sicherheitsfrage2", SichF2);

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


#endif // SQLBEFEHLE_H
