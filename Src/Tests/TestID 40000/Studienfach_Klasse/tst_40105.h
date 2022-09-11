#ifndef TST_STUDIENFACHWERTEVONID_H
#define TST_STUDIENFACHWERTEVONID_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/StartseiteStudikalender/Studienfach_Klasse.h>
#include <../../../Code/StartseiteStudikalender/StartseiteStudikalender/Studienfach_Klasse.cpp>

using namespace testing;


//Überprüfen ob Studienfach von id Werte ablesen kann
TEST(tst_40105, Test)
{{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //Studienfach TestStd ist speziell für den Test erstellt id 72

    Studienfach T;
    QString ST ="TestStd";

    bool ergebnis =T.StudienfachwertevonID(72);
    ASSERT_THAT(T._Bezeichnung, "TestStd");
    ASSERT_THAT(ergebnis, true);
    ASSERT_THAT(T._idStudienfach, 72);

    ASSERT_THAT(T._ECTS,1);
    ASSERT_THAT(T._SWS,0);
    ASSERT_THAT(T._Eigenstunden,0);
    ASSERT_THAT(T._idNutzer_FK,76);
}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

#endif // TST_STUDIENFACHWERTEVONID_H
