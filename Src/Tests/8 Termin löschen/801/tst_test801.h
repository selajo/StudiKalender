#ifndef TST_TEST801_H
#define TST_TEST801_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>

using namespace testing;

TEST(test_801, test801)
{

    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

//TestTermin ist speziell für den Test erstellt
        Termin t;


        QDate date (1,1,2020);
        QTime Beginn( 10,10,0);
        QTime Ende( 10,20,0);
        QTime timer(0,0,0);
        QString St = "Test";

        //Termin einfügen der Gelöscht werden soll
        bool ergebnis = t.TerminInsert("TestTermin", date, Beginn, Ende, St, timer , 0 , 0, 0,1);
        ASSERT_THAT(ergebnis, true);

        //Termin wieder löschen
        ergebnis = t.LoescheTermin1("TestTermin",date, Beginn,Ende, 1);
        ASSERT_THAT(ergebnis,true);

    }
    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_801a, test801)
{

    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

//TestTermin ist speziell für den Test erstellt
        Termin t;

        QString Name= "TestTermin";
        QDate date (1,1,2020);
        QTime Beginn( 10,10,0);
        QTime Ende( 10,20,0);
        QTime timer(0,0,0);
        QString St = "Test";

        //Termin einfügen der Gelöscht werden soll
        bool ergebnis = t.TerminInsert(Name, date, Beginn, Ende, St, timer , 0 , 0, 0, 1);
        ASSERT_THAT(ergebnis, true);

        //Bekomme den Primärschlüssel
        int i =t.get_idTermin(Name,date,Beginn,Ende, 1);

        //Termin wieder löschen
        ergebnis = t.LoescheTermin2(i);
        ASSERT_THAT(ergebnis,true);

    }
    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


#endif // TST_TEST801_H
