#ifndef TST_PROFILCHECKPASSWORT_H
#define TST_PROFILCHECKPASSWORT_H


#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilCheckPasswort testen

TEST(test_20006, test)
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
        bool ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test123!");

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20007, test)
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
        //Nutzername stimmt nicht
        NProfil p;
        bool ergebnis = p.ProfilCheckPasswort("MexMusteer", "Test123!");

        ASSERT_THAT(ergebnis, false);
    }
    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20008, test)
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

TEST(test_20009, test)
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
        //Passwort und Nutzernamen stimmen nicht
        NProfil p;
        bool ergebnis = p.ProfilCheckPasswort("MaxMuuuster", "Testtt133!");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_PROFILCHECKPASSWORT_H
