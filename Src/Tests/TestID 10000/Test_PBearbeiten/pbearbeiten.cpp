#include "pbearbeiten.h"
#include "ui_pbearbeiten.h"
#include "Nutzerprofil.h"
#include "mainwindow.h"
#include "QMainWindow"
#include <QDialog>
#include <QMessageBox>


/*
 * Author: Irma Krieger
 *
 */

PBearbeiten::PBearbeiten(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PBearbeiten)
{
    ui->setupUi(this);
    connect(ui->ButtonExit, SIGNAL(clicked()), this, SLOT(close()));
}

PBearbeiten::~PBearbeiten()
{
    delete ui;
}

void PBearbeiten::on_ButtonExit_destroyed()
{

}


void PBearbeiten::on_ButtonProfil_clicked()
{
    //Datenbankverbindung aufbauen
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("Stud!KLSZ21");
    db.setDatabaseName("Kalender");

    db.open();
    QSqlQuery query;
    NProfil np;




}
