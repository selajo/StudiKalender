#ifndef TST_UPDATE_ERINNERUNG_NULL_H
#define TST_UPDATE_ERINNERUNG_NULL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>

using namespace testing;


//Überprüfen ob es die Geladenen werte stimmen
TEST(tst_40019, Test)
{{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //TestTermin ist speziell für den Test erstellt

    QTime ti(01,00,00,00);

    Termin T;
    T.TerminwertevonID(6712);
    ASSERT_THAT(T.Erinnerung,ti);

    bool ergebnis =T.Update_Erinnerung_NULL(6712);

    ASSERT_THAT(ergebnis,true);
    QTime tim(00,00,00,00);
    ASSERT_THAT(T.Erinnerung,tim);




}
    //Aufräumen
     QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

#endif // TST_UPDATE_ERINNERUNG_NULL_H
