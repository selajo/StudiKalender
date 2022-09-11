#ifndef TST_GET_IDTERMIN_H
#define TST_GET_IDTERMIN_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>

using namespace testing;


//Wenn ein termin nur vorhanden ist
TEST(tst_40004, Test)
{{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //TestTermin ist speziell für den Test erstellt
    QDate date (2020,6,26);
    QTime Beginn( 12,00,0);
    QTime Ende( 13,00,0);
    QTime timer(0,0,0);
    QString St = "Test";
    //Termin Checken ob die id überhaupt vorhanden ist
    Termin T;
    int ergebnis = T.get_idTermin("TestTermin",date,Beginn, Ende,76);
    ASSERT_THAT(ergebnis, 6704);
}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Wenn es die falschen Werte sind
TEST(tst_40005, Test)
{{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //TestTermin ist speziell für den Test erstellt
    QDate date (2020,6,27);
    QTime Beginn( 12,00,0);
    QTime Ende( 13,00,0);
    QTime timer(0,0,0);
    QString St = "Test";
    //Termin Checken ob die id überhaupt vorhanden ist
    Termin T;
    int ergebnis = T.get_idTermin("TestTermin",date,Beginn, Ende,76);
    ASSERT_THAT(ergebnis, -1);
}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


/*
//Wenn es denn gleichen Termin exakt zwei mal gibt Fehler
TEST(TestCheckidTermina, Test)
{{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //TestTermin ist speziell für den Test erstellt
    QDate date (26,6,2020);
    QTime Beginn( 12,00,0);
    QTime Ende( 13,00,0);
    QTime timer(0,0,0);
    QString St = "Test";
    //Termin Checken ob die id überhaupt vorhanden ist
    Termin T;
    int ergebnis = T.get_idTermin("TestTermin",date,Beginn, Ende,76);
    ASSERT_THAT(ergebnis, 6704);
}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Fehler kann behoben werden wenn bereits beim einfügen kontrolliert wird
*/

#endif // TST_GET_IDTERMIN_H
