#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "registrieren.h"
#include <password.h>
#include "tagesansicht.h"
#include "Nutzerprofil.h"
#include "Globals.h"
#include "wochenansicht.h"
#include"Datenbank.h"


/*
 * Author: Irma Krieger, Josef Lanzl
 *
 */

extern NProfil NP;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Public/StudiKalender/Logo1.png");
    ui->lblLogo->setPixmap(pix);

    QPixmap calenderLogo("C:/Users/Public/StudiKalender/Kalender1.png");
    ui->lbl3->setPixmap(calenderLogo);
    ui->lbl4->setPixmap(calenderLogo);
    ui->lbl5->setPixmap(calenderLogo);
    ui->lbl6->setPixmap(calenderLogo);
    ui->lbl7->setPixmap(calenderLogo);
    ui->lbl8->setPixmap(calenderLogo);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonLogIn_clicked()
{
    QString username = ui ->lEUsername->text();
    QString passwort = ui ->lEPasswort->text();
    //Daten werden eingelesen

    //Datenbankverbindung aufbauen

    Datenbank * db = Datenbank::getInstance();
    db->connOpen();
    QSqlQuery query;
    NProfil np;

     if(np.ProfilCheckPasswort(query, username, passwort))
     {
         QMessageBox::information(this, "Login", "Username und Passwort stimmen überein. Login wird vorbereitet");
         //testet, ob Username zum Passwort passt'

         //Hier wird die globale Variable gefüllt
         NP.ProfilLaden(query,username,passwort);

         //Datenbankverbindung schließen
         db->connClose();

         Tagesansicht start;
         this->close();
         start.setModal(true);
         start.exec();


     }

     else if(username == "" || passwort == "")
     {
         QMessageBox::warning(this, "Login", "Bitte Benutzerdaten eingeben");


     }

    else
     {

        QMessageBox::warning(this, "Login", "Deine Anmeldedaten stimmen nicht überein.");
        //Fehlermeldung, wenn Username und Passwort nicht übereinstimmen}
     }
}


void MainWindow::on_pushRegistrieren_clicked()
{
    Registrieren registrieren;
    this->close();
    registrieren.setModal(true);
    registrieren.exec();


}

void MainWindow::on_pushButtonPassword_clicked()
{
    Password passwort;
    passwort.setModal(true);
    passwort.exec();


}
