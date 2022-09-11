#ifndef TST_CHECKLERNPLAN_H
#define TST_CHECKLERNPLAN_H

#include <tst_tst_termineinwoche.h>

//Author: Josef Lanzl

using namespace testing;

//CheckLernplan

TEST(test_20101, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Erstml muss ein Lernplan schon existieren
        Termin t;
        QTime AchtUhr, ZehnUhr;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(22, 0, 0);
        QTime Null;
        Null.setHMS(0, 0, 0);

        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest2")) {
            p.ProfilInsert("LernplanTest2", "Lernen", "lern2@mail.de", "l1", "l2");
        }
        p.ProfilLaden("LernplanTest2", "Lernen");

        t.TerminInsert("Lernen Test", QDate::currentDate().addDays(1), AchtUhr, ZehnUhr, "Lernplan Test", Null, 1, 0, 1, p.idNutzer);


        Lernplan l;
        Kalender k;
        bool ergebnis = k.CheckLernplan(p.idNutzer);

        ASSERT_THAT(ergebnis, true);

        l.LernplanLoeschen(p.idNutzer);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20102, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest2")) {
            p.ProfilInsert("LernplanTest2", "Lernen", "lern2@mail.de", "l1", "l2");
        }
        p.ProfilLaden("LernplanTest2", "Lernen");



        Kalender k;

        ASSERT_THAT(k.CheckLernplan(p.idNutzer), false);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20103, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Erstml muss ein Lernplan schon existieren
        Termin t;
        QTime AchtUhr, ZehnUhr;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(22, 0, 0);
        QTime Null;
        Null.setHMS(0, 0, 0);

        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest2")) {
            p.ProfilInsert("LernplanTest2", "Lernen", "lern2@mail.de", "l1", "l2");
        }
        p.ProfilLaden("LernplanTest2", "Lernen");


        t.TerminInsert("Test", QDate::currentDate(), AchtUhr, ZehnUhr, "Lernplan Test", Null, 1, 0, 0, p.idNutzer);
        int id = t.get_idTermin("Test", QDate::currentDate(), AchtUhr, ZehnUhr, p.idNutzer);

        t.TerminInsert("Lernen Test", QDate::currentDate().addDays(1), AchtUhr, ZehnUhr, "Lernplan Test", Null, 1, 0, 1, p.idNutzer);
        int id2 = t.get_idTermin("Lernen Test", QDate::currentDate().addDays(1), AchtUhr, ZehnUhr, p.idNutzer);

        Lernplan l;
        l.EndDatum = QDate::currentDate().addDays(1);

        Kalender k;
        ASSERT_THAT(k.CheckLernplan(p.idNutzer), true);

        t.LoescheTermin2(id);
        t.LoescheTermin2(id2);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20104, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Erstml muss ein Lernplan schon existieren
        Termin t;
        QTime AchtUhr, ZehnUhr;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(22, 0, 0);
        QTime Null;
        Null.setHMS(0, 0, 0);

        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest2")) {
            p.ProfilInsert("LernplanTest2", "Lernen", "lern2@mail.de", "l1", "l2");
        }
        p.ProfilLaden("LernplanTest2", "Lernen");


        t.TerminInsert("Test", QDate::currentDate(), AchtUhr, ZehnUhr, "Lernplan Test", Null, 1, 0, 0, p.idNutzer);
        int id = t.get_idTermin("Test", QDate::currentDate(), AchtUhr, ZehnUhr, p.idNutzer);

        t.TerminInsert("Test", QDate::currentDate().addDays(1), AchtUhr, ZehnUhr, "Lernplan Test", Null, 1, 0, 0, p.idNutzer);
        int id2 = t.get_idTermin("Test", QDate::currentDate().addDays(1), AchtUhr, ZehnUhr, p.idNutzer);

        Kalender k;

        ASSERT_THAT(k.CheckLernplan(p.idNutzer), false);

        t.LoescheTermin2(id);
        t.LoescheTermin2(id2);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


#endif // TST_CHECKLERNPLAN_H
