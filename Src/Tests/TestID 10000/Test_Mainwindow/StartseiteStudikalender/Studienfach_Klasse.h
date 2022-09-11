#ifndef STUDIENFACH_FUNKTIONEN_H
#define STUDIENFACH_FUNKTIONEN_H

/*
 *
 * Author: André Zimmer
 *
 */


#include <QtSql>
#include <QSqlDatabase>
#include <iostream>

class Studienfach{
public:
    int _idStudienfach;
    QString _Bezeichnung;
    int _ECTS;
    int _SWS;
    int _Eigenstunden;
    int _idNutzer_FK;

    Studienfach();
    bool insert_Studienfach( QString Name, int ECTS, int SWS, int Eigenstunden, int idNutzer_fk);
    int get_idStudienfach(QString Name, int idNutzer_fk);
    bool StudienfachLaden( QString Name, int idNutzer_fk);
    bool UpdateStudienfach(int idStudienfach, QString Name, int ECTS, int SWS, int Eigenstunden);
    bool DeleteStudienfach( int idStudienfach);
    bool StudienfachwertevonID( int ID);
};


#endif // STUDIENFACH_FUNKTIONEN_H
