#include "registrieren.h"
#include "ui_registrieren.h"
#include <QMessageBox>
#include "tagesansicht.h"
#include "mainwindow.h"
#include "Nutzerprofil.h"

/*
 * Author: Elena Schmidmeier
 *
 */

Registrieren::Registrieren(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrieren)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(showFullScreen())); //Vollbild

    //Bilder einsetzen
    QPixmap pix("Images/Logo1.png");
    QPixmap calenderLogo("Images/Kalender1.png");
    ui->logo->setPixmap(pix);  
    ui->lbl2->setPixmap(calenderLogo);
    ui->lbl3->setPixmap(calenderLogo);
    ui->lbl4->setPixmap(calenderLogo);
    ui->lbl5->setPixmap(calenderLogo);
    ui->lbl6->setPixmap(calenderLogo);
    ui->lbl7->setPixmap(calenderLogo);
    ui->lbl1->setPixmap(calenderLogo);
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

    NProfil *NP = NProfil::getInstance();


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
        if(!NP->ProfilCheckVorhanden(username, email)) {
            if(NP->ProfilInsert(username, passwort, email, s1, s2)) {
                NP->ProfilLaden(username, passwort);
                
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

    }
    else{
         QMessageBox::warning(this, tr("Registrierung"), tr("Keine gültige E-Mail Adresse!"));

    }

}

//Zurück zum Login
void Registrieren::on_login_clicked()
{
    MainWindow *qmain= new MainWindow(0);
    this->close();
    qmain->show();
}
// X Button und Programm schließen
void Registrieren::on_exit_clicked()
{

        qApp->closeAllWindows();
        qApp->quit();


}
