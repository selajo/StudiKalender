#ifndef TST_STUDIENFACH_LADEN_H
#define TST_STUDIENFACH_LADEN_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Studienfach_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Studienfach_Klasse.cpp>
using namespace testing;


//Überprüfen ob Studienfach löschbar ist
TEST(Test_Studienfach_Laden, Test)
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

    bool ergebnis = T.StudienfachLaden(ST,76);
    ASSERT_THAT(T._Bezeichnung, "TestStd");
    ASSERT_THAT(ergebnis, true);
}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
#endif // TST_STUDIENFACH_LADEN_H
