#include "pbearbeiten.h"
#include "ui_pbearbeiten.h"
#include "Nutzerprofil.h"
#include "mainwindow.h"
#include "QMainWindow"
#include <QDialog>
#include <QMessageBox>
#include "Datenbank.h"
#include <QApplication>
#include <QDebug>
#include "deleteprofil.h"

/*
 * Author: Irma Krieger
 *
 */
extern NProfil NP;



PBearbeiten::PBearbeiten(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PBearbeiten)
{
    ui->setupUi(this);
    connect(ui->ButtonExit, SIGNAL(clicked()), this, SLOT(close()));
    ui->Username->setText(NP.Nutzername);
}

PBearbeiten::~PBearbeiten()
{
    delete ui;
}

void PBearbeiten::on_ButtonExit_destroyed()
{

}


void PBearbeiten::on_ButtonProfil_clicked()
{

    //Datenbankverbindung aufbauen
    Datenbank * db= Datenbank::getInstance();
    db->connOpen();


    QSqlQuery query;
    NProfil np;


    QString email = ui->email->text();
    QString passwortAlt = ui ->passwortAlt->text();
    QString passwortNeu = ui->passwortNeu->text();

   NP.ProfilChangeEmail(query, email);
   NP.ProfilUpdatePasswort(query, NP.Nutzername, passwortAlt, passwortNeu);
   QMessageBox::information(this, "Profil bearbeiten", "Deine Daten wurden erfolgreich geändert");
   this->close();


}
void PBearbeiten::on_ProfilLoeschen_clicked()
{
    DeleteProfil loeschen;
    loeschen.setModal(true);
    loeschen.exec();
}
