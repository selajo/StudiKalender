#include "tst_studifach.h"
#include "studifaecher.cpp"
#include "studifaecher.h"
#include "ui_studifaecher.h"
#include "QMessageBox"


/*
 * Author: Elena Schmidmeier
 *
 */


studifach::studifach() {
    msg = "";
}
studifach::~studifach() {

}

void studifach::TimeOut()
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

//Keine Daten eingegeben 902
void studifach::test_Studifach_kein_Name()
{
        studifaecher fach1;
        fach1.ui->name->setText("");
        QTimer::singleShot(4000, this, SLOT(TimeOut()));
        fach1.on_speichern_clicked();
        QVERIFY2(this->msg == "Kein Name eingegeben!", "Titel");

}
//Name eingegeben, Studienfach hinzugefügt 30005
void studifach::test_Studifach_Name_eingegeben()
{
        studifaecher fach;
        fach.ui->name->setText("MA1");
        fach.on_speichern_clicked();
        QString name= fach.ui->name->text();
        int ects=fach.ui->ects->value();
        int sws=fach.ui->sws->value();
        int stunden=fach.ui->stunden->value();
        QCOMPARE(name, " ");
        QCOMPARE(sws, 0);
        QCOMPARE(ects, 0);
        QCOMPARE(stunden, 0);

}
//Nutzer bricht ab 30006
void studifach::test_Studifach_abbrechen()
{
        studifaecher fach2;

        fach2.on_abbrechen_clicked();
        bool visible= fach2.isVisible();
        QCOMPARE(visible, false);

}
/* 903 Nutzer hat keine positive ganze Zahl für ECTS eingegeben. Warnung ausgeben. Studienfach nicht der Datenbank zugewiesen.
Da wir die Spinbox der QSpinBox Klasse verwenden und diese das default minimum 0 hat, kann keine negative Zahl eingegeben werden, außerdem werden per default nur Integer der Basis 10 akzeptiert 
*/
/* 904 Nutzer hat keine positive Ganzzahl für SWS eingegeben. Warnung ausgeben. Studienfach nicht der Datenbank zugewiesen.
Da wir die Spinbox der QSpinBox Klasse verwenden und diese das default minimum 0 hat, kann keine negative Zahl eingegeben werden, außerdem werden per default nur Integer der Basis 10 akzeptiert 
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    studifach t;

    return QTest::qExec(&t, argc, argv);

}


//QTEST_APPLESS_MAIN(tst);
