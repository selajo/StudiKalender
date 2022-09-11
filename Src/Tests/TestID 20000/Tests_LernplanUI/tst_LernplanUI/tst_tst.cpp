#include "tst_tst.h"

#include "../../../../Code/StartseiteStudikalender/Nutzerprofil.h"
#include "../../../../Code/StartseiteStudikalender/Nutzerprofil.cpp"
#include "../../../../Code/StartseiteStudikalender/Lernplan.h"
#include "../../../../Code/StartseiteStudikalender/Lernplan.cpp"
#include "../../../../Code/StartseiteStudikalender/Kalender.h"
#include "../../../../Code/StartseiteStudikalender/Kalender.cpp"
#include "../../../../Code/StartseiteStudikalender/Termin_Klasse.h"
#include "../../../../Code/StartseiteStudikalender/Termin_Klasse.cpp"
#include "../../../../Code/StartseiteStudikalender/Studienfach_Klasse.h"
#include "../../../../Code/StartseiteStudikalender/Studienfach_Klasse.cpp"

#include "../../../../Code/StartseiteStudikalender/lernplanui.h"
#include "../../../../Code/StartseiteStudikalender/lernplanui.cpp"

//Author: Josef Lanzl

tst::tst() {
    msg = "";
}
tst::~tst() {

}

void tst::TimeOut()
{
    QWidgetList allToplevelWidgets = QApplication::topLevelWidgets();
    foreach (QWidget *w, allToplevelWidgets) {
        if (w->inherits("QMessageBox")) {
            QMessageBox *mb = qobject_cast<QMessageBox *>(w);
            this->msg = mb->text();
            QTest::keyClick(mb, Qt::Key_Enter);
        }
    }
}

//ID: 20301
void tst::test_EndDatum_default()
{
    lernplanUI l;
    QVERIFY2(l.ui->EndDatum->date() == QDate::currentDate().addDays(6), "Default-Werte");

}

//ID: 20302
void tst::test_Loeschen_kein_Lernplan() {
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        lernplanUI l;
        l.ui->EndDatum->setDate(QDate::currentDate().addDays(-1));

        QTimer::singleShot(1000, this, SLOT(TimeOut()));
        l.on_Loeschen_clicked();
        QVERIFY2(this->msg == "Es existiert noch kein Lernplan.", "Kein Lernplan");
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//ID: 20303
void tst::test_Loeschen_Lernplan() {
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();
        QSqlQuery Query;

        NProfil * NP = NProfil::getInstance();
        NP->idNutzer = 1;

        QTime AchtUhr;
        AchtUhr.setHMS(8, 0, 0);
        QTime ZehnUhr;
        ZehnUhr.setHMS(22, 0, 0);
        QTime NullH;
        NullH.setHMS(0, 0, 0);
        Termin t;
        t.TerminInsert(Query, "Lernen UI-Test", QDate::currentDate(), AchtUhr, ZehnUhr, "Lernplan-Termin für das Fach UI-Test", NullH, 1,0, 1, NP->idNutzer);

        lernplanUI l;
        l.ui->EndDatum->setDate(QDate::currentDate().addDays(-1));

        QTimer::singleShot(1000, this, SLOT(TimeOut()));
        l.on_Loeschen_clicked();
        QVERIFY2(this->msg == "Lernplan erfolgreich gelöscht.", "Lernplan existiert");
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//ID: 20304
void tst::test_Studienfach_fehlt() {
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        NProfil * NP = NProfil::getInstance();
        NP->idNutzer = 0;

        lernplanUI l;
        l.ui->EndDatum->setDate(QDate::currentDate().addDays(6));


        QTimer::singleShot(1000, this, SLOT(TimeOut()));
        l.on_ok_clicked();
        QVERIFY2(this->msg == "Du musst vorher noch Studienfächer hinzufügen!", "Studienfächer fehlen");

    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//ID: 20305
void tst::test_Datum_klein() {
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        NProfil * NP = NProfil::getInstance();
        NP->idNutzer = 1;

        lernplanUI l;
        l.ui->EndDatum->setDate(QDate::currentDate());


        QTimer::singleShot(1000, this, SLOT(TimeOut()));
        l.on_ok_clicked();
        QVERIFY2(this->msg == "Der Lernplan arbeitet wochenweise. Bitte ein Datum mit Ziel > heute + 6 eingeben!", "Datum < heute + 6");


    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


//ID: 20306
void tst::test_Datum_ok() {
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        NProfil * NP = NProfil::getInstance();
        NP->idNutzer = 1;

        lernplanUI l;
        l.ui->EndDatum->setDate(QDate::currentDate().addDays(7));


        QTimer::singleShot(1000, this, SLOT(TimeOut()));
        l.on_ok_clicked();
        QVERIFY2(this->msg == "Lernplan wurde erfolgreich erstellt. Du kannst die Termine auch noch bearbeiten, falls dir doch noch wichtige Termine einfallen!", "Datum > heute + 6");


    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

//ID: 20307
void tst::test_Datum_gleich() {
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        NProfil * NP = NProfil::getInstance();
        NP->idNutzer = 1;

        lernplanUI l;
        l.ui->EndDatum->setDate(QDate::currentDate().addDays(6));


        QTimer::singleShot(1000, this, SLOT(TimeOut()));
        l.on_ok_clicked();
        QVERIFY2(this->msg == "Lernplan wurde erfolgreich erstellt. Du kannst die Termine auch noch bearbeiten, falls dir doch noch wichtige Termine einfallen!", "Datum > heute + 6");


    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    tst t;

    return QTest::qExec(&t, argc, argv);

}


//QTEST_APPLESS_MAIN(tst);

