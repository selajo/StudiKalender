#include "termin_bearbeiten.h"
#include "ui_termin_bearbeiten.h"
#include "ui_tagesansicht.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "Termin_Klasse.h"
#include "QList_Model_AusgabeTagesansicht.h"
/*
 * Author: Elena Schmidmeier
 *
 */

Termin_bearbeiten::Termin_bearbeiten(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Termin_bearbeiten)
{
    ui->setupUi(this);
    //Bilder einsetzen
    QPixmap calenderLogo("Images/Kalender1.png");
    ui->l1->setPixmap(calenderLogo);
    ui->l2->setPixmap(calenderLogo);
    ui->l3->setPixmap(calenderLogo);
    ui->l4->setPixmap(calenderLogo);


}

Termin_bearbeiten::~Termin_bearbeiten()
{
    delete ui;
}
//Terminwerte des ausgewählten Termins einsetzen
void Termin_bearbeiten::setData(const QString &labelText)
{
    QString ID;
    ID=labelText;
    ui->Id->setText(labelText);
    int id= ID.toInt();

    Termin TER;

    TER.TerminwertevonID( id);
    QString titel, beschreibung;
    QDate datum;
    QTime beginn, ende, reminder;
    bool erledigt;    

    titel=TER.TerminName;
    beginn= TER.Beginn;
    ende= TER.Ende;
    datum=TER.Datum;
    reminder=TER.Erinnerung;
    erledigt= TER.Erledigung;
    beschreibung=TER.Beschreibung;
    erledigt=TER.Erledigung;
    ui->ende->setTime(ende);
    ui->beginn->setTime(beginn);
    ui->Datum->setDate(datum);
    ui->Erinnerung->setTime(reminder);
    ui->beschreibung->setText(beschreibung);
    ui->Titel->setText(titel);
    if(erledigt==true)
        ui->erledigt->setChecked(true);

}
//abbrechen
void Termin_bearbeiten::on_abbrechen_clicked()
{
    this->close();
}

// Termin löschen
void Termin_bearbeiten::on_Termin_loeschen_clicked()
{
    QString titel, intervall, beschreibung,ID;
    QDate datum;
    QTime beginn, ende, reminder;

    ID=ui->Id->text();
    reminder=ui->Erinnerung->time();
    beginn=ui->beginn->time();
    ende =ui->ende->time();
    datum= ui->Datum->date();
    titel= ui->Titel->text();
    beschreibung =ui->beschreibung->text();
    int id=ID.toInt();

    QMessageBox messageBox(QMessageBox::Question,
                tr("Termin löschen"),
                tr("Willst du den Termin wirklich löschen?"),
                QMessageBox::Yes | QMessageBox::No,
                this);
        messageBox.setButtonText(QMessageBox::Yes, tr("Ja"));
        messageBox.setButtonText(QMessageBox::No, tr("Nein"));


    int t=messageBox.exec();
    switch(t){
      case QMessageBox::No:
        break;
      case QMessageBox::Yes:
        this->close();


        Termin TER;

        TER.LoescheTermin2(id);

        break;
    }
}
//Termin Bearbeitung speichern
void Termin_bearbeiten::on_speichern_clicked()
{

    QString titel, beschreibung,ID;
    QDate datum;
    QTime beginn, ende, reminder;
    bool erledigt;


    ID=ui->Id->text();
    reminder=ui->Erinnerung->time();
    beginn=ui->beginn->time();
    ende =ui->ende->time();
    datum= ui->Datum->date();
    titel= ui->Titel->text();
    beschreibung =ui->beschreibung->text();

    int id = ID.toInt();


    if(ui->erledigt->isChecked())
        erledigt=true;
    else
        erledigt=false;



    if(titel==""){
        QMessageBox::warning(this, tr("Titel"), tr("Kein Name eingegeben!"));
    }
    else {

    this->close();


    Termin TER;
    TER.TerminwertevonID(id);
    int wdh=TER.Wiederholungen;

    TER.TerminUpdate(id,titel,datum,beginn,ende,beschreibung,reminder, erledigt, wdh);}

}



