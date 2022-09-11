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
    QString Beschreibung;
    QTime Erinnerung;
    bool Erledigung;
    int idNutzer_fk;
    bool TeilLernplan;

    Termin();
    bool TerminInsert(QSqlQuery Query, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung, bool TeilLernplan, int idNutzer_fk);
    bool CheckTerminID(QSqlQuery Query, int ID_Termin);
    int get_idTermin( QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk);
    bool LoescheTermin2(QSqlQuery Query,int ID_Termin);
    bool LoescheTermin1(QSqlQuery Query, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk);
    bool TerminUpdate(QSqlQuery Query,int idTermin, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung);

    bool TerminLaden(QSqlQuery,QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idTermin_fk);
    bool TerminCheckVorhanden(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idTermin_fk);
    bool TerminwertevonID(QSqlQuery Query, int ID);
};






#endif // SQL_TERMIN_BEFEHLE_H
