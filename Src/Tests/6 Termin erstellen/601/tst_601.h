#ifndef TST_601_H
#define TST_601_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>

using namespace testing;

//Termin richtig einfügen

TEST(tst_601, test)
{
        {
            //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    //TestTermin ist speziell für den Test erstellt
            Termin t;
            QDate date (1,1,2020);
            QTime Beginn( 10,10,0);
            QTime Ende( 10,20,0);
            QTime timer(0,0,0);
            QString St = "Test";

            try{

            bool ergebnis = t.TerminInsert("TestTermin", date, Beginn, Ende, St, timer , 0 , 0, 0,1);
            ASSERT_THAT(ergebnis, true);
            }

             catch (char const * s) {
                qDebug()<< s;
            }

        }
        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }

#endif // TST_601_H
