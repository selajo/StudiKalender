#ifndef TST_TERMINHEUTEMITERINNERUNGEN_H
#define TST_TERMINHEUTEMITERINNERUNGEN_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>

using namespace testing;


//Überprüfen ob es die Geladenen werte stimmen
TEST(tst_40009, Test)
{{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //TestTermin ist speziell für den Test erstellt
    QDate date (2020,6,28);
    QTime Beginn( 12,00,00);
    QTime Ende( 13,00,00);
    QTime timer(01,00,00);
    QTime Timer(02,00,00);
    QString St = "TestTermin";
    QString Name= "TestTermin";


    Termin T;
    //Zwei Termine wurden für den heutigen Tage 28.06.2020 hinzugefügt

    QVector<Termin> ergebnis =T.TermineHeuteMitErinnerungen(76);
    //Kontrollieren ob diese Termine heute vorhanden sind
    ASSERT_THAT(ergebnis[0].idTermin,6713);
    ASSERT_THAT(ergebnis[1].idTermin,6712);


}
    //Aufräumen
     QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

//Überprüfen ob mehr als die 2 TestTermine vorhanden sind
TEST(tst_40010, Test)
{{
    //setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

    //TestTermin ist speziell für den Test erstellt
    QDate date (2020,6,28);
    QTime Beginn( 12,00,00);
    QTime Ende( 13,00,00);
    QTime timer(01,00,00);
    QTime Timer(02,00,00);
    QString St = "TestTermin";
    QString Name= "TestTermin";


    Termin T;
    //Zwei Termine wurden für den heutigen Tage 28.06.2020 hinzugefügt

    QVector<Termin> ergebnis =T.TermineHeuteMitErinnerungen(76);
    //Kontrollieren ob diese Termine heute vorhanden sind
    ASSERT_THAT(ergebnis[0].idTermin,6713);
    ASSERT_THAT(ergebnis[1].idTermin,6712);
    ASSERT_THAT(ergebnis[2].idTermin,NULL); //out of range Fehler

}
    //Aufräumen
     QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

#endif // TST_TERMINHEUTEMITERINNERUNGEN_H
