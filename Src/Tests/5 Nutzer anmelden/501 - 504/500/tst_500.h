#ifndef TST_500_H
#define TST_500_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.cpp>


//Author: Josef Lanzl

using namespace testing;

//TEST-ID: 501 ; Nutzer im System erkannt
TEST(test_501, test)
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
        bool ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test123!");
        ASSERT_THAT(ergebnis, true);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 502 ; Benutzername falsch, Passwort richtig
TEST(test_502, test)
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
        bool ergebnis = p.ProfilCheckPasswort("MaxMuuuuster", "Test123!");
        ASSERT_THAT(ergebnis, false);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 503 ; Benutzername richtig, Passwort falsch
TEST(test_503, test)
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
        bool ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test13!");
        ASSERT_THAT(ergebnis, false);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 504 ; Benutzername falsch, Passwort falsch
TEST(test_504, test)
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
        bool ergebnis = p.ProfilCheckPasswort("MaxMursuster", "Test13!");
        ASSERT_THAT(ergebnis, false);

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_500_H
