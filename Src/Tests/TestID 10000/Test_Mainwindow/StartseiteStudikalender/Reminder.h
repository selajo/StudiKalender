#ifndef REMINDER_H
#define REMINDER_H

//Author: Josef Lanzl
#include "mainwindow.h"


class Reminder {
public:
    int idReminder;
    QTime Zeit;
    QDate Datum;
    int idTermin_fk;
    QString TerminName;

    std::vector<Reminder> GetReminder(QSqlQuery Query, QDate Datum);
    Reminder();
    ~Reminder();

    bool ReminderErstellen(QSqlQuery Query, int TerminID, QTime Zeit, QDate Datum);
    bool ReminderLoeschen(QSqlQuery Query, int TerminID);
    bool ReminderUpdate(QSqlQuery Query, int TerminID, QTime Zeit, QDate Datum);
    bool ReminderLaden(QSqlQuery Query, int ReminderID);
    int getReminderID(QSqlQuery Query, int TerminID);

    //Gibt es zum Termin einen Reminder?
    bool ReminderCheck(QSqlQuery Query, int TerminID);

};


/* Idee:
 *  GetReminder: Ladet alle Reminder von Datum in einen vector
 *
 *  Reminder Konstruktor: Füllt Parameter mit ungültgen Werten
 *
 */


inline Reminder::Reminder() {
    this->idReminder = -1;
    this->Zeit.setHMS(-1, -1, -1);
    this->Datum.setDate(-1, -1, -1);
    this->idTermin_fk = -1;
    this->TerminName = "";
}

inline Reminder::~Reminder() {

}

inline bool Reminder::ReminderCheck(QSqlQuery Query, int TerminID) {
    //Prüfe ob schon Reminder zu Termin vorhanden
    Query.prepare("SELECT idReminder FROM reminder WHERE idTermin_fk = :TerminID");
    Query.bindValue(":TerminID", TerminID);
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

inline bool Reminder::ReminderErstellen(QSqlQuery Query, int TerminID, QTime Zeit, QDate Datum) {
    if(!ReminderCheck(Query, TerminID)) {
        Query.prepare("INSERT INTO reminder (Zeit, Datum, idTermin_fk) "
                      "VALUES (:Zeit, :Datum, :TerminID)");
        Query.bindValue(":Zeit", Zeit);
        Query.bindValue(":Datum", Datum);
        Query.bindValue(":TerminID", TerminID);
        if(!Query.exec()) {
            qDebug() << Query.lastError().text();
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

inline bool Reminder::ReminderLoeschen(QSqlQuery Query, int TerminID) {
    if(ReminderCheck(Query, TerminID)) {
        Query.prepare("DELETE FROM reminder WHERE idTermin_fk = :TerminID");
        Query.bindValue(":TerminID", TerminID);
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

inline bool Reminder::ReminderUpdate(QSqlQuery Query, int TerminID, QTime Zeit, QDate Datum) {
    if(ReminderCheck(Query, TerminID)) {
        Query.prepare("UPDATE reminder SET Zeit = :Zeit, Datum = :Datum WHERE idTermin_fk = :TerminID");
        Query.bindValue(":Zeit", Zeit);
        Query.bindValue(":Datum", Datum);
        Query.bindValue(":TerminID", TerminID);

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

inline int Reminder::getReminderID(QSqlQuery Query, int TerminID) {
    Query.prepare("SELECT idReminder FROM reminder WHERE idTermin_fk = :TerminID");
    Query.bindValue(":TerminID", TerminID);
    if(!Query.exec()) {
        throw "Connection error";
    }
    else {
        if(!Query.first()) {
            return -1;
        }
        else {
            return Query.value(0).toInt();
        }
    }
}

inline bool Reminder::ReminderLaden(QSqlQuery Query, int TerminID) {
    Query.prepare("SELECT idReminder, Zeit, TerminName FROM reminder r, termin t WHERE idTermin_fk = :TerminID");
    Query.bindValue(":TerminID", TerminID);
    if(!Query.exec()) {
        qDebug() << Query.lastError().text();
        throw "Connection error";
    }
    else {
        if(!Query.first()) {

            return false;
        }
        else {
            this->Zeit = Query.value(1).toTime();
            this->idReminder = Query.value(0).toInt();
            this->idTermin_fk = TerminID;
            this->TerminName = Query.value(2).toString();

            qDebug() << this->TerminName << this->Zeit << this->idReminder;
            return true;
        }
    }
}

inline std::vector<Reminder> Reminder::GetReminder(QSqlQuery Query, QDate Datum) {
    std::vector<Reminder> r;
    Reminder remind;

    Query.prepare("SELECT Zeit, TerminName FROM reminder r, termin t WHERE r.Datum = :date AND t.Datum = :date2");
    Query.bindValue(":date", Datum);
    Query.bindValue(":date2", Datum);
    //Query.bindValue(":NutzerID", NutzerID);

    if(!Query.exec()) {
        qDebug() << Query.lastError().text();
        throw "Connection error";
    }
    else {
        if(!Query.first()) {
            return r;
        }
        else {
            remind.TerminName = Query.value(1).toString();
            remind.Zeit = Query.value(0).toTime();
            r.push_back(remind);

            while(Query.next()) {
                remind.TerminName = Query.value(1).toString();
                remind.Zeit = Query.value(0).toTime();
                r.push_back(remind);
            }
            return r;

        }
    }
}


#endif // REMINDER_H
