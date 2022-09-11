#include "pbearbeiten.h"
#include "Nutzerprofil.h"
#include "mainwindow.h"
#include "QMainWindow"
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "deleteprofil.h"
#include <QFileDialog>
#include <QDebug>
#include "ui_pbearbeiten.h"


/*
 * Author: Irma Krieger, Josef Lanzl
 *
 */


PBearbeiten::PBearbeiten(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PBearbeiten)
{
    setWindowFlags(Qt::WindowTitleHint);

    NProfil *NP = NProfil::getInstance();

    ui->setupUi(this);
    connect(ui->ButtonExit, SIGNAL(clicked()), this, SLOT(close()));
    ui->Username->setText(NP->Nutzername);

    QPixmap LogoKlein ("Images/LogoKlein.png");
    ui->LogoKlein->setPixmap(LogoKlein);

    QPixmap calenderLogo("Images/Kalender1.png");
    ui->lbl1->setPixmap(calenderLogo);
    ui->lbl2->setPixmap(calenderLogo);
    ui->lbl3->setPixmap(calenderLogo);
    ui->lbl4->setPixmap(calenderLogo);

    ui->profilePicture->setPixmap(NP->ProfilGetImage().scaled(ui->profilePicture->width(), ui->profilePicture->height(), Qt::KeepAspectRatio));

}

PBearbeiten::~PBearbeiten()
{

}

void PBearbeiten::on_ButtonExit_destroyed()
{

}


void PBearbeiten::on_ButtonProfil_clicked()
{
    NProfil *NP = NProfil::getInstance();

    QString email = ui->email->text();
    QString passwortAlt = ui ->passwortAlt->text();
    QString passwortNeu = ui->passwortNeu->text();

    if(email == "" || passwortAlt == "" || passwortNeu == "")
    {QMessageBox::warning(this, "Profil bearbeiten", "Bitte Benutzerdaten eingeben");}
    else
    {
        if ((email.contains("@") && email.contains(".com"))|| (email.contains("@") && email.contains(".de")))
        {
             NP->ProfilChangeEmail(email);
             NP->ProfilUpdatePasswort(NP->Nutzername, passwortAlt, passwortNeu);
             QMessageBox::information(this, "Profil bearbeiten", "Deine Daten wurden erfolgreich geändert");
             NP->ProfilLaden(NP->Nutzername, passwortNeu);
             this->close();
        }
        else
        {QMessageBox::warning(this, "E-Mail", "Ungültige E-Mail Adresse. Beispiel: maxmustermann@test.de");
            //Fehlermeldung, wenn E-Mail ungültig
        }
    }


}
void PBearbeiten::on_ProfilLoeschen_clicked()
{
    DeleteProfil loeschen;
    loeschen.setModal(true);
    loeschen.exec();
}

void PBearbeiten::on_ProfilbildHochladen_clicked()
{
    NProfil *NP = NProfil::getInstance();

    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("Images (*.JPG)"));
    if(fileNames.size() != 0) {
        QString File = fileNames[0];
        if(File != "") {

            NP->ProfilUploadImage(NP->Nutzername, File);

            ui->profilePicture->setPixmap(NP->ProfilGetImage().scaled(ui->profilePicture->width(), ui->profilePicture->height(), Qt::KeepAspectRatio));
        }
    }
}
