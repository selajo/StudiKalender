#include "password.h"
#include "ui_password.h"
#include <QMessageBox>

#include "Nutzerprofil.h"
#include "username.h"
/*
 * Author: Irma Krieger
 *
 */


Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password)
{

    ui->setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint);

}

Password::~Password()
{
    delete ui;
}

void Password::on_ButtonCheck_clicked()
{
    QString username = ui ->lEUsername->text();
    QString email = ui -> Email->text();
    QString safety1 = ui ->lES1->text();
    QString safety2 = ui -> lES2->text();
    QString passwort = ui -> lEPasswort->text();

    //Daten werden eingelesen

    NProfil *NP = NProfil::getInstance();

    if(NP->ProfilPasswortVergessen(username, email, safety1, safety2, passwort))
    {

        QMessageBox::information(this, "Login", "Passwort geändert");
        //testet, ob Username,E-mail, S1 und S2 passt und ändert Passwort
        NP->ProfilLaden(username, passwort);
        this->close();

        }


    //Felder leer
    else if(username == "" || email == "" || safety1 == "" || safety2 == "" || passwort == "")
    {
        QMessageBox::warning(this, "Passwort vergessen", "Bitte Benutzerdaten eingeben");


    }
   else
    {
       QMessageBox::warning(this, "Passwort vergessen", "Dein Username stimmt nicht mit deinen Daten überein.");
       //Fehlermeldung, wenn Username, E-mail, S1 und S2 nicht übereinstimmen
    }

    //Datenbankverbindung schließen
}

void Password::on_ButtonCheck_2_clicked()
{
    Username user;
    user.setModal(true);
    this->close();
    user.exec();

}


void Password::on_pushButton_clicked()
{
    this->close();
}
