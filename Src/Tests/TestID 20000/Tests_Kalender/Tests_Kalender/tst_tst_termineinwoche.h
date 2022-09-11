#ifndef TST_TERMINEINWOCHE_H
#define TST_TERMINEINWOCHE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../../Code/StartseiteStudikalender/Lernplan.h>
#include <../../../../Code/StartseiteStudikalender/Lernplan.cpp>
#include <../../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>
#include <../../../../Code/StartseiteStudikalender/Studienfach_Klasse.h>
#include <../../../../Code/StartseiteStudikalender/Studienfach_Klasse.cpp>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.cpp>
#include <../../../../Code/StartseiteStudikalender/Kalender.h>
#include <../../../../Code/StartseiteStudikalender/Kalender.cpp>


//Author: Josef Lanzl

using namespace testing;

//TermineInWoche

TEST(test_20107, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();
        QSqlQuery query;

        //Nutzer LernplanTest1: hat in Woche 01.07.2019 bis 14.07.2019 keinen einzigen Termin
        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest1")) {
            p.ProfilInsert("LernplanTest1", "Lernen", "lern@mail.de", "l1", "l2");
        }

        p.ProfilLaden("LernplanTest1", "Lernen");

        Lernplan l;
        QDate Start, Ziel;
        Start.setDate(2019, 7, 1);
        Ziel.setDate(2019, 7, 14);
        Kalender k;
        k.TermineInWoche(Start, Ziel, p.idNutzer);


        bool ergebnis = true;

        QTime AchtUhr, ZehnUhr;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(22, 0, 0);

        for(auto i = l.Termine.begin(); i != l.Termine.end(); i++) {
            if(i->Datum == Start && i->Beginn == AchtUhr && i->Ende == AchtUhr) {
                i++;
            }
            else {
                ergebnis = false;
                break;
            }

            if(i->Datum == Start && i->Beginn == ZehnUhr && i->Ende == ZehnUhr) {
                Start = Start.addDays(1);
            }
            else {
                ergebnis = false;
                break;
            }
        }



        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20108, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Nutzer LernplanTest1: hat in 17.07.2019 bis 30.07.2019 keinen einzigen Termin; Am 16.07.2019 schon
        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest1")) {
            p.ProfilInsert("LernplanTest1", "Lernen", "lern@mail.de", "l1", "l2");
        }

        p.ProfilLaden("LernplanTest1", "Lernen");

        Termin t;
        Lernplan l;
        QDate Start, Ziel;
        Start.setDate(2019, 8, 16);
        Ziel.setDate(2019, 8, 30);
        QTime AchtUhr, ZehnUhr, Null;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(22, 0, 0);
        Null.setHMS(0, 0, 0);


        if(!t.TerminCheckVorhanden("Termin", Start, AchtUhr, ZehnUhr,p.idNutzer)) {
            t.TerminInsert("Termin", Start, AchtUhr, ZehnUhr, "Termin", Null, 1, 0, 0, p.idNutzer);
        }

        Kalender k;
        k.TermineInWoche(Start, Ziel, p.idNutzer);

        bool ergebnis = true;

        QDate Sechzehn = Start;

        for(auto i = l.Termine.begin(); i != l.Termine.end(); i++) {
            if(i->Datum == Start && i->Beginn == AchtUhr && i->Ende == AchtUhr) {
                i++;
            }
            else {
                ergebnis = false;
                break;
            }

            if(i->Datum == Sechzehn && i->Beginn == AchtUhr && i->Ende == ZehnUhr) {
                i++;
            }
            else if(i->Datum == Sechzehn && (i->Beginn != AchtUhr || i->Ende != ZehnUhr)) {
                ergebnis = false;
                break;
            }

            if(i->Datum == Start && i->Beginn == ZehnUhr && i->Ende == ZehnUhr) {
                Start = Start.addDays(1);
            }
            else {
                ergebnis = false;
                break;
            }
        }



        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20109, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Nutzer LernplanTest1: hat in 16.09.2019 bis 30.09.2019 keinen einzigen Termin; Am 21.09.2019 schon
        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest1")) {
            p.ProfilInsert("LernplanTest1", "Lernen", "lern@mail.de", "l1", "l2");
        }

        p.ProfilLaden("LernplanTest1", "Lernen");

        Termin t;
        Lernplan l;
        QDate Start, Ziel;
        Start.setDate(2019, 9, 16);
        Ziel.setDate(2019, 9, 30);
        QTime AchtUhr, ZehnUhr, Null;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(22, 0, 0);
        Null.setHMS(0, 0, 0);
        QDate Insert;
        Insert.setDate(2019, 9, 21);

        if(!t.TerminCheckVorhanden("Termin", Insert, AchtUhr, ZehnUhr,p.idNutzer)) {
            t.TerminInsert("Termin", Insert, AchtUhr, ZehnUhr, "Termin", Null, 1, 0, 0, p.idNutzer);
        }

        Kalender k;
        k.TermineInWoche(Start, Ziel, p.idNutzer);

        bool ergebnis = true;

        for(auto i = l.Termine.begin(); i != l.Termine.end(); i++) {
            if(i->Datum == Start && i->Beginn == AchtUhr && i->Ende == AchtUhr) {
                i++;
            }
            else {
                ergebnis = false;
                break;
            }

            if(i->Datum == Insert && i->Beginn == AchtUhr && i->Ende == ZehnUhr) {
                i++;
            }
            else if(i->Datum == Insert && (i->Beginn != AchtUhr || i->Ende != ZehnUhr)) {
                ergebnis = false;
                break;
            }

            if(i->Datum == Start && i->Beginn == ZehnUhr && i->Ende == ZehnUhr) {
                Start = Start.addDays(1);
            }
            else {
                ergebnis = false;
                break;
            }
        }



        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20110, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Nutzer LernplanTest1: hat in 16.10.2019 bis 30.10.2019 keinen einzigen Termin; Am 30.10.2019 schon
        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest1")) {
            p.ProfilInsert("LernplanTest1", "Lernen", "lern@mail.de", "l1", "l2");
        }

        p.ProfilLaden("LernplanTest1", "Lernen");

        Termin t;
        Lernplan l;
        QDate Start, Ziel;
        Start.setDate(2019, 10, 16);
        Ziel.setDate(2019, 10, 30);
        QTime AchtUhr, ZehnUhr, Null;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(22, 0, 0);
        Null.setHMS(0, 0, 0);
        QDate Insert;
        Insert.setDate(2019, 10, 30);

        if(!t.TerminCheckVorhanden("Termin", Insert, AchtUhr, ZehnUhr,p.idNutzer)) {
            t.TerminInsert("Termin", Insert, AchtUhr, ZehnUhr, "Termin", Null, 1, 0, 0, p.idNutzer);
        }

        Kalender k;
        k.TermineInWoche(Start, Ziel, p.idNutzer);

        bool ergebnis = true;

        for(auto i = l.Termine.begin(); i != l.Termine.end(); i++) {
            if(i->Datum == Start && i->Beginn == AchtUhr && i->Ende == AchtUhr) {
                i++;
            }
            else {
                ergebnis = false;
                break;
            }

            if(i->Datum == Insert && i->Beginn == AchtUhr && i->Ende == ZehnUhr) {
                i++;
            }
            else if(i->Datum == Insert && (i->Beginn != AchtUhr || i->Ende != ZehnUhr)) {
                ergebnis = false;
                break;
            }

            if(i->Datum == Start && i->Beginn == ZehnUhr && i->Ende == ZehnUhr) {
                Start = Start.addDays(1);
            }
            else {
                ergebnis = false;
                break;
            }
        }



        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_TERMINEINWOCHE_H
