#ifndef TST_PROFILCHANGEEMAIL_H
#define TST_PROFILCHANGEEMAIL_H

#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilChangeEmail testen

TEST(test_20002, test)
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

TEST(test_20003, test)
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
#endif // TST_PROFILCHANGEEMAIL_H
