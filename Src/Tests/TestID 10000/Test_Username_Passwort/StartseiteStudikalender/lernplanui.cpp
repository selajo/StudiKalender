#include "lernplanui.h"
#include "ui_lernplanui.h"
#include "Lernplan.h"
#include <QMessageBox>

//Author: Josef Lanzl

extern NProfil NP;

lernplanUI::lernplanUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lernplanUI)
{
    ui->setupUi(this);

    QDate Date = QDate::currentDate().addDays(6);
    ui->EndDatum->setDate(Date);

}

lernplanUI::~lernplanUI()
{
    delete ui;
}

void lernplanUI::on_buttonBox_accepted()
{
    QDate Ende = ui->EndDatum->date();


    Lernplan l;
    l.EndDatum = Ende;

    Datenbank * db = Datenbank::getInstance();
    db->connOpen();
    QSqlQuery Query;

    if(!l.checkEndDatum()) {
        QMessageBox::information(this, "Lernplan", "Der Lernplan arbeitet wochenweise. Bitte ein Datum mit Ziel > heute + 6 eingeben!");
    }
    else {

        if(!l.LernplanErstellenStart(Query, NP.idNutzer)) {
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
}

void lernplanUI::on_Loeschen_clicked()
{
    Datenbank * db = Datenbank::getInstance();
    db->connOpen();
    QSqlQuery Query;

    Lernplan l;
    if(l.CheckLernplan(Query, NP.idNutzer)) {
        l.LernplanLoeschen(Query, NP.idNutzer);
        QMessageBox::information(this, "Lernplan löschen", "Lernplan erfolgreich gelöscht.");
    }
    else {
        QMessageBox::warning(this, "Lernplan löschen", "Es existiert noch kein Lernplan.");
    }
}
