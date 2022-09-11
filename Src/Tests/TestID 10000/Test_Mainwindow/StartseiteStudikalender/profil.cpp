#include "profil.h"
#include "ui_profil.h"
#include "pbearbeiten.h"
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"
#include <QPixmap>



/*
 * Author: Irma Krieger
 *
 */

profil::profil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profil)
{
    setWindowFlags(Qt::WindowTitleHint);

    ui->setupUi(this);

    connect(ui->pushExit, SIGNAL(clicked()), this, SLOT(close()));

    QPixmap LogoKlein ("Images/LogoKlein.png");
    ui->LogoKlein->setPixmap(LogoKlein);

    QPixmap calenderLogo("Images/Kalender1.png");
    ui->lbl1->setPixmap(calenderLogo);
    ui->lbl2->setPixmap(calenderLogo);
    ui->lbl3->setPixmap(calenderLogo);
    ui->lbl4->setPixmap(calenderLogo);

    NProfil *NP = NProfil::getInstance();

    //Ausgabe Nutzerdaten bei Profilansicht
    ui->Username->setText(NP->Nutzername);
    ui->email->setText(NP->Email);

    ui->profilePicture->setPixmap(NP->ProfilGetImage().scaled(ui->profilePicture->width(), ui->profilePicture->height(), Qt::KeepAspectRatio));
}

profil::~profil()
{
    delete ui;
}


void profil::on_ButtonProfil_clicked()
{
    PBearbeiten change;
    change.setModal(true);
    this->close();
    change.exec();
}


void profil::on_pushExit_destroyed()
{

}
