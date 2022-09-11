#include "termin_bearbeiten.h"
#include "ui_termin_bearbeiten.h"
#include "ui_tagesansicht.h"
#include <QMessageBox>
#include "Datenbank.h"
#include "mainwindow.h"
#include "Termin_Klasse.h"
#include "QList_Model_AusgabeTagesansicht.h"
/*
 * Author: Elena Schmidmeier
 *
 */
extern NProfil NP;
Termin_bearbeiten::Termin_bearbeiten(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Termin_bearbeiten)
{
    ui->setupUi(this);


}

Termin_bearbeiten::~Termin_bearbeiten()
{
    delete ui;
}

void Termin_bearbeiten::setData(const QString &labelText)
{
    QString ID;
    ID=labelText;
    ui->Id->setText(labelText);
    int id= ID.toInt();

    Termin TER;
    Datenbank * db= Datenbank::getInstance();
    db->connOpen();
    QSqlQuery query;


    TER.TerminwertevonID(query, id);
    QString titel, wiederholung, beschreibung;
    QDate datum;
    QTime beginn, ende, reminder;
    //int wdh;
    bool erledigt;
    //wdh=TER.wiederholung;
    //wiederholung=QString::number(wdh);

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
    db->connClose();

}
//abbrechen
void Termin_bearbeiten::on_abbrechen_clicked()
{
    this->close();
}

// Termin löschen
void Termin_bearbeiten::on_Termin_loeschen_clicked()
{
    QString titel, intervall, wiederholung, beschreibung,ID;
    QDate datum;
    QTime beginn, ende, reminder;
    bool erledigt;

    ID=ui->Id->text();
    wiederholung=ui->wiederholungen->text();
    reminder=ui->Erinnerung->time();
    beginn=ui->beginn->time();
    ende =ui->ende->time();
    datum= ui->Datum->date();
    titel= ui->Titel->text();
    beschreibung =ui->beschreibung->text();
    wiederholung.toInt();
    int id=ID.toInt();

    if(ui->erledigt->isChecked())
        erledigt=true;
    else
        erledigt=false;

    QMessageBox messageBox(QMessageBox::Question,
                tr("Termin löschen"),
                tr("Wollen Sie den Termin wirklich löschen?"),
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

        Datenbank * db= Datenbank::getInstance();
        db->connOpen();
        QSqlQuery query;

        Termin TER;

        TER.LoescheTermin2(query,id);

        db->connClose();

        break;
    }
}
//Termin Bearbeitung speichern
void Termin_bearbeiten::on_speichern_clicked()
{
    //Terminänderung speichern
    QString titel, wiederholung, beschreibung,ID;
    QDate datum;
    QTime beginn, ende, reminder;
    bool erledigt;

    ID=ui->Id->text();
    wiederholung=ui->wiederholungen->text();
    reminder=ui->Erinnerung->time();
    beginn=ui->beginn->time();
    ende =ui->ende->time();
    datum= ui->Datum->date();
    titel= ui->Titel->text();
    beschreibung =ui->beschreibung->text();
    int wdh=wiederholung.toInt();

    int id = ID.toInt();


    if(ui->erledigt->isChecked())
        erledigt=true;
    else
        erledigt=false;

    //default Wert für Wiederholungen
    if(wiederholung==" ")
        wdh=0;

    if(titel==" "){
        QMessageBox::warning(this, tr("Titel"), tr("Kein Name eingegeben!"));
    }

    this->close();

    Datenbank * db= Datenbank::getInstance();
    db->connOpen();
    QSqlQuery query;

    Termin TER;

    TER.TerminUpdate(query,id,titel,datum,beginn,ende,beschreibung,reminder, erledigt);

    db->connClose();
    /*
     * speichere alte wdh in int
     * vergleiche alten und neuen wert
     * if(altwdh!=wdh){
     * while(altwdh!=-1){
            Termin Ter; alte Termindaten!!!
            Ter.TerminDelete(query, titel, datum, beginn, ende, beschreibung, reminder,erledigt, false, i);
            altwdh--;
            datum=datum.addDays(+7);

        }
        while(wdh!=-1){
            Termin Ter; neue Termindaten!!!
            Ter.TerminDelete(query, titel, datum, beginn, ende, beschreibung, reminder,erledigt, false, i);
            wdh--;
            datum=datum.addDays(+7);
        }
     */
}


