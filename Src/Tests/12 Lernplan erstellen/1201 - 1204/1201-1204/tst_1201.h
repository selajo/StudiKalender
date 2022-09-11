#ifndef TST_1201_H
#define TST_1201_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../../Code/StartseiteStudikalender/Lernplan.h>
#include <../../../../Code/StartseiteStudikalender/Lernplan.cpp>
#include <../../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>
#include <../../../../Code/StartseiteStudikalender/Studienfach_Klasse.h>
#include <../../../../Code/StartseiteStudikalender/Studienfach_Klasse.cpp>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.cpp>
#include <../../../../Code/StartseiteStudikalender/Kalender.h>
#include <../../../../Code/StartseiteStudikalender/Kalender.cpp>

using namespace testing;

//Test 1201: Datum wurde ein gültiger Wert zugewiesen
TEST(test_1201, 1201)
{
    //setup
    Lernplan l;
    l.EndDatum = QDate::currentDate().addDays(7);

    bool ergebnis = l.checkEndDatum();
    ASSERT_THAT(ergebnis, true);
}

//Test Fortsetzung 1201: Lernplan erstellen
TEST(test_1201F, 1201)
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
        Start.setDate(2018, 11, 16);
        Ziel = Start.addDays(6);
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
        l.LernplanErstellenStart(p.idNutzer);
        bool ergebnis = l.LernplanErstellenWoche(Start, Ziel, p.idNutzer);

        ASSERT_THAT(ergebnis, true);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//Test 1202: Datum wurde ein Wert aus der Vergangengeit zugewiesen
TEST(test_1202, 1201)
{
    //setup
    Lernplan l;
    l.EndDatum = QDate::currentDate();
    l.EndDatum = l.EndDatum.addDays(-2);

    bool ergebnis = l.checkEndDatum();
    ASSERT_THAT(ergebnis, false);
}


//Test 1203: Datum wurde ein Wert aus der Vergangengeit zugewiesen
TEST(test_1203, 1201)
{
    //setup
    Lernplan l;
    l.EndDatum = QDate::currentDate();
    l.EndDatum = l.EndDatum.addDays(5);

    bool ergebnis = l.checkEndDatum();
    ASSERT_THAT(ergebnis, false);
}

//Test 1204: Zu wenig Platz
TEST(test_1204, 1201)
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
        Start.setDate(2018, 11, 16);
        Ziel = Start.addDays(6);
        QTime AchtUhr, ZehnUhr, Null;
        AchtUhr.setHMS(8, 0, 0);
        ZehnUhr.setHMS(20, 37, 0);
        Null.setHMS(0, 0, 0);

        Studienfach s;
        int StundenStudienfach = 3;
        if(s.get_idStudienfach("Testen", p.idNutzer) == 0) {
            s.insert_Studienfach("Testen", 5, 4, StundenStudienfach, p.idNutzer);
        }

        if(s.get_idStudienfach("Testen die Fortsetzung", p.idNutzer) == 0) {
            s.insert_Studienfach("Testen die Fortsetzung", 5, 4, 7*14*60, p.idNutzer);
        }
        int id = s.get_idStudienfach("Testen die Fortsetzung", p.idNutzer);

        Termin t;
        if(!t.TerminCheckVorhanden("Termin", Start, AchtUhr, ZehnUhr,p.idNutzer)) {
            t.TerminInsert("Termin", Start, AchtUhr, ZehnUhr, "Termin", Null, 1, 0, 0, p.idNutzer);
        }


        Lernplan l;
        bool ergebnis = l.LernplanErstellenWoche(Start, Ziel, p.idNutzer);

        ASSERT_THAT(ergebnis, false);

        s.DeleteStudienfach(id);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

#endif // TST_1201_H
