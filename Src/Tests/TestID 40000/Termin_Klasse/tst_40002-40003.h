#ifndef TST_TEST_H
#define TST_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>

using namespace testing;

TEST(tst_40002, Test)
{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //TestTermin ist speziell für den Test erstellt
    //Termin Checken ob die id überhaupt vorhanden ist
    Termin T;
    bool ergebnis = T.CheckTerminID(6704);
    ASSERT_THAT(ergebnis,true);
}


//Termin der Nicht vorhanden ist
TEST(tst_40003, Test)
{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //TestTermin ist speziell für den Test erstellt
    //Termin Checken ob die id überhaupt vorhanden ist
    Termin T;
    bool ergebnis = T.CheckTerminID(100000);
    ASSERT_THAT(ergebnis,false);
}

#endif // TST_TEST_H
