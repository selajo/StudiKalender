#ifndef TST_TERMINCHECKVORHANDEN_H
#define TST_TERMINCHECKVORHANDEN_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>

using namespace testing;


//Überprüft ob der Termin schon vorhanden ist
TEST(tst_40006, Test)
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


    Termin T;
    bool ergebnis = T.TerminCheckVorhanden("TestTermin",date,Beginn,Ende,76);
    ASSERT_THAT(ergebnis,true);


}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//EinTermin der noch nie exestiert hat
TEST(tst_40007, Test)
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


    Termin T;
    bool ergebnis = T.TerminCheckVorhanden("TestTerminTTTTTT",date,Beginn,Ende,76);
    ASSERT_THAT(ergebnis,false);


}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//EinTermin der wieder gelöscht wurde
TEST(tst_40008, Test)
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


    Termin T;
    bool ergebnis = T.TerminCheckVorhanden("TestTerminB",date,Beginn,Ende,76);
    ASSERT_THAT(ergebnis,false);


}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_TERMINCHECKVORHANDEN_H
