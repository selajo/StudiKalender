#ifndef TST_STUDIENFACH_H
#define TST_STUDIENFACH_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Studienfach_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Studienfach_Klasse.cpp>

using namespace testing;


//Überprüfen ob von Studienfach die Id ermittlebar ist
TEST(Test_get_idStudienfach, Test)
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


    ASSERT_THAT(T._idStudienfach, -1);
    ASSERT_THAT(T._Bezeichnung," ");
    ASSERT_THAT(T._ECTS,-1);
    ASSERT_THAT(T._SWS,-1);
    ASSERT_THAT(T._Eigenstunden,-1);
    ASSERT_THAT(T._idNutzer_FK,-1);

}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

#endif // TST_STUDIENFACH_H
