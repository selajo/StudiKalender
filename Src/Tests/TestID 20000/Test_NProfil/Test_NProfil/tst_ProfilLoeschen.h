#ifndef TST_PROFILLOESCHEN_H
#define TST_PROFILLOESCHEN_H


#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilLoeschen testen

TEST(test_20023, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster ist speziell für Testzwecke erstellt
        NProfil p;
        //Nutzer muss angemeldet sein
        p.ProfilLaden("MaxMuster", "Test123!");
        bool ergebnis = p.ProfilLoeschen("Test123!", "Max1", "Max2");

        ASSERT_THAT(ergebnis, true);

        //Prüfen, ob MaxMuster wirklich gelöscht
        ergebnis = p.ProfilCheckNutzername("MaxMuster");

        ASSERT_THAT(ergebnis, false);

        //Ausgangszustand herstellen
        ergebnis = p.ProfilInsert("MaxMuster", "Test123!", "max@muster.de", "Max1", "Max2");


        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20024, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster ist speziell für Testzwecke erstellt
        NProfil p;
        p.ProfilLaden("MaxMuster", "Test123!");
        bool ergebnis = p.ProfilLoeschen("Test3!", "Max1", "Max2");

        ASSERT_THAT(ergebnis, false);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20025, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster ist speziell für Testzwecke erstellt
        NProfil p;
        //Nutzer muss angemeldet sein
        p.ProfilLaden("MaxMuster", "Test123!");
        bool ergebnis = p.ProfilLoeschen("Test123!", "M1", "Max2");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20026, test)
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
        bool ergebnis = p.ProfilLoeschen("Test123!", "Max1", "M2");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_PROFILLOESCHEN_H
