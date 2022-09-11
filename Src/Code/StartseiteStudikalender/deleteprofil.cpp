#include "deleteprofil.h"
#include "ui_deleteprofil.h"
#include "Nutzerprofil.h"
#include "mainwindow.h"
#include "QMainWindow"
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>


/*
 * Author: Irma Krieger
 *
 */



DeleteProfil::DeleteProfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteProfil)
{
    ui->setupUi(this);

    QPixmap calenderLogo("Images/Kalender1.png");
    ui->lbl1->setPixmap(calenderLogo);
    ui->lbl2->setPixmap(calenderLogo);
    ui->lbl3->setPixmap(calenderLogo);
    ui->lbl4->setPixmap(calenderLogo);

    QPixmap LogoKlein ("Images/LogoKlein.png");
    ui->LogoKlein->setPixmap(LogoKlein);

    NProfil *NP = NProfil::getInstance();
    ui->profilePicture->setPixmap(NP->ProfilGetImage().scaled(ui->profilePicture->width(), ui->profilePicture->height(), Qt::KeepAspectRatio));

    connect(ui->ButtonExit, SIGNAL(clicked()), this, SLOT(close()));
}

DeleteProfil::~DeleteProfil()
{
    delete ui;
}

void DeleteProfil::on_ButtonExit_destroyed()
{

}

void DeleteProfil::on_ButtonLoeschen_clicked()
{
    NProfil *NP = NProfil::getInstance();

    QSqlQuery query;
    NProfil np;

    QString passwortAlt = ui ->passwortAlt->text();
    QString s1 = ui->s1->text();
    QString s2 = ui->s2->text();

    QMessageBox msgBox;
    msgBox.setWindowTitle("Profil löschen");
    msgBox.setText("Möchtest du wirklich dein Profil löschen?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes)
    {

        if(passwortAlt == "" || s1 == "" || s2 == "")
        {
            QMessageBox::warning(this, "Profil löschen", "Bitte Benutzerdaten eingeben");


        }

        else if(NP->ProfilLoeschen(passwortAlt, s1, s2))
        {QMessageBox::information(this, "Profil löschen", "Dein Profil wird gelöscht");
        qApp->closeAllWindows();
        qApp->quit();}

        else
        {
        QMessageBox::information(this, "Fehler", "Deine Daten stimmen nicht überein. Das Fenster wird jetzt geschlossen");
        this->hide();
        }


    }
    else
    {
      QMessageBox::information(this, "Abbruch", "Vorgang abgebrochen");
      this->close();
    }
}
