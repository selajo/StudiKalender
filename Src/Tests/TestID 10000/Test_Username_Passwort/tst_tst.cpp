#include "tst_tst.h"

//Alle notwendingen hs und cpps
#include "Nutzerprofil.h"
#include "Nutzerprofil.cpp"
#include "username.h"
#include "username.cpp"
#include "password.h"
#include "password.cpp"

#include <QMessageBox>




//Author: Irma Krieger

tst::tst() {
    msg = "";
}
tst::~tst() {

}

//Damit sich die QMessageBoxen automatisch schliessen
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

// TESTFÄLLE USERNAME VERGESSEN

void tst::Abbruch()
{
    //Testfall 10017
    //Nutzer bricht vorgang ab

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

Username p;
p.on_pushButton_clicked();
QTimer::singleShot(1000, this, SLOT(TimeOut()));


//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");}

void tst::Feldausgefuellt_10018()
{
    //Testfall 10018
        //alles leer

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

        Username p;
        p.ui->Email->setText("");
        p.ui->lES1->setText("");
        p.ui->lES2->setText("");
        p.on_ButtonCheck_clicked();
        QTimer::singleShot(1000, this, SLOT(TimeOut()));


        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}


void tst::Feldausgefuellt_10019()
{
    //Testfall 10019
        //Email = 1, S1 = 0, S2 = 0


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                Username p;
                p.ui->Email->setText("irma.krieger@ymail.com");
                p.ui->lES1->setText("");
                p.ui->lES2->setText("");
                p.on_ButtonCheck_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungueltige Angaben");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

void tst::Feldausgefuellt_10020()
{
    //Testfall 10020
        //Email = 0, S1 = 1, S2 = 0


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                Username p;
                p.ui->Email->setText("");
                p.ui->lES1->setText("abc");
                p.ui->lES2->setText("");
                p.on_ButtonCheck_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

void tst::Feldausgefuellt_10021()
{
    //Testfall 10021
        //Email = 0, S1 = 0, S2 = 1


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                Username p;
                p.ui->Email->setText("");
                p.ui->lES1->setText("");
                p.ui->lES2->setText("test");
                p.on_ButtonCheck_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Felder", "Ungültige Angaben");
        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

void tst::Feldausgefuellt_10022()
{
    //Testfall 10022
        //Email = 1, S1 = 1, S2 = 0


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                Username p;
                p.ui->Email->setText("irma.krieger@ymail.com");
                p.ui->lES1->setText("abc");
                p.ui->lES2->setText("");
                p.on_ButtonCheck_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

void tst::Feldausgefuellt_10023()
{
    //Testfall 10023
        //Email = 1, S1 = 0, S2 = 1

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                Username p;
                p.ui->Email->setText("irma.krieger@ymail.com");
                p.ui->lES1->setText("");
                p.ui->lES2->setText("test");
                p.on_ButtonCheck_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

void tst::Feldausgefuellt_10024()
{
    //Testfall 10024
        //Email = 0, S1 = 1, S2 = 1


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                Username p;
                p.ui->Email->setText("");
                p.ui->lES1->setText("abc");
                p.ui->lES2->setText("test");
                p.on_ButtonCheck_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}



//____________________________________________________________________________________________

// TESTFÄLLE PASSWORT VERGESSEN

void tst::Feldausgefuellt_10025()
{
    //Testfall 10025
    //Kein Feld ist ausgefüllt (Username, S1, S2, Email, Passwort)

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10026()
{
    //Testfall 10026
    // Username=0, S1=0, S2=0, Email=0, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10027()
{
    //Testfall 10027
    //Username=0, S1=0, S2=0, Email=1, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10028()
{
    //Testfall 10028
    //Username=0, S1=0, S2=0, Email=1, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10029()
{
    //Testfall 10029
    //Username=0, S1=0, S2=1, Email=0, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10030()
{
    //Testfall 10030
    //Username=0, S1=0, S2=1, Email=0, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10031()
{
    //Testfall 10031
    //Username=0, S1=0, S2=1, Email=1, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10032()
{
    //Testfall 10032
    //Username=0, S1=0, S2=1, Email=1, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10033()
{
    //Testfall 10033
    //Username=0, S1=1, S2=0, Email=0, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10034()
{
    //Testfall 10034
    //Username=0, S1=1, S2=0, Email=0, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10035()
{
    //Testfall 10035
    //Username=0, S1=1, S2=0, Email=1, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10036()
{
    //Testfall 10036
    //Username=0, S1=1, S2=0, Email=1, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10037()
{
    //Testfall 10037
    //Username=0, S1=1, S2=1, Email=0, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10038()
{
    //Testfall 10038
    //Username=0, S1=1, S2=1, Email=1, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10039()
{
    //Testfall 10039
    //Username=0, S1=1, S2=1, Email=1, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10040()
{
    //Testfall 10040
    //Username=1, S1=0, S2=0, Email=0, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10041()
{
    //Testfall 10041
    //Username=1, S1=0, S2=0, Email=0, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10042()
{
    //Testfall 10042
    //Username=1, S1=0, S2=0, Email=1, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10043()
{
    //Testfall 10043
    //Username=1, S1=0, S2=0, Email=1, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10044()
{
    //Testfall 10044
    //Username=1, S1=0, S2=1, Email=0, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10045()
{
    //Testfall 10045
    //Username=1, S1=0, S2=1, Email=0, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10046()
{
    //Testfall 10046
    //Username=1, S1=0, S2=1, Email=1, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10047()
{
    //Testfall 10047
    //Username=1, S1=0, S2=1, Email=1, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10048()
{
    //Testfall 10048
    //Username=1, S1=0, S2=0, Email=0, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10049()
{
    //Testfall 10049
    //Username=1, S1=1, S2=0, Email=0, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10050()
{
    //Testfall 10050
    //Username=1, S1=1, S2=0, Email=1, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10051()
{
    //Testfall 10051
    //Username=1, S1=1, S2=0, Email=1, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10052()
{
    //Testfall 10052
    //Username=1, S1=1, S2=1, Email=0, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10053()
{
    //Testfall 10053
    //Username=1, S1=1, S2=1, Email=0, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10054()
{
    //Testfall 10054
    //Username=1, S1=1, S2=1, Email=1, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10055()
{
    //Testfall 10055
    //Username=1, S1=1, S2=1, Email=1, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("Irma");
    p.ui->lES2->setText("Irma");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("Irma");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Gültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10056()
{
    //Testfall 10056
    //Username=1, S1=0, S2=0, Email=0, PW=0

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("test");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Feldausgefuellt_10057(){
    //Testfall 20057
    //Username=1, S1=0, S2=0, Email=0, PW=1

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    Password p;
    p.ui->lEUsername->setText("Irma");
    p.ui->lES1->setText("");
    p.ui->lES2->setText("");
    p.ui->Email->setText("Irma");
    p.ui->lEPasswort->setText("test");
    p.on_ButtonCheck_clicked();

    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Ungültige Angaben");

//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

void tst::Abbruch2()
{
    //Testfall 10017
    //Nutzer bricht vorgang ab

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("194.95.108.24");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("kalender");
    db.open();

Password p;
p.on_pushButton_clicked();
QTimer::singleShot(1000, this, SLOT(TimeOut()));


//Aufräumen
QSqlDatabase::removeDatabase("qt_sql_default_connection");}





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    tst t;

    return QTest::qExec(&t, argc, argv);

}

