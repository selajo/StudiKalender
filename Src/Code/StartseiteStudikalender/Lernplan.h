#ifndef LERNPLAN_H
#define LERNPLAN_H

#include "mainwindow.h"
#include "Termin_Klasse.h"
#include "Datenbank.h"
#include "Studienfach_Klasse.h"
#include "Kalender.h"


//Author: Josef Lanzl

class Lernplan {
public:
    QDate EndDatum;

    QVector<Termin> Termine;
    QVector<Studienfach> Studienfaecher;

    QDate AktuelleWoche;

    Lernplan();
    ~Lernplan();

    bool checkEndDatum();
    bool checkStunden(QDate start, QDate ende, int idNutzer);
    int RechneStunden(QDate start, QDate ende, int idNutzer);
    void SetZeroSeconds();
    void prepareTermine();

    void LernplanLoeschen(int idNutzer);
    bool LernplanErstellenStart(int idNutzer);
    bool LernplanErstellenWoche(QDate DatumWochenBeginn, QDate DatumWochenEnde, int idNutzer);
    void LernplanErstellenTag(QDate Datum, int idNutzer);

};



#endif // LERNPLAN_H
