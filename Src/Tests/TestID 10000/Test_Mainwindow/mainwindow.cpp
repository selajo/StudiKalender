#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "registrieren.h"
#include <password.h>
#include "tagesansicht.h"
#include "Nutzerprofil.h"
#include "wochenansicht.h"
#include"Datenbank.h"


/*
 * Author: Irma Krieger, Josef Lanzl
 *
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QTimer::singleShot(0, this, SLOT(showFullScreen()));
    ui->setupUi(this);

    QPixmap pix("C:/Users/Public/StudiKalender/Images/Logo1.png");
    ui->lblLogo->setPixmap(pix);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));

    QPixmap calenderLogo("C:/Users/Public/StudiKalender/Images/Kalender1.png");
    ui->lbl2->setPixmap(calenderLogo);
    ui->lbl3->setPixmap(calenderLogo);
    ui->lbl4->setPixmap(calenderLogo);
    ui->lbl5->setPixmap(calenderLogo);
    ui->lbl6->setPixmap(calenderLogo);
    ui->lbl7->setPixmap(calenderLogo);
    ui->lbl1->setPixmap(calenderLogo);



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

    NProfil * NP = NProfil::getInstance();

    try {
        Datenbank * conn = Datenbank::getInstance();
        conn->connOpen();

        if(NP->ProfilCheckPasswort(username, passwort))
        {
            QMessageBox::information(this, "Login", "Username und Passwort stimmen überein. Login wird vorbereitet");
            //testet, ob Username zum Passwort passt'

            //Hier wird die globale Variable gefüllt
            NP->ProfilLaden(username,passwort);

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
    catch(const char* e) {
        QMessageBox::warning(this, "Login", "Server konnte nicht erreicht werden. Bitte überprüfe deine Internetverbindung bzw. deinen VPN.");
        this->show();
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

void MainWindow::on_pushButton_destroyed()
{

}
