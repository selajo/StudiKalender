#ifndef TST_TEST_H
#define TST_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Studienfach_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Studienfach_Klasse.cpp>

using namespace testing;


//Überprüfen ob Studienfach eingefügt werden kann
TEST(Test_901, Test)
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

    bool ergebnis = T.insert_Studienfach("TestN",5,5,2,76);
    ASSERT_THAT(ergebnis, 72);

}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
#endif // TST_TEST_H
