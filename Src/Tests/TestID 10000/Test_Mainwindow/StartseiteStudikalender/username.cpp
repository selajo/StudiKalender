#include "username.h"
#include "ui_username.h"
#include "password.h"
#include "mainwindow.h"
#include <QMessageBox>


Username::Username(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Username)
{
    ui->setupUi(this);

    QPixmap calenderLogo("Images/Kalender1.png");
    ui->lbl1->setPixmap(calenderLogo);
    ui->lbl2->setPixmap(calenderLogo);
    ui->lbl3->setPixmap(calenderLogo);
    ui->lbl4->setPixmap(calenderLogo);
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

    NProfil *NP = NProfil::getInstance();

    QString username = NP->ProfilNutzernameVergessen(email, safety1, safety2);
    if(username != "")
    {

        QMessageBox::information(this, "Username vergessen", "Deine Daten werden überprüft...");
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
}


void Username::on_pushButton_clicked()
{
    this->close();
}
