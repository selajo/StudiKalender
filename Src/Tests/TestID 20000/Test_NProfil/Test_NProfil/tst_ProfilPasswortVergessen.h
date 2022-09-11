#ifndef TST_PROFILPASSWORTVERGESSEN_H
#define TST_PROFILPASSWORTVERGESSEN_H


#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilPasswortVergessen testen

TEST(test_20031, test)
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
        bool ergebnis = p.ProfilPasswortVergessen("MaxMuster", "max@muster.de", "Max1", "Max2", "Test12345");
        ASSERT_THAT(ergebnis, true);

        p.ProfilLaden("MaxMuster", "Test12345");
        ASSERT_THAT(p.Passwort, "Test12345");

        //zurück auf Ausgangszustand
        ergebnis = p.ProfilUpdatePasswort("MaxMuster", "Test12345", "Test123!");
        ASSERT_THAT(ergebnis, true);
    }
    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20032, test)
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

        //Prüfe, ob Passwort unverändert
        ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test123!");
        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20033, test)
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
        bool ergebnis = p.ProfilPasswortVergessen("MaxMuster", "max@ster.de", "Max1", "Max2", "Test12345");

        ASSERT_THAT(ergebnis, false);

        //Prüfe, ob Passwort unverändert
        ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test123!");
        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20034, test)
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

TEST(test_20035, test)
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
       bool ergebnis = p.ProfilPasswortVergessen("MaxMuster", "max@muster.de", "Max1", "Maxime2", "Test12345");

       ASSERT_THAT(ergebnis, false);

       //Prüfe, ob Passwort unverändert
       ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test123!");
       ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_PROFILPASSWORTVERGESSEN_H
