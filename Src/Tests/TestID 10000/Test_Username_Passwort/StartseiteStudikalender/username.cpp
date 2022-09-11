#include "username.h"
#include "ui_username.h"
#include "password.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "Datenbank.h"

extern NProfil NP;


Username::Username(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Username)
{
    ui->setupUi(this);
}

Username::~Username()
{
    delete ui;
}

void Username::on_ForgotPassword_clicked()
{
    Password passwort;
    passwort.setModal(true);
    this->close();
    passwort.exec();

}

void Username::on_ButtonCheck_clicked()
{
    QString email = ui -> Email->text();
    QString safety1 = ui ->lES1->text();
    QString safety2 = ui -> lES2->text();

    //Daten werden eingelesen

    //Datenbankverbindung aufbauen
    Datenbank * db = Datenbank::getInstance();
    db->connOpen();


    QSqlQuery query;

    QString username = NP.ProfilNutzernameVergessen(query, email, safety1, safety2);
    if(username != "")
    {
        QMessageBox::information(this, "Username vergessen", "Dein Username lautet: ");
        ui->lEUsername->setText(username);
        //testet, ob E-mail, S1 und S2 passt und gibt Username aus
    }
    //Felder leer
    else if(email == "" || safety1 == "" || safety2 == "")
    {
        QMessageBox::warning(this, "Username vergessen", "Bitte Benutzerdaten eingeben");


    }
   else
    {
       QMessageBox::warning(this, "Username vergessen", "Deine Email stimmt nicht mit deinen Daten überein.");
       //Fehlermeldung, wenn  E-mail, S1 und S2 nicht übereinstimmen
    }

    db->connClose();
}
