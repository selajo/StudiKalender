#ifndef TST_TEST_H
#define TST_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(tst_1001, test)
{
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Studienfach_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Studienfach_Klasse.cpp>

using namespace testing;


//Überprüfen ob Studienfach update ist
TEST(Test_UpdateStudienfach, Test)
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
   // T.StudienfachLaden("TestStd",76);
    //ASSERT_THAT(T._Bezeichnung,"TestStd");

    bool ergebnis = T.UpdateStudienfach(72,"Test",0,0,0);
    ASSERT_THAT(ergebnis,true);

    //Konrollieren
    //T.StudienfachLaden("Test",76);
    //ASSERT_THAT(T._Bezeichnung,"Test");

   //Rückgängig machen
    ergebnis = T.UpdateStudienfach(72,"TestStd",0,0,0);
        ASSERT_THAT(ergebnis,true);
}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

//Überprüfen ob Studienfach update obwohl es nicht vorhanden ist
TEST(Test_UpdateStudienfacha, Test)
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


    bool ergebnis = T.UpdateStudienfach(73,"Test",0,0,0);
    ASSERT_THAT(ergebnis,true);


}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
}

#endif // TST_TEST_H
