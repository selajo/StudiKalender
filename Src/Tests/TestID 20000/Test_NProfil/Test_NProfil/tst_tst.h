#ifndef TST_TEST_H
#define TST_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.cpp>
#include <QCoreApplication>

//Author: Josef Lanzl

using namespace testing;

//ProfilCheckNutzername testen

TEST(test_20042, test)
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
        bool ergebnis = p.ProfilCheckNutzername("MaxMuster");

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20043, test) {
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Nutzername falsch geschrieben, bzw. nicht existent
        NProfil p;
        bool ergebnis = p.ProfilCheckNutzername("MxMuuster");

        ASSERT_THAT(ergebnis, false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}




#endif // TST_TEST_H

