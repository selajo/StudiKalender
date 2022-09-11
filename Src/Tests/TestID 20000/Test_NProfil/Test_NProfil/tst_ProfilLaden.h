#ifndef TST_PROFILLADEN_H
#define TST_PROFILLADEN_H


#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilLaden testen

TEST(test_20019, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Josef ist speziell für Testzwecke erstellt
        //MaxMusters ID hat sich wegen Loeschen und neu erstellen zu oft verändert
        NProfil p;
        bool ergebnis = p.ProfilLaden("Josef", "12345");

        ASSERT_THAT(p.Nutzername, "Josef");
        ASSERT_THAT(p.Email, "mail");
        ASSERT_THAT(p.idNutzer, 1);
        ASSERT_THAT(p.Passwort, "12345");
        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20020, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Josef ist speziell für Testzwecke erstellt
        //MaxMuster's ID hat sich wegen Loeschen und neu erstellen zu oft verändert
        NProfil p;
        bool ergebnis = p.ProfilLaden("Josef", "123456");

        ASSERT_THAT(p.Nutzername, "");
        ASSERT_THAT(p.Email, "");
        ASSERT_THAT(p.idNutzer, -1);
        ASSERT_THAT(p.Passwort, "");
        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20021, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Josef ist speziell für Testzwecke erstellt
        //MaxMuster's ID hat sich wegen Loeschen und neu erstellen zu oft verändert
        NProfil p;
        bool ergebnis = p.ProfilLaden("Jsef", "12345");

        ASSERT_THAT(p.Nutzername, "");
        ASSERT_THAT(p.Email, "");
        ASSERT_THAT(p.idNutzer, -1);
        ASSERT_THAT(p.Passwort, "");
        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20022, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Josef ist speziell für Testzwecke erstellt
        //MaxMuster's ID hat sich wegen Loeschen und neu erstellen zu oft verändert
        NProfil p;
        bool ergebnis = p.ProfilLaden("Jsef", "123456");

        ASSERT_THAT(p.Nutzername, "");
        ASSERT_THAT(p.Email, "");
        ASSERT_THAT(p.idNutzer, -1);
        ASSERT_THAT(p.Passwort, "");
        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_PROFILLADEN_H
