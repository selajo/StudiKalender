#include <QtTest>
#include <QCoreApplication>

#include "tst_studienfach_bearbeiten.h"
#include "studifaecher_verwalten.cpp"
#include "studifaecher_verwalten.h"
#include "ui_studifaecher_verwalten.h"
#include "QMessageBox"

/*
 * Author: Elena Schmidmeier
 *
 */


studienfach_bearbeiten::studienfach_bearbeiten() {
    msg = "";
}
studienfach_bearbeiten::~studienfach_bearbeiten() {

}

void studienfach_bearbeiten::TimeOut()
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

//Kein Name eingegeben 1002
void studienfach_bearbeiten::test_Studifach_kein_Name()
{
        Studifaecher_verwalten fach;
        QTimer::singleShot(4000, this, SLOT(TimeOut()));
        fach.on_speichern_clicked();

        QVERIFY2(this->msg == "Kein Name eingegeben!", "Titel");


}
//Nutzer gibt Name ein und fügt hinzu 30004
void studienfach_bearbeiten::test_Studifach_Name_eingegeben()
{
        Studifaecher_verwalten fach1;
        fach1.ui->name->setText("MA1");
        fach1.on_speichern_clicked();
        bool visible= fach1.isVisible();
        QCOMPARE(visible, false);

}
//Nutzer bricht Vorgang ab 30002
void studienfach_bearbeiten::test_Studifach_abbrechen()
{
        Studifaecher_verwalten fach2;

        fach2.on_abbrechen_clicked();
        bool visible= fach2.isVisible();
        QCOMPARE(visible, false);

}
//Nutzer klickt auf löschen 30003
void studienfach_bearbeiten::test_Studifach_loeschen()
{
        Studifaecher_verwalten fach3;
        QTimer::singleShot(4000, this, SLOT(TimeOut()));
        fach3.on_loeschen_clicked();
        QVERIFY2(this->msg == "Willst du das Studienfach wirklich löschen?", "Studienfach löschen");
        bool visible= fach3.isVisible();
        QCOMPARE(visible, false);

}
/* 1003 Nutzer hat keine positive Ganzzahl für ECTS eingegeben. Studienfach wurde in der Datenbank nicht verändert.
 * 	Da wir die Spinbox der QSpinBox Klasse verwenden und diese das default Minimum 0 hat, kann keine negative Zahl eingegeben werden, außerdem werden per default nur Integer der Basis 10 akzeptiert.
*/
/* 1004 Nutzer hat keine positive Ganzzahl für SWS eingegeben. Studienfach wurde in der Datenbank nicht verändert.
 * 	Da wir die Spinbox der QSpinBox Klasse verwenden und diese das default Minimum 0 hat, kann keine negative Zahl eingegeben werden, außerdem werden per default nur Integer der Basis 10 akzeptiert
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    studienfach_bearbeiten t;

    return QTest::qExec(&t, argc, argv);

}


//QTEST_APPLESS_MAIN(tst);
