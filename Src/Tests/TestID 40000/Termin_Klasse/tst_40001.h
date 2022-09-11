#ifndef TST_TERMIN_H
#define TST_TERMIN_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>

using namespace testing;


//Überprüfen ob es Default werte stimmen
TEST(tst_40001, Test)
{{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //TestTermin ist speziell für den Test erstellt

    Termin T;

    ASSERT_THAT(T.TerminName, "0");
    ASSERT_THAT(T.idTermin,-1);
    ASSERT_THAT(T.Erledigung,false);
    ASSERT_THAT(T.idNutzer_fk,-1);
}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_TERMIN_H
