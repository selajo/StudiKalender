#ifndef TST_301_H
#define TST_301_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.cpp>


//Author: Josef Lanzl

using namespace testing;

//Test-ID: 301 ; Passwort erfolgreich geändert
TEST(test_301, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster ist speziell für die Tests erstellt worden
        NProfil p;
        p.ProfilLaden("MaxMuster", "Test123!");
        p.ProfilChangeEmail("max@muster.de");
        bool ergebnis = p.ProfilPasswortVergessen("MaxMuster", "max@muster.de", "Max1", "Max2", "Test12345");
        ASSERT_THAT(ergebnis, true);

        //Überprüfen, ob Passwort wirklich geändert wurde
        ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test12345");
        ASSERT_THAT(ergebnis, true);

        //zurück auf Ausgangszustand
        ergebnis = p.ProfilUpdatePasswort("MaxMuster", "Test12345", "Test123!");
        ASSERT_THAT(ergebnis, true);
    }
    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Test-ID: 302 ; Nutzername nicht im System vorhanden
TEST(test_302, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster ist speziell für die Tests erstellt worden
        NProfil p;
        bool ergebnis = p.ProfilPasswortVergessen("MaxMuer", "max@muster.de", "Max1", "Max2", "Test12345");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Test-ID: 303a ; Sicherheitsfrage1 falsch beantwortet
TEST(test_303a, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster ist speziell für die Tests erstellt worden
        NProfil p;
        bool ergebnis = p.ProfilPasswortVergessen("MaxMuster", "max@muster.de", "Maxime1", "Max2", "Test12345");

        ASSERT_THAT(ergebnis, false);

        //Prüfe, ob Passwort unverändert
        ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test123!");
        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Test-ID: 303b ; Sicherheitsfrage2 falsch beantwortet
TEST(test_303b, test)
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

       //MaxMuster ist speziell für die Tests erstellt worden
       NProfil p;
       bool ergebnis = p.ProfilPasswortVergessen("MaxMuster", "max@muster.de", "Max1", "Maxime2", "Test12345");

       ASSERT_THAT(ergebnis, false);

       //Prüfe, ob Passwort unverändert
       ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test123!");
       ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 307 ; Nutzername richtig, Email falsch
TEST(test_307, test)
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

        //MaxMuster ist speziell für die Tests erstellt worden
        NProfil p;
        bool ergebnis = p.ProfilPasswortVergessen("MaxMuster", "max@ster.de", "Max1", "Max2", "Test12345");

        ASSERT_THAT(ergebnis, false);

        //Prüfe, ob Passwort unverändert
        ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test123!");
        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//TEST-ID: 308 ; Nutzername und Email nicht im System vorhanden
TEST(test_308, test)
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

        //MaxMuster ist speziell für die Tests erstellt worden
        NProfil p;
        bool ergebnis = p.ProfilPasswortVergessen("MMuster", "max@ster.de", "Max1", "Max2", "Test12345");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_301_H
