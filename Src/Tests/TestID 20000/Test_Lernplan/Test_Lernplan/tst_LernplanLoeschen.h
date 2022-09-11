#ifndef TST_LERNPLANLOESCHEN_H
#define TST_LERNPLANLOESCHEN_H


#include <tst_tst_checkenddatum.h>

//Author: Josef Lanzl

using namespace testing;

//LernplanLoeschen

TEST(test_20211, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //Erstml muss ein Lernplan schon existieren
        Termin t;
        QTime AchtUhr, ZehnUhr;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(22, 0, 0);
        QTime Null;
        Null.setHMS(0, 0, 0);
        int NutzerID = 1;
        //Nutzer Josef mit id = 1
        t.TerminInsert("Lernen Test", QDate::currentDate(), AchtUhr, ZehnUhr, "Lernplan Test", Null, 1, 0, 1, NutzerID);
        int id = t.get_idTermin("Lernen Test", QDate::currentDate(), AchtUhr, ZehnUhr, NutzerID);

        Lernplan l;
        l.LernplanLoeschen(NutzerID);

        ASSERT_THAT(t.CheckTerminID(id), false);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}



#endif // TST_LERNPLANLOESCHEN_H
