#include "tst_tst.h"

//Alle notwendingen hs und cpps
#include "../../../Code/StartseiteStudikalender/Nutzerprofil.h"
#include "../../../Code/StartseiteStudikalender/Nutzerprofil.cpp"
#include "../../../Code/StartseiteStudikalender/deleteprofil.h"
#include "../../../Code/StartseiteStudikalender/deleteprofil.cpp"

#include <QWidget>




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
void tst::Abbruch()
{
    //User klickt auf Abbruch Button
    //Testfall 10058

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    DeleteProfil p;
    p.on_ButtonExit_destroyed();
    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Abbruch", "Abbruch betätigt");

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");



}


void tst::Felder_Leer10059()
{
    //Testfall 10059
        //Keine Felder sind ausgefüllt

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

        DeleteProfil p;
        p.ui->passwortAlt->setText("");
        p.ui->s1->setText("");
        p.ui->s2->setText("");
        p.on_ButtonLoeschen_clicked();
        QTimer::singleShot(1000, this, SLOT(TimeOut()));
        QVERIFY2(this->msg == "Abbruch", "Abbruch betätigt");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10060()
{
    //Testfall 10060
        //PW = 1, S1 = 0, S2 = 0


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                DeleteProfil p;
                p.ui->passwortAlt->setText("test");
                p.ui->s1->setText("");
                p.ui->s2->setText("");
                p.on_ButtonLoeschen_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Felder", "Falsche Eingabe");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10061()
{
    //Testfall 10061
        //PW = 0, S1 = 1, S2 = 0


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                DeleteProfil p;
                p.ui->passwortAlt->setText("");
                p.ui->s1->setText("test");
                p.ui->s2->setText("");
                p.on_ButtonLoeschen_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Felder", "Falsche Eingabe");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10062()
{
    //Testfall 10062
        //PW= 0, S1 = 0, S2 = 1


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                DeleteProfil p;
                p.ui->passwortAlt->setText("");
                p.ui->s1->setText("");
                p.ui->s2->setText("test");
                p.on_ButtonLoeschen_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Felder", "Falsche Eingabe");
        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
}
void tst::Felder_Leer10063()
{
    //Testfall 10063
        //PW = 1, S1 = 1, S2 = 0




        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                DeleteProfil p;
                p.ui->passwortAlt->setText("test");
                p.ui->s1->setText("test");
                p.ui->s2->setText("");
                p.on_ButtonLoeschen_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Felder", "Falsche Eingabe");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10064()
{
    //Testfall 10064
        // PW = 1, S1 = 0, S2 = 1

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                DeleteProfil p;
                p.ui->passwortAlt->setText("test");
                p.ui->s1->setText("");
                p.ui->s2->setText("test");
                p.on_ButtonLoeschen_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Felder", "Falsche Eingabe");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10065()
{
    //Testfall 10065
        //PW = 0, S1 = 1, S2 = 1

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                DeleteProfil p;
                p.ui->passwortAlt->setText("");
                p.ui->s1->setText("test");
                p.ui->s2->setText("test");
                p.on_ButtonLoeschen_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Felder", "Falsche Eingabe");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    tst t;

    return QTest::qExec(&t, argc, argv);

}

