#ifndef TST_TERMINLADEN_H
#define TST_TERMINLADEN_H


#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>
using namespace testing;


//Überprüfen ob es die Geladenen werte stimmen
TEST(tst_40011, Test)
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
    QString Name= "TestTermin";


    Termin T;
    bool ergebnis =T.TerminLaden(Name,date,Beginn,Ende,76);

    ASSERT_THAT(ergebnis,true);
    ASSERT_THAT(T.idTermin,6704);
    ASSERT_THAT(T.TerminName,"TestTermin");
    ASSERT_THAT(T.Datum,date);
    ASSERT_THAT(T.Beginn,Beginn);
    ASSERT_THAT(T.Ende,Ende);
    ASSERT_THAT(T.Beschreibung,St);
    ASSERT_THAT(T.Erinnerung,timer);
    ASSERT_THAT(T.Erledigung,0);
    ASSERT_THAT(T.Wiederholungen,0);
    ASSERT_THAT(T.idNutzer_fk,76);
    ASSERT_THAT(T.TeilLernplan,0);


}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Name nicht richtig

TEST(tst_40012, Test)
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
    QString Name= "TestTTTT";


    Termin T;
    bool ergebnis =T.TerminLaden(Name,date,Beginn,Ende,76);

    ASSERT_THAT(ergebnis,false);



}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Datum nicht richtig

TEST(TestTerminLadenb, Test)
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
    QString Name= "TestTermin";


    Termin T;
    bool ergebnis =T.TerminLaden(Name,date,Beginn,Ende,76);

    ASSERT_THAT(ergebnis,false);



}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Beginn nicht richtig

TEST(tst_40014, Test)
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
    QTime Beginn( 13,00,0);
    QTime Ende( 13,00,0);
    QTime timer(0,0,0);
    QString St = "Test";
    QString Name= "TestTermin";


    Termin T;
    bool ergebnis =T.TerminLaden(Name,date,Beginn,Ende,76);

    ASSERT_THAT(ergebnis,false);



}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Ende nicht richtig

TEST(tst_40015, Test)
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
    QTime Ende( 14,00,0);
    QTime timer(0,0,0);
    QString St = "Test";
    QString Name= "TestTermin";


    Termin T;
    bool ergebnis =T.TerminLaden(Name,date,Beginn,Ende,76);

    ASSERT_THAT(ergebnis,false);



}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Falscher Nutzer

TEST(tst_40016, Test)
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
    QTime Ende( 14,00,0);
    QTime timer(0,0,0);
    QString St = "Test";
    QString Name= "TestTermin";


    Termin T;
    bool ergebnis =T.TerminLaden(Name,date,Beginn,Ende,77);

    ASSERT_THAT(ergebnis,false);



}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_TERMINLADEN_H
