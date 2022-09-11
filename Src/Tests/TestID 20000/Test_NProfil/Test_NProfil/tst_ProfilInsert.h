#ifndef TST_PROFILINSERT_H
#define TST_PROFILINSERT_H


#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilInsert testen

TEST(test_20015, test)
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
        p.ProfilLaden("MaxMuster2", "Test123!");
        p.ProfilLoeschen("Test123!", "Max1", "Max2");

        //MaxMuster2 erstellen
        bool ergebnis = p.ProfilInsert("MaxMuster2", "Test123!", "test@test.de", "1", "2");

        ASSERT_THAT(ergebnis, true);

        //Überprüfen, ob erstellt
        ergebnis = p.ProfilCheckVorhanden("MaxMuster2", "test@test.de");

        ASSERT_THAT(ergebnis, true);

        //Zurück setzen
        p.ProfilLaden("MaxMuster2", "Test123!");
        ergebnis = p.ProfilLoeschen("Test123!", "1", "2");

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20016, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster2 erstellen
        NProfil p;
        bool ergebnis = p.ProfilInsert("MaxMuster", "Test123!", "test@test.de", "1", "2");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20017, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster2 erstellen
        NProfil p;
        bool ergebnis = p.ProfilInsert("MaxMuster3", "Test1234!", "max@muster.de", "1", "2");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20018, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster2 erstellen
        NProfil p;
        bool ergebnis = p.ProfilInsert("MaxMuster", "Test123!", "max@muster.de", "1", "2");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_PROFILINSERT_H
