#ifndef TST_PROFILUPDATEPASSWORT_H
#define TST_PROFILUPDATEPASSWORT_H


#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilUpdatePasswort testen

TEST(test_20036, test)
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
        //Passwort ändern
        NProfil p;
        bool ergebnis = p.ProfilUpdatePasswort("MaxMuster", "Test123!", "Test1234!");

        ASSERT_THAT(ergebnis, true);

        //Überprüfen, ob Passwort geändert wurde
        ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test1234!");

        ASSERT_THAT(ergebnis, true);

        //Zurück setzen
        ergebnis = p.ProfilUpdatePasswort("MaxMuster", "Test1234!", "Test123!");

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20037, test)
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
        //Passwort ändern
        NProfil p;
        bool ergebnis = p.ProfilUpdatePasswort("MaxMusstter", "Test123!", "Test1234!");



        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20038, test)
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
        //Passwort ändern; mit falscher Passworteingabe
        NProfil p;
        bool ergebnis = p.ProfilUpdatePasswort("MaxMuster", "Test1234!", "Test12345!");

        ASSERT_THAT(ergebnis, false);

        //überprüfe, ob Passwort unverändert
        ergebnis = p.ProfilCheckPasswort("MaxMuster", "Test123!");

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20039, test)
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
        bool ergebnis = p.ProfilUpdatePasswort("MaxMeuster", "Test1234!", "Test12345!");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_PROFILUPDATEPASSWORT_H
