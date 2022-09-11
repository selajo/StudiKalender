#ifndef KALENDER_H
#define KALENDER_H

#include "mainwindow.h"
#include "Termin_Klasse.h"
#include "Studienfach_Klasse.h"



class Kalender {
public:
    //Alles für Lernplan
    //Author: Josef Lanzl
    QVector<Termin> Termine;
    QVector<Studienfach> Studienfaecher;

    QTime ZehnUhr;
    QTime AchtUhr;

    void TermineInWoche(QDate DatumWochenBeginn,QDate DatumWochenEnde, int idNutzer);
    void StudienfachVonNutzer(int idNutzer);
    bool CheckLernplan(int idNutzer);
    void setObereGrenze(Termin *t);
    void setUntereGrenze(Termin *t);


    //Alles für Termine
    //Author::André Zimmer
    QList<int> BLidTermin;
    QList<QString> BLTerminname;
    QList<QDate> BLDatum;
    QList<QTime> BLBeginn;
    QList<QTime> BLEnde;
    QList<QString>BLBeschreibung;

    void getTermin(QDate Datum);
};


#endif // KALENDER_H
