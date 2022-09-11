#include "studifaecher_verwalten.h"
#include "ui_studifaecher_verwalten.h"
#include "Studienfach_Klasse.h"
#include <QMessageBox>
#include "QList_Model_FuerAusgabeStudienfaecher.h"

/*
 * Author: Elena Schmidmeier
 *
 */

Studifaecher_verwalten::Studifaecher_verwalten(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Studifaecher_verwalten)
{
    ui->setupUi(this);
    QPixmap calenderLogo("Images/Kalender1.png");
    ui->l1->setPixmap(calenderLogo);
    ui->l2->setPixmap(calenderLogo);
    ui->l3->setPixmap(calenderLogo);
    ui->l4->setPixmap(calenderLogo);
}

Studifaecher_verwalten::~Studifaecher_verwalten()
{
    delete ui;
}

void Studifaecher_verwalten::on_abbrechen_clicked()
{
    this->close();
}

void Studifaecher_verwalten::on_loeschen_clicked()
{
    //loeschen
    QString ID;
    ID=ui->ID->text();
    int id= ID.toInt();

    QMessageBox messageBox(QMessageBox::Question,
                tr("Studienfach löschen"),
                tr("Willst du das Studienfach wirklich löschen?"),
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

        Studienfach STD;

        QSqlQuery query;

        STD.DeleteStudienfach(query,id);

        break; }

}

void Studifaecher_verwalten::on_speichern_clicked()
{
    QString ID;
    QString Name, Ects, Sws, Stunden;
    Name= ui->name->text();
    Ects=ui->ects->text();
    Sws=ui->sws->text();
    Stunden=ui->stunden->text();
    int ects=Ects.toInt();
    int stunden=Stunden.toInt();
    int sws=Sws.toInt();
    ID=ui->ID->text();
    int id= ID.toInt();

    if(Name==""){
        QMessageBox::warning(this, tr("Titel"), tr("Kein Name eingegeben!"));
    }
    else{

    this->close();

    QSqlQuery query;

    Studienfach fach;

    fach.UpdateStudienfach(query,id,Name,ects,sws,stunden);}
}

void Studifaecher_verwalten::setData_fach(const QString &labelText)
{
   QString ID;
   ID=labelText;
   ui->ID->setText(labelText);
   int id= ID.toInt();

   Studienfach FA;

   QSqlQuery query;

   FA.StudienfachwertevonID(query, id);

   QString name, Ects, Sws,Stunden;
   int ects, sws, stunden;
   ects=FA._ECTS;
   sws=FA._SWS;
   stunden=FA._Eigenstunden;
   name=FA._Bezeichnung;
   Ects=QString::number(ects);
    ui->name->setText(name);
    ui->sws->setValue(sws);
    ui->ects->setValue(ects);
    ui->stunden->setValue(stunden);
}

