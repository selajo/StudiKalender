#ifndef TST_201_H
#define TST_201_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../Code/StartseiteStudikalender/Nutzerprofil.h"
#include "../../../Code/StartseiteStudikalender/Nutzerprofil.cpp"

//Author: Josef Lanzl

using namespace testing;


//Test-ID: 201 ; E-Mail-Adresse und Passwort stimmen überein, Nutzerdaten erfolgreich geändert.
TEST(test_201, test)
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
        //Max muss angemeldet sein
        p.ProfilLaden("MaxMuster", "Test123!");
        bool ergebnis = p.ProfilChangeEmail("maximus@muster.de");

        ASSERT_THAT(ergebnis, true);

        p.ProfilLaden("MaxMuster", "Test123!");
        ASSERT_THAT(p.Email, "maximus@muster.de");

        //Wieder auf Ausgang
        p.ProfilChangeEmail("max@muster.de");
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


//Test-ID: 202 ; Passwort stimmt nicht mit Profil überein
TEST(test_202, test)
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
        //Passwort stimmt nicht
        NProfil p;
        bool ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test133!");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


//Test-ID: 203 ; Neue E-Mail-Adresse bereits registriert
TEST(test_203, test)
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
        //Max muss angemeldet sein
        p.ProfilLaden("MaxMuster", "Test123!");

        //Hier wird die Email von Josef verwendet
        bool ergebnis = p.ProfilChangeEmail("mail");

        ASSERT_THAT(ergebnis, false);

        //Email unverändert
        p.ProfilLaden("MaxMuster", "Test123!");
        ASSERT_THAT(p.Email, "max@muster.de");
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_201_H
