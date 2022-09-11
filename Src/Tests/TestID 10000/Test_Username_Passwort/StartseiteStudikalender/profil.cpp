#include "profil.h"
#include "ui_profil.h"
#include "pbearbeiten.h"
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"
#include "Datenbank.h"
#include <QPixmap>



/*
 * Author: Elena Schmidmeier, Irma Krieger
 *
 */

extern NProfil NP;

profil::profil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profil)
{
    ui->setupUi(this);
    connect(ui->ButtonExit, SIGNAL(clicked()), this, SLOT(close()));

    ui->Username->setText(NP.Nutzername);
    ui->email->setText(NP.Email);
    Datenbank * db= Datenbank::getInstance();
    db->connOpen();
    QSqlQuery query;
    ui->profilePicture->setPixmap(NP.ProfilGetImage(query).scaled(ui->profilePicture->width(), ui->profilePicture->height(), Qt::KeepAspectRatio));



}

profil::~profil()
{
    delete ui;
}




void profil::on_ButtonExit_destroyed()
{

}

void profil::on_ButtonProfil_clicked()
{
    PBearbeiten change;
    change.setModal(true);
    this->close();
    change.exec();
}
