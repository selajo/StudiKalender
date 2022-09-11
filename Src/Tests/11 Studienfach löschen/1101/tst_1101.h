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


//Überprüfen ob Studienfach löschbar ist
TEST(Test_1101a, Test)
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

    bool ergebnis = T.DeleteStudienfach(72);
    ASSERT_THAT(ergebnis,true);
}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

//Überprüfen ob Studienfach löschbar ist
TEST(Test_1101b, Test)
{{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //Studienfach TestStd ist speziell für den Test erstellt id 72 und wurde im ersten Fall bereits gelöscht

    Studienfach T;

    bool ergebnis = T.DeleteStudienfach(72);
    ASSERT_THAT(ergebnis,false);
}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}


#endif // TST_TEST_H
