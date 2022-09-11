#ifndef TST_STUDIENFACHVONNUTZER_H
#define TST_STUDIENFACHVONNUTZER_H

#include <tst_tst_termineinwoche.h>

//Author: Josef Lanzl

using namespace testing;

//StudienfachVonNutzer

TEST(test_20105, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest1")) {
            p.ProfilInsert("LernplanTest1", "Lernen", "lern@mail.de", "l1", "l2");
        }

        p.ProfilLaden("LernplanTest1", "Lernen");
        Studienfach s;
        if(s.get_idStudienfach("Testen", p.idNutzer) == 0) {
            s.insert_Studienfach("Testen", 5, 4, 3, p.idNutzer);
        }

        Kalender k;
        k.StudienfachVonNutzer(p.idNutzer);

        ASSERT_THAT(k.Studienfaecher[0]._Bezeichnung, "Testen");
        ASSERT_THAT(k.Studienfaecher[0]._Eigenstunden / 60, 3);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20106, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        NProfil p;
        if(!p.ProfilCheckNutzername("LernplanTest2")) {
            p.ProfilInsert("LernplanTest2", "Lernen", "lern2@mail.de", "l1", "l2");
        }

        p.ProfilLaden("LernplanTest2", "Lernen");

        Kalender k;
        k.StudienfachVonNutzer(p.idNutzer);

        ASSERT_THAT(k.Studienfaecher[0]._Eigenstunden, -1);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_STUDIENFACHVONNUTZER_H
