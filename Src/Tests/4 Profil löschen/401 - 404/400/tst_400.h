#ifndef TST_400_H
#define TST_400_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.cpp>


//Author: Josef Lanzl

using namespace testing;


//TEST-ID: 401 ; Profil erfolgreich gelöscht
TEST(test_401, test)
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
        bool ergebnis = p.ProfilLoeschen("Test123!", "Max1", "Max2");
        ASSERT_THAT(ergebnis, true);

        //Prüfen, ob MaxMuster wirklich gelöscht
        ergebnis = p.ProfilCheckNutzername("MaxMuster");
        ASSERT_THAT(ergebnis, false);

        //Prüfen, ob Email wirklich gelöscht
        ergebnis = p.ProfilCheckEmail("max@muster.de");
        ASSERT_THAT(ergebnis, false);

        //Ausgangszustand herstellen
        ergebnis = p.ProfilInsert("MaxMuster", "Test123!", "max@muster.de", "Max1", "Max2");
        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 402 ; Passwort falsch
TEST(test_402, test)
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
        bool ergebnis = p.ProfilLoeschen("Tt123!", "Max1", "Max2");

        ASSERT_THAT(ergebnis, false);

        //Prüfen, ob MaxMuster wirklich nicht gelöscht
        ergebnis = p.ProfilCheckNutzername("MaxMuster");
        ASSERT_THAT(ergebnis, true);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 403a ; F1 falsch
TEST(test_403a, test)
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
        bool ergebnis = p.ProfilLoeschen("Test123!", "Mx1", "Max2");
        ASSERT_THAT(ergebnis, false);

        //Prüfen, ob MaxMuster wirklich nicht gelöscht
        ergebnis = p.ProfilCheckNutzername("MaxMuster");
        ASSERT_THAT(ergebnis, true);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 403b ; F2 falsch
TEST(test_403b, test)
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
        bool ergebnis = p.ProfilLoeschen("Test123!", "Max1", "ax2");

        ASSERT_THAT(ergebnis, false);

        //Prüfen, ob MaxMuster wirklich nicht gelöscht
        ergebnis = p.ProfilCheckNutzername("MaxMuster");
        ASSERT_THAT(ergebnis, true);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 404a ; Passwort und F1 falsch
TEST(test_404a, test)
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
        bool ergebnis = p.ProfilLoeschen("Tes23!", "Mx1", "Max2");
        ASSERT_THAT(ergebnis, false);

        //Prüfen, ob MaxMuster wirklich nicht gelöscht
        ergebnis = p.ProfilCheckNutzername("MaxMuster");
        ASSERT_THAT(ergebnis, true);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 404b ; Passwort und F1 falsch
TEST(test_404b, test)
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
        bool ergebnis = p.ProfilLoeschen("Tes23!", "Max1", "x2");
        ASSERT_THAT(ergebnis, false);

        //Prüfen, ob MaxMuster wirklich nicht gelöscht
        ergebnis = p.ProfilCheckNutzername("MaxMuster");
        ASSERT_THAT(ergebnis, true);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


#endif // TST_400_H
