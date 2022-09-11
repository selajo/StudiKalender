#include <QtTest>
#include <QCoreApplication>

#include "tst_termin_bearbeiten.h"
#include "termin_bearbeiten.cpp"
#include "termin_bearbeiten.h"
#include "ui_termin_bearbeiten.h"
#include "QMessageBox"

/*
 * Author: Elena Schmidmeier
 *
 */

termin_bearbeiten::termin_bearbeiten() {
    msg = "";
}
termin_bearbeiten::~termin_bearbeiten() {

}

void termin_bearbeiten::TimeOut()
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

//Kein Name eingegeben 704
void termin_bearbeiten::test_Termin_kein_Name()
{
        Termin_bearbeiten ter1;
        QTimer::singleShot(4000, this, SLOT(TimeOut()));
        ter1.on_speichern_clicked();

        QVERIFY2(this->msg == "Kein Name eingegeben!", "Titel");


}
//Nutzer gibt Name ein und fügt hinzu 30007
void termin_bearbeiten::test_Termin_Name_eingegeben()
{
        Termin_bearbeiten ter3;
        ter3.ui->Titel->setText("Vorlesung");
        ter3.on_speichern_clicked();
        bool visible= ter3.isVisible();
        QCOMPARE(visible, false);

}
//Nutzer bricht Vorgang ab 30009
void termin_bearbeiten::test_Termin_abbrechen()
{
        Termin_bearbeiten ter;

        ter.on_abbrechen_clicked();
        bool visible= ter.isVisible();
        QCOMPARE(visible, false);

}
//Nutzer klickt auf löschen 30008
void termin_bearbeiten::test_Termin_loeschen()
{
        Termin_bearbeiten ter2;
        QTimer::singleShot(4000, this, SLOT(TimeOut()));
        ter2.on_Termin_loeschen_clicked();
        QVERIFY2(this->msg == "Willst du den Termin wirklich löschen?", "Termin löschen");
        bool visible= ter2.isVisible();
        QCOMPARE(visible, false);

}
/*
702 Nutzer hat Datum nicht eingegeben. Termin nicht verändert. (Hier ist auf die Termin-ID speziell zu testen)
Das ehemalige Datum des Termins wird beibehalten.

703 Nutzer hat Uhrzeiten nicht eingeben. Termin nicht verändert. (Hier ist auf die Termin-ID speziell zu testen)
Die ehemaligen Uhrzeiten des Termins werden beibehalten.

705 Nutzer hat kein gültiges Datum (falscher Datentyp) eingeben. Termin nicht verändert. (Hier ist auf die Termin-ID speziell zu testen)
Da wir das Widget der QDateEdit Klasse verwenden, ist es nicht möglich ein ungültiges Datum einzugeben.

706 Nutzer hat keine gültigen Uhrzeiten eingegeben. Termin nicht verändert. (Hier ist auf die Termin-ID speziell zu testen)
Da wir das Widget der QTimeEdit Klasse verwenden ist es nicht möglich eine ungültige Uhrzeit eingeben.

 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    termin_bearbeiten t;

    return QTest::qExec(&t, argc, argv);

}


//QTEST_APPLESS_MAIN(tst);
