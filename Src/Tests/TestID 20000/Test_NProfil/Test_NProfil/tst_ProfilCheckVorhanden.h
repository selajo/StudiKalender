#ifndef TST_PROFILCHECKVORHANDEN_H
#define TST_PROFILCHECKVORHANDEN_H


#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilCheckVorhanden testen

TEST(test_20010, test)
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
        bool ergebnis = p.ProfilCheckVorhanden("MaxMuster", "max@muster.de");

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20011, test)
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
        //Nutzername existiert nicht
        //Email existiert
        NProfil p;
        bool ergebnis = p.ProfilCheckVorhanden("MaxMuusster", "max@muster.de");

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20012, test)
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
        //Nutzername existiert
        //Email existiert nichts
        NProfil p;
        bool ergebnis = p.ProfilCheckVorhanden("MaxMuster", "maaaxx@muster.de");

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20013, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Nutzername und Email existieren nicht
        NProfil p;
        bool ergebnis = p.ProfilCheckVorhanden("MaxMuusster", "mmmax@muster.de");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_PROFILCHECKVORHANDEN_H
