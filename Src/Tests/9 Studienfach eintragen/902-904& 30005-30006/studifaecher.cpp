#include "studifaecher.h"
#include "ui_studifaecher.h"
//#include "Studienfach_Klasse.h"
//#include "QList_Model_FuerAusgabeStudienfaecher.h"
#include <QMessageBox>
#include "studifaecher_verwalten.h"
//#include "Nutzerprofil.h"

/*
 * Author: Elena Schmidmeier
 *
 */

studifaecher::studifaecher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studifaecher)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(showFullScreen()));
    QPixmap calenderLogo("Images/Kalender1.png");
    ui->l1->setPixmap(calenderLogo);
    ui->l2->setPixmap(calenderLogo);
    ui->l3->setPixmap(calenderLogo);
    ui->l4->setPixmap(calenderLogo);
    ui->l5->setPixmap(calenderLogo);
    ui->l6->setPixmap(calenderLogo);
    ui->l7->setPixmap(calenderLogo);
    ui->faecher->setSelectionBehavior(QAbstractItemView::SelectRows);
    QPixmap LogoKlein("Images/LogoKlein.png");
    ui->logo->setPixmap(LogoKlein);

    //studiAnzeige();
}


studifaecher::~studifaecher()
{
    delete ui;
}


//speichern Button betätigt
void studifaecher::on_speichern_clicked()
{
    //NProfil *NP = NProfil::getInstance();

    QString Name, Ects, Sws, Stunden;
    Name= ui->name->text();
    Ects=ui->ects->text();
    Sws=ui->sws->text();
    Stunden=ui->stunden->text();

    int stunden=Stunden.toInt();
    int sws=Sws.toInt();
    int ects=Ects.toInt();
    if(Name==""){
        QMessageBox::warning(this, tr("Titel"), tr("Kein Name eingegeben!"));
    }
    else {
        ui->name->setText(" ");
        ui->ects->setValue(0);
        ui->sws->setValue(0);
        ui->stunden->setValue(0);

        //Studienfach ST;
        //QSqlQuery Query;
        //int i =NP->idNutzer;
        //ST.insert_Studienfach(Query,Name,ects,sws,stunden,i);

    }
    //studiAnzeige();
}
//abbrechen Button betätigt
void studifaecher::on_abbrechen_clicked()
{
    this->close();
}


void studifaecher::on_faecher_doubleClicked(const QModelIndex &index)
{
    int a= index.row();
    QString i= ui->faecher->model()->data(ui->faecher->model()->index(a,0)).toString();

    //Studifaecher_verwalten verwalten;
    //verwalten.setModal(true);
    //verwalten.setData_fach(i);
    //verwalten.exec();
    //studiAnzeige();

}

