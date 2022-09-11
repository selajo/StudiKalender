#include <QtTest>
#include <QCoreApplication>

#include "tst_termin_erstellen.h"
#include "ui_termin_erstellen.h"
#include "termin_erstellen.cpp"
#include "termin_erstellen.h"
#include "QMessageBox"

/*
 * Author: Elena Schmidmeier
 *
 */

termin_erstellen::termin_erstellen() {
    msg = "";
}
termin_erstellen::~termin_erstellen() {

}

void termin_erstellen::TimeOut()
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

//Kein Name eingegeben 604
void termin_erstellen::test_Termin_kein_Name()
{
        Termin_erstellen ter1;
        QTimer::singleShot(4000, this, SLOT(TimeOut()));
        ter1.on_termin_hinzufuegen_clicked();

        QVERIFY2(this->msg == "Kein Name eingegeben!", "Titel");


}
//Nutzer gibt Name ein und fügt hinzu 30010
void termin_erstellen::test_Termin_Name_eingegeben()
{
        Termin_erstellen ter3;
        ter3.ui->Titel->setText("Vorlesung");
        ter3.on_termin_hinzufuegen_clicked();
        bool visible= ter3.isVisible();
        QCOMPARE(visible, false);

}
//Nutzer bricht Vorgang ab 30011
void termin_erstellen::test_Termin_abbrechen()
{
        Termin_erstellen ter;

        ter.on_abbrechen_clicked();
        bool visible= ter.isVisible();
        QCOMPARE(visible, false);

}
/*
 * 602 Datum nicht eingegeben. Termin nicht hinzugefügt
Wir haben es so gemacht, dass als default Datum des Widgtes der QDateEdit Klasse das aktuelle Datum steht, wenn der Nutzer nichts daran ändert wird dieses gespeichert.

603 Uhrzeit nicht angegeben. Termin nicht hinzugefügt
Wir haben es so gemacht, dass als default Zeit des Widgtes der QTimeEdit Klasse bei Beginn die aktuelle Zeit und bei Ende die aktuelle Zeit+1Stunde steht, wenn der Nutzer nichts daran ändert werden diese Daten gespeichert.

605 Nutzer hat kein gültiges Datum (falscher Datentyp) eingeben. Termin nicht hinzugefügt.
Da wir das Widget der QDateEdit Klasse verwenden, ist es nicht möglich ein ungültiges Datum einzugeben.

606 Nutzer hat keine gültigen Uhrzeiten eingegeben. Termin nicht hinzugefügt.
Da wir das Widget der QTimeEdit Klasse verwenden ist es nicht möglich eine ungültige Uhrzeit eingeben.

 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    termin_erstellen t;

    return QTest::qExec(&t, argc, argv);

}


//QTEST_APPLESS_MAIN(tst);
