#ifndef LERNPLAN_H
#define LERNPLAN_H

#include "mainwindow.h"
#include "Termin_Klasse.h"
#include "Datenbank.h"
#include "Studienfach_Klasse.h"


//Author: Josef Lanzl

class Lernplan {
public:
    QDate EndDatum;
    QVector<Termin> Termine;
    QVector<Studienfach> Studienfaecher;
    QDate AktuelleWoche;

    Lernplan();
    ~Lernplan();
    void TermineInWoche(QSqlQuery Query, QDate DatumWochenBeginn,QDate DatumWochenEnde, int idNutzer);
    void StudienfachVonNutzer(QSqlQuery Query, int idNutzer_fk);
    bool checkEndDatum();
    bool checkStunden(QSqlQuery Query, QDate start, QDate ende, int idNutzer);
    int RechneStunden(QSqlQuery Query, QDate start, QDate ende, int idNutzer);
    void SetZeroSeconds();
    void prepareTermine();

    bool CheckLernplan(QSqlQuery Query, int idNutzer);

    void LernplanLoeschen(QSqlQuery Query, int idNutzer);
    bool LernplanErstellenStart(QSqlQuery Query, int idNutzer);
    bool LernplanErstellenWoche(QSqlQuery Query, QDate DatumWochenBeginn, QDate DatumWochenEnde, int idNutzer);
    void LernplanErstellenTag(QSqlQuery, QDate Datum, int idNutzer);

};



#endif // LERNPLAN_H
