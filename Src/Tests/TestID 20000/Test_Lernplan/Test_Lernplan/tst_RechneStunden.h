#ifndef TST_RECHNESTUNDEN_H
#define TST_RECHNESTUNDEN_H

#include <tst_tst_checkenddatum.h>

//Author: Josef Lanzl

using namespace testing;

//RechneStunden

TEST(test_20216, test)
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
        QDate Start, Ziel;
        Start.setDate(2019, 11, 16);
        Ziel.setDate(2019, 11, 30);
        QTime AchtUhr, ZehnUhr, Null;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(20, 37, 0);
        Null.setHMS(0, 0, 0);

        Studienfach s;
        int StundenStudienfach = 3;
        if(s.get_idStudienfach("Testen", p.idNutzer) == 0) {
            s.insert_Studienfach("Testen", 5, 4, StundenStudienfach, p.idNutzer);
        }

        Termin t;
        if(!t.TerminCheckVorhanden("Termin", Start, AchtUhr, ZehnUhr,p.idNutzer)) {
            t.TerminInsert("Termin", Start, AchtUhr, ZehnUhr, "Termin", Null, 1, 0, 0, p.idNutzer);
        }


        Lernplan l;
        int ergebnis = l.RechneStunden(Start, Ziel, p.idNutzer);

        ASSERT_THAT(ergebnis, 12 * 60 + 37 + StundenStudienfach * 60);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}
#endif // TST_RECHNESTUNDEN_H
