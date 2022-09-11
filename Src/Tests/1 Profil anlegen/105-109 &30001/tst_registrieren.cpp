#include "tst_registrieren.h"
#include "registrieren.cpp"
#include "registrieren.h"
#include "ui_registrieren.h"
#include "QMessageBox"

/*
 * Author: Elena Schmidmeier
 *
 */

tst_registrieren::tst_registrieren() {
    msg = "";
}
tst_registrieren::~tst_registrieren() {

}

void tst_registrieren::TimeOut()
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


// 105 Keine Daten eingegeben
void tst_registrieren::test_Registrieren_keine_Daten()
{
        Registrieren reg;
        QTimer::singleShot(4000, this, SLOT(TimeOut()));
        reg.on_Registrieren_2_clicked();
        QVERIFY2(this->msg == "Nicht alle Felder ausgefüllt!", "Fehler");

}
//106 Nutzer geht zurück zum Login/ bricht den Vorgang ab
void tst_registrieren::test_Registrieren_login_zurueck()
{
        Registrieren reg;

        reg.on_login_clicked();
        bool visible= reg.isVisible();
        QCOMPARE(visible, false);

}

// 107 gültige EMail
void tst_registrieren::test_Registrieren_gueltige_EMail()
{

    Registrieren reg;
    reg.ui->LEs1->setText("Sicherheitsfrage 1");
    reg.ui->LEs2->setText("Sicherheitsfrage 2");
    reg.ui->LEUsername->setText("Name");
    reg.ui->LEPasswort->setText("Passwort");
    reg.ui->LEPasswortwdh->setText("Passwort");
    reg.ui->LEEMail->setText("email@web.de");

    QTimer::singleShot(4000, this, SLOT(TimeOut()));
    reg.on_Registrieren_2_clicked();
    QVERIFY2(this->msg == "Ihr Login wird vorbereitet!", "Login");


    bool registr;
    registr= reg.isVisible();
    QCOMPARE(registr,false);



}

//108 ungültige EMail
void tst_registrieren::test_Registrieren_ungueltige_EMail()
{
    Registrieren reg;

    reg.ui->LEs1->setText("Sicherheitsfrage 1");
    reg.ui->LEs2->setText("Sicherheitsfrage 2");
    reg.ui->LEUsername->setText("Name");
    reg.ui->LEPasswort->setText("Passwort");
    reg.ui->LEPasswortwdh->setText("Passwort");
    reg.ui->LEEMail->setText("email");

    QTimer::singleShot(4000, this, SLOT(TimeOut()));
    reg.on_Registrieren_2_clicked();
    QVERIFY2(this->msg == "Keine gültige E-Mail Adresse!", "Fehler");

}
// 109 Passwörter stimmen nicht überein
void tst_registrieren::test_Registrieren_Passwort_ungleich()
{
    Registrieren reg;

    reg.ui->LEs1->setText("Sicherheitsfrage 1");
    reg.ui->LEs2->setText("Sicherheitsfrage 2");
    reg.ui->LEUsername->setText("Name");
    reg.ui->LEPasswort->setText("Passwort");
    reg.ui->LEPasswortwdh->setText("Passwort _wiederholen");
    reg.ui->LEEMail->setText("email@web.de");

    QTimer::singleShot(4000, this, SLOT(TimeOut()));
    reg.on_Registrieren_2_clicked();
    QVERIFY2(this->msg == "Passwörter stimmen nicht überein!", "Fehler");

}

//30001 Nutzer schließt Programm
void tst_registrieren::test_Registrieren_exit()
{
        Registrieren reg;

        reg.on_exit_clicked();
        bool visible= reg.isVisible();
        QCOMPARE(visible, false);

}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    tst_registrieren t;

    return QTest::qExec(&t, argc, argv);

}


//QTEST_APPLESS_MAIN(tst);
