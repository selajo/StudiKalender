#ifndef TST_701_H
#define TST_701_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>

using namespace testing;



//Test zum Ändern des Namens
TEST(test_701, test)
{
    {
           //setup
           QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
           db.setHostName("194.95.108.24");
           db.setUserName("root");
           db.setPassword("root");
           db.setDatabaseName("kalender");
           db.open();

   //TestTermin ist speziell für die Tests erstellt worden
    Termin t;

    QDate Date(2020,6,26);
    QTime beg(12,00);
    QTime end(13,00);
    QTime rem(00,00);
    QString BE = "TestTermin";

    bool ergebnis = t.TerminUpdate(6704,"TESTTermin",Date,beg,end,BE,rem,0,0);
    ASSERT_THAT(ergebnis, true);


    //Zurücksetzen
     ergebnis = t.TerminUpdate(6704,"TestTermin",Date,beg,end,BE,rem,0,0);
    ASSERT_THAT(ergebnis, true);

}
       //Aufräumen
       QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

//Test zum Ändern des Datums
TEST(test_701a, test)
{
    {
           //setup
           QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
           db.setHostName("194.95.108.24");
           db.setUserName("root");
           db.setPassword("root");
           db.setDatabaseName("kalender");
           db.open();

   //TestTermin ist speziell für die Tests erstellt worden
    Termin t;

    QDate Date(2020,6,27);
    QTime beg(12,00);
    QTime end(13,00);
    QTime rem(00,00);
    QString BE = "TestTermin";

    bool ergebnis = t.TerminUpdate(6704,"TESTTermin",Date,beg,end,BE,rem,0,0);
    ASSERT_THAT(ergebnis, true);


    //Zurücksetzen
    QDate date(2020,6,26);
     ergebnis = t.TerminUpdate(6704,"TestTermin",date,beg,end,BE,rem,0,0);
    ASSERT_THAT(ergebnis, true);

}
       //Aufräumen
       QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

//Test für zu großen Namen unnötig weil UI nur gültige Werte liefert
/*TEST(test_701b, test)
{
    {
           //setup
           QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
           db.setHostName("194.95.108.24");
           db.setUserName("root");
           db.setPassword("root");
           db.setDatabaseName("kalender");
           db.open();

   //TestTermin ist speziell für die Tests erstellt worden
    Termin t;

    QDate Date(2020,6,27);
    QTime beg(12,00);
    QTime end(13,00);
    QTime rem(00,00);
    QString BE = "TestTermin";

    bool ergebnis = t.TerminUpdate(6704,"TerminTESTTerminTESTTerminTerminTESTTerminTESTTerminTerminTESTTerminTESTTermin",Date,beg,end,BE,rem,0,0);
    ASSERT_THAT(ergebnis, false);


    //Zurücksetzen
    QDate date(2020,6,26);
     ergebnis = t.TerminUpdate(6704,"TestTermin",date,beg,end,BE,rem,0,0);
    ASSERT_THAT(ergebnis, true);

}
       //Aufräumen
       QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
*/
#endif // TST_701_H
