#include "password.h"
#include "ui_password.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "Nutzerprofil.h"
#include "username.h"
#include "Datenbank.h"

/*
 * Author: Irma Krieger
 *
 */

extern NProfil NP;

Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
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

    //Datenbankverbindung aufbauen
    Datenbank * db = Datenbank::getInstance();
    db->connOpen();


    QSqlQuery query;

    if(NP.ProfilPasswortVergessen(query, username, email, safety1, safety2, passwort))
    {
        QMessageBox::information(this, "Login", "Passwort geändert");
        //testet, ob Username,E-mail, S1 und S2 passt und ändert Passwort
        NP.ProfilLaden(query, username, passwort);
        Tagesansicht start;
        this->close();
        start.setModal(true);
        start.exec();
    }
    //Felder leer
    else if(username == "" || email == "" || safety1 == "" || safety2 == "")
    {
        QMessageBox::warning(this, "Passwort vergessen", "Bitte Benutzerdaten eingeben");


    }
   else
    {
       QMessageBox::warning(this, "Passwort vergessen", "Dein Username stimmt nicht mit deinen Daten überein.");
       //Fehlermeldung, wenn Username, E-mail, S1 und S2 nicht übereinstimmen
    }

    //Datenbankverbindung schließen
    db->connClose();
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
