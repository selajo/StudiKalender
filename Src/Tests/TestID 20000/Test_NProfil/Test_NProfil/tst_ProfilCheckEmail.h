#ifndef TST_PROFILCHECKEMAIL_H
#define TST_PROFILCHECKEMAIL_H

#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilCheckEmail testen

TEST(test_20004, test)
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
        bool ergebnis = p.ProfilCheckEmail("max@muster.de");

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


TEST(test_20005, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Email falsch geschrieben, bzw. nicht existent
        NProfil p;
        bool ergebnis = p.ProfilCheckEmail("mx@musster.de");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_PROFILCHECKEMAIL_H
