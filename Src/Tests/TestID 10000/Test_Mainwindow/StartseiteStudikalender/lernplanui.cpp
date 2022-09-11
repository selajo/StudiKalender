#include "lernplanui.h"
#include "ui_lernplanui.h"
#include "Lernplan.h"
#include <QMessageBox>

//Author: Josef Lanzl; UI-Gestaltung: Elena Schmidmeier
//Quellen: Zur UI-Erstellung: Code von Team-Kollegen

lernplanUI::lernplanUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lernplanUI)
{
    ui->setupUi(this);
    QPixmap calenderLogo("Images/Kalender1.png");
    ui->lbl1->setPixmap(calenderLogo);
    ui->lbl2->setPixmap(calenderLogo);
    ui->lbl3->setPixmap(calenderLogo);

    QDate Date = QDate::currentDate().addDays(6);
    ui->EndDatum->setDate(Date);

}

lernplanUI::~lernplanUI()
{
    delete ui;
}

void lernplanUI::on_Loeschen_clicked()
{
    NProfil *NP = NProfil::getInstance();

    Kalender k;
    if(k.CheckLernplan(NP->idNutzer)) {
        Lernplan l;
        l.LernplanLoeschen(NP->idNutzer);
        QMessageBox::information(this, "Lernplan löschen", "Lernplan erfolgreich gelöscht.");
    }
    else {
        QMessageBox::warning(this, "Lernplan löschen", "Es existiert noch kein Lernplan.");
    }
    this->close();
}

void lernplanUI::on_abbrechen_clicked()
{
    this->close();
}

void lernplanUI::on_ok_clicked()
{
    QDate Ende = ui->EndDatum->date();
    Lernplan l;
    l.EndDatum = Ende;
    NProfil *NP = NProfil::getInstance();

    if(!l.checkEndDatum()) {
        QMessageBox::information(this, "Lernplan", "Der Lernplan arbeitet wochenweise. Bitte ein Datum mit Ziel > heute + 6 eingeben!");
    }
    else {

        if(!l.LernplanErstellenStart(NP->idNutzer)) {
            if(l.Studienfaecher[0]._Eigenstunden == -1) {
                QMessageBox::information(this, "Lernplan", "Du musst vorher noch Studienfächer hinzufügen!");
            }
            else {
                QMessageBox::information(this, "Lernplan", "In der Woche mit dem Datum " + l.AktuelleWoche.toString() + " gibt es keinen Platz für den Lernplan."
                                                                                                                        "Bitte Termine bearbeiten!" +
                                         ((l.AktuelleWoche <= QDate::currentDate().addDays(6)) ? "" : "Bis zu diesem Datum wurde schon mal ein Lernplan erstellt."));
            }
        }
        else {
            QMessageBox::information(this, "Lernplan", "Lernplan wurde erfolgreich erstellt. Du kannst die Termine auch noch bearbeiten, falls dir doch noch wichtige Termine einfallen!");
        }
    }
    this->close();


}
