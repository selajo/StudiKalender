#include "registrieren.h"
#include "ui_registrieren.h"
#include <QMessageBox>
#include "tagesansicht.h"
#include "mainwindow.h"
#include "Nutzerprofil.h"
#include "Datenbank.h"

/*
 * Author: Elena Schmidmeier
 *
 */

extern NProfil NP;

Registrieren::Registrieren(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrieren)
{
    ui->setupUi(this);
}

Registrieren::~Registrieren()
{
    delete ui;
}

//Registrieren Button betätigt
void Registrieren::on_Registrieren_2_clicked()
{
    QString username, email, passwort, passwortWdh, s1, s2;
    username= ui ->LEUsername->text();
    email=ui->LEEMail->text();
    passwort= ui->LEPasswort->text();
    passwortWdh= ui->LEPasswortwdh->text();
    s1= ui->LEs1->text();
    s2= ui->LEs2 ->text();
    QString e=email;


//Wenn in ein Feld nichts eingetragen wird
    if(username=="" || email=="" || passwort=="" || passwortWdh=="" || s1=="" || s2==""){
        QMessageBox::critical(this, tr("Fehler"), tr("Nicht alle Felder ausgefüllt!"));

    }
//Wenn die beiden Passwörter nicht übereinstimmen
    else if(passwort != passwortWdh){
    QMessageBox::critical(this, tr("Fehler"), tr("Passwörter stimmen nicht überein!")); }



//Prüfen, ob es eine gültige EMail Adresse ist und Nutzer registrieren
    else if ((e.contains("@") && e.contains(".com"))|| (e.contains("@") && e.contains(".de")))
    {
        Datenbank * db= Datenbank::getInstance();
        db->connOpen();
        QSqlQuery query;

        if(!NP.ProfilCheckVorhanden(query, username, email)) {
            if(NP.ProfilInsert(query, username, passwort, email, s1, s2)) {
                NP.ProfilLaden(query, username, passwort);
                
                this->close();
                //QMessageBox::information(this, tr("Login"), tr("Ihr Login wird vorbereitet!"));
                //this->hide();
                Tagesansicht Tagesansicht;
                Tagesansicht.setModal(true);
                Tagesansicht.exec();
            }
            else {
                QMessageBox::warning(this, tr("Registrierung"), tr("Fehler mit der Verbindung!"));
            }
        }
        else {
            QMessageBox::warning(this, tr("Registrierung"), tr("Username oder EMail bereits vergeben!"));
        }

        db->connClose();
    }
    else{
         QMessageBox::warning(this, tr("Registrierung"), tr("Keine gültige E-Mail Adresse!"));

    }

}


void Registrieren::on_login_clicked()
{
    MainWindow *qmain= new MainWindow(0);
    this->close();
    qmain->show();
}
