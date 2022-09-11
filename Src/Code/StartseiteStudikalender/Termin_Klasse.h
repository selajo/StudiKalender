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
    int Wiederholungen;
    int idNutzer_fk;
    bool TeilLernplan;

    Termin();
    bool TerminInsert( QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung,int Wiederholungen, bool TeilLernplan, int idNutzer_fk);
    bool CheckTerminID( int ID_Termin);
    int get_idTermin( QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk);
    bool LoescheTermin2(int ID_Termin);
    bool LoescheTermin1( QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idNutzer_fk);
    bool TerminUpdate(int idTermin, QString TerminN, QDate Datum, QTime Beginn, QTime Ende, QString Beschreibung, QTime Erinnerung,  bool Erledigung, int Wiederholungen);

    bool TerminLaden(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idTermin_fk);
    bool TerminCheckVorhanden(QString TerminN, QDate Datum, QTime Beginn, QTime Ende, int idTermin_fk);
    bool TerminwertevonID( int ID);
    QVector<Termin> TermineHeuteMitErinnerungen (int idNutzer_fk);
    bool Update_Erinnerung_NULL( int ID_Termin);
};






#endif // SQL_TERMIN_BEFEHLE_H
