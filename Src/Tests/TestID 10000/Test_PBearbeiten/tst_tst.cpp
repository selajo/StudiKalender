#include "tst_tst.h"

//Alle notwendingen hs und cpps
#include "../../../Code/StartseiteStudikalender/Nutzerprofil.h"
#include "../../../Code/StartseiteStudikalender/Nutzerprofil.cpp"
#include "../../../Code/StartseiteStudikalender/pbearbeiten.h"
#include "../../../Code/StartseiteStudikalender/pbearbeiten.cpp"

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



void tst::Email_wohlgeformt10001()
{
    //Testfall 10001
    // Email ist wohlgeformt (mit @ und .de)
    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    PBearbeiten p;
    p.ui->passwortAlt->setText("test");
    p.ui->passwortNeu->setText("test");
    p.ui->email->setText("irma.krieger@gmx.de");
    p.on_ButtonProfil_clicked();

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Email_wohlgeformt10002()
{
    //Testfall 10002
    // Email ist wohlgeformt (mit @ und .com)
    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    PBearbeiten p;
    p.ui->passwortAlt->setText("test");
    p.ui->passwortNeu->setText("test");
    p.ui->email->setText("irma.krieger@gmx.com");

    p.on_ButtonProfil_clicked();

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

void tst::Email_nichtwohlgeformt10003()
{
    //Testfall 10003
    //Email ist nicht wohlgeformt (ohne @ und mit .de)
    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    PBearbeiten p;
    p.ui->passwortAlt->setText("test");
    p.ui->passwortNeu->setText("test");
    p.ui->email->setText("irmakrieger.de");
    p.on_ButtonProfil_clicked();

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

void tst::Email_nichtwohlgeformt10004()
{    //Testfall 10004
    //Email ist nicht wohlgeformt (ohne @ und ohne .de)
    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    PBearbeiten p;
    p.ui->passwortAlt->setText("test");
    p.ui->passwortNeu->setText("test");
    p.ui->email->setText("irmakrieger");
    p.on_ButtonProfil_clicked();

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");}

void tst::Email_nichtwohlgeformt10005()
{    //Testfall 10005
    //Email ist nicht wohlgeformt (mit @ und ohne .com)

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    PBearbeiten p;
    p.ui->passwortAlt->setText("test");
    p.ui->passwortNeu->setText("test");
    p.ui->email->setText("irma@krieger");
    p.on_ButtonProfil_clicked();

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");}

void tst::Email_nichtwohlgeformt10006()
{    //Testfall 10006
    //Email ist nicht wohlgeformt (ohne @ und mit .com)

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    PBearbeiten p;
    p.ui->passwortAlt->setText("test");
    p.ui->passwortNeu->setText("test");
    p.ui->email->setText("irmakrieger.com");
    p.on_ButtonProfil_clicked();

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");}

void tst::Email_nichtwohlgeformt10007()
{    //Testfall 10007
    //Email ist nicht wohlgeformt (ohne @ und ohne .com)

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    PBearbeiten p;
    p.ui->passwortAlt->setText("test");
    p.ui->passwortNeu->setText("test");
    p.ui->email->setText("irmakriegercom");
    p.on_ButtonProfil_clicked();

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");}

void tst::Email_nichtwohlgeformt10008()
{    //Testfall 10008
    //Email ist nicht wohlgeformt (mit @ und ohne .com)

    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    PBearbeiten p;
    p.ui->passwortAlt->setText("test");
    p.ui->passwortNeu->setText("test");
    p.ui->email->setText("irma@kriegercom");
    p.on_ButtonProfil_clicked();

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");}

void tst::Felder_Leer10009()
{
    //Testfall 10009
        //Keine Felder sind ausgefüllt

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

        PBearbeiten p;
        p.ui->passwortAlt->setText("");
        p.ui->passwortNeu->setText("");
        p.ui->email->setText("");
        p.on_ButtonProfil_clicked();

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10010()
{
    //Testfall 10010
        //email = 1, passwortAlt = 0, passwort Neu = 0


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

        PBearbeiten p;
        p.ui->passwortAlt->setText("");
        p.ui->passwortNeu->setText("");
        p.ui->email->setText("irma.krieger@gmx.de");
        p.on_ButtonProfil_clicked();

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10011()
{
    //Testfall 10011
        //email = 0, passwortAlt = 1, passwort Neu = 0


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

        PBearbeiten p;
        p.ui->passwortAlt->setText("test");
        p.ui->passwortNeu->setText("");
        p.ui->email->setText("");
        p.on_ButtonProfil_clicked();

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10012()
{
    //Testfall 10012
        //email = 0, passwortAlt = 0, passwort Neu = 1


        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

        PBearbeiten p;
        p.ui->passwortAlt->setText("");
        p.ui->passwortNeu->setText("test");
        p.ui->email->setText("");
        p.on_ButtonProfil_clicked();

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
}
void tst::Felder_Leer10013()
{
    //Testfall 10013
        //email = 1, passwortAlt = 1, passwort Neu = 0




        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

        PBearbeiten p;
        p.ui->passwortAlt->setText("test");
        p.ui->passwortNeu->setText("");
        p.ui->email->setText("irma.krieger@gmx.de");
        p.on_ButtonProfil_clicked();

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10014()
{
    //Testfall 10014
        //   email = 1, passwortAlt = 0, passwort Neu = 1

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

        PBearbeiten p;
        p.ui->passwortAlt->setText("");
        p.ui->passwortNeu->setText("test");
        p.ui->email->setText("irma.krieger@gmx.de");
        p.on_ButtonProfil_clicked();

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}
void tst::Felder_Leer10015()
{
    //Testfall 10015
        //email = 0, passwortAlt = 1, passwort Neu = 1

        //setup
                QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName("194.95.108.24");
                db.setUserName("root");
                db.setPassword("root");
                db.setDatabaseName("kalender");
                db.open();

        PBearbeiten p;
        p.ui->passwortAlt->setText("test");
        p.ui->passwortNeu->setText("test");
        p.ui->email->setText("");
        p.on_ButtonProfil_clicked();

        //Aufräumen
        QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

void tst::Abbruch()
{
    //User klickt auf Abbruch Button
    //setup
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("194.95.108.24");
            db.setUserName("root");
            db.setPassword("root");
            db.setDatabaseName("kalender");
            db.open();

    PBearbeiten p;
    p.on_ButtonExit_destroyed();
    QTimer::singleShot(1000, this, SLOT(TimeOut()));
    QVERIFY2(this->msg == "Abbruch", "Abbruch betätigt");

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");



}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    tst t;

    return QTest::qExec(&t, argc, argv);

}

