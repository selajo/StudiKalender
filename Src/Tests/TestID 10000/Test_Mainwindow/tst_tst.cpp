#include "tst_tst.h"

//Alle notwendingen hs und cpps
#include "StartseiteStudikalender/Nutzerprofil.h"
#include "StartseiteStudikalender/Nutzerprofil.cpp"
#include "StartseiteStudikalender/mainwindow.h"
#include "StartseiteStudikalender/mainwindow.cpp"

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
void tst::Felder_ausgefuellt10066()
{
    //User wird auf Startseite gelenkt
    //Testfall 10066

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

            //MaxMuster ist speziell für die Tests erstellt worden
              NProfil p;
            //Max muss angemeldet sein
              p.ProfilLaden("MaxMuster", "Test123!");



    MainWindow s;
    s.ui->lEUsername->setText("MaxMuster");
    s.ui->lEPasswort->setText("Test123!");
    s.on_pushButtonLogIn_clicked();
    QTimer::singleShot(1000, this, SLOT(TimeOut()));


    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");



}


void tst::Felder_Leer10067()
{
    //Testfall 10067
        //Username =falsch; PW=Richtig; Error

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                //MaxMuster ist speziell für die Tests erstellt worden
                  NProfil p;
                //Max muss angemeldet sein
                  p.ProfilLaden("MaxMuster", "Test123!");


                MainWindow s;
                s.ui->lEUsername->setText("Max");
                s.ui->lEPasswort->setText("Test123!");
                s.on_pushButtonLogIn_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));

        QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Abbruch betätigt");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

void tst::Felder_Leer10068()
{
    //Testfall 10068
        //Username = richtig, PW = falsch; Error



        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();
                //MaxMuster ist speziell für die Tests erstellt worden
                  NProfil p;
                //Max muss angemeldet sein
                  p.ProfilLaden("MaxMuster", "Test123!");

                MainWindow s;
                s.ui->lEUsername->setText("MaxMuster");
                s.ui->lEPasswort->setText("Irma");
                s.on_pushButtonLogIn_clicked();

                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Falsche Eingabe");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10069()
{
    //Testfall 10069
        //Username = falsch, PW = falsch; Error



        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();
                //MaxMuster ist speziell für die Tests erstellt worden
                  NProfil p;
                //Max muss angemeldet sein
                  p.ProfilLaden("MaxMuster", "Test123!");

                MainWindow s;
                s.ui->lEUsername->setText("Irma");
                s.ui->lEPasswort->setText("Irma");
                s.on_pushButtonLogIn_clicked();
                QTimer::singleShot(1000, this, SLOT(TimeOut()));

                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Falsche Eingabe");
        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
}
void tst::Felder_Leer10070()
{
    //Testfall 10070
        //Benutzername = 0, PW= 0




        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                MainWindow p;
                p.ui->lEUsername->setText("");
                p.ui->lEPasswort->setText("");
                p.on_pushButtonLogIn_clicked();

                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Falsche Eingabe");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10071()
{
    //Testfall 10071
        // Benutzername = 0, PW= 1
        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                MainWindow p;
                p.ui->lEUsername->setText("");
                p.ui->lEPasswort->setText("Irma");
                p.on_pushButtonLogIn_clicked();

                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Falsche Eingabe");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10072()
{
    //Testfall 10072
        //Benutzername = 1, PW= 0

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

                MainWindow p;
                p.ui->lEUsername->setText("Irma");
                p.ui->lEPasswort->setText("");
                p.on_pushButtonLogIn_clicked();

                QTimer::singleShot(1000, this, SLOT(TimeOut()));
                QVERIFY2(this->msg == "Bitte Benutzerdaten eingeben", "Falsche Eingabe");

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    tst t;

    return QTest::qExec(&t, argc, argv);

}

