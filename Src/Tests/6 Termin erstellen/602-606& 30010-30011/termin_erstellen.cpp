#include "termin_erstellen.h"
#include "ui_termin_erstellen.h"
//#include "Termin_Klasse.h"
//#include "mainwindow.h"
#include <QMessageBox>
#include <QDate>
#include <QTime>

/*
 * Author: Elena Schmidmeier
 *
 */

Termin_erstellen::Termin_erstellen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Termin_erstellen)
{
    ui->setupUi(this);
    QPixmap calenderLogo("Images/Kalender1.png");
    ui->l1->setPixmap(calenderLogo);
    ui->l2->setPixmap(calenderLogo);
    ui->l3->setPixmap(calenderLogo);
    ui->l4->setPixmap(calenderLogo);
    QDate date= QDate::currentDate();
    QTime time= QTime::currentTime();
    ui->beginn->setTime(time);
    ui->Datum->setDate(date);
    ui->ende->setTime(time.addSecs(3600));
}

Termin_erstellen::~Termin_erstellen()
{
    delete ui;
}

//abbrechen
void Termin_erstellen::on_abbrechen_clicked()
{
    this->close();
}

//neuen Termin hinzufügen
void Termin_erstellen::on_termin_hinzufuegen_clicked()
{
    //NProfil *NP = NProfil::getInstance();

    QString titel, intervall, wiederholung, beschreibung;
    QDate datum;
    QTime beginn, ende, reminder;
    bool erledigt;

    wiederholung=ui->wiederholungen->text();
    reminder=ui->Erinnerung->time();
    beginn=ui->beginn->time();
    ende =ui->ende->time();
    datum= ui->Datum->date();
    titel= ui->Titel->text();
    beschreibung =ui->beschreibung->text();
    int wdh= wiederholung.toInt();



    if(ui->erledigt->isChecked())
        erledigt=true;
    else
        erledigt=false;

    //default Wert für Wiederholungen
    if(wiederholung==" ")
        wdh=0;
    //Wenn kein Titel eingegeben wird
    if(titel==""){
        QMessageBox::warning(this, tr("Titel"), tr("Kein Name eingegeben!"));
    }
    else{
    this->close();/*
        QSqlQuery query;

        int i= NP->idNutzer;     //Die ID vom Profil für den Fremdschlüssel für Termin
        while(wdh!=-1){


            Termin Ter;
            Ter.TerminInsert(query, titel, datum, beginn, ende, beschreibung, reminder,erledigt, wdh , false, i);
            wdh--;
            datum=datum.addDays(+7);

        }*/
    }
}
