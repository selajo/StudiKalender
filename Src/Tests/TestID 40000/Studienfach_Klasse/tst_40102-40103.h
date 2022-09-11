#ifndef TST_GET_IDSTUDIENFACH_H
#define TST_GET_IDSTUDIENFACH_H

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

    int ergebnis = T.get_idStudienfach(ST,76);
    ASSERT_THAT(ergebnis, 72);

}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}


//Überprüfen ob von fehlerhaften Studienfach die Id ermittlebar ist
TEST(Test_get_idStudienfacha, Test)
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

    int ergebnis = T.get_idStudienfach("ST",76);
    ASSERT_THAT(ergebnis, 0);

}

//Aufräumen
 QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

#endif // TST_GET_IDSTUDIENFACH_H
