#include "deleteprofil.h"
#include "ui_deleteprofil.h"
#include "Nutzerprofil.h"
#include "mainwindow.h"
#include "QMainWindow"
#include <QDialog>
#include <QMessageBox>
#include "Datenbank.h"
#include <QApplication>
#include <QDebug>


/*
 * Author: Irma Krieger
 *
 */
extern NProfil NP;



DeleteProfil::DeleteProfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteProfil)
{
    ui->setupUi(this);
}

DeleteProfil::~DeleteProfil()
{
    delete ui;
}


void DeleteProfil::on_buttonBox_accepted()
{
    //Datenbankverbindung aufbauen
    Datenbank * db= Datenbank::getInstance();
    db->connOpen();


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
        if(NP.ProfilLoeschen(query, passwortAlt, s1, s2))
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

