#include "studifaecher.h"
#include "ui_studifaecher.h"
#include "Studienfach_Klasse.h"
#include "Datenbank.h"
#include "QList_Model_FuerAusgabeStudienfaecher.h"
#include <QMessageBox>
#include "studifaecher_verwalten.h"

/*
 * Author: Elena Schmidmeier
 *
 */

extern NProfil NP;

studifaecher::studifaecher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studifaecher)
{
    ui->setupUi(this);
    ui->faecher->setSelectionBehavior(QAbstractItemView::SelectRows);


    Datenbank * conn= Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    int idNutzer_fk = NP.idNutzer;


    // Erschaffe QList Container um die gesuchten Daten hineinzuspeichern
    QList<int> BLidStudienfach;
    QList<QString> BLBezeichnung;
    QList<int> BLECTS;
    QList<int> BLSWS;
    QList<int> BLEigenstunden;

    model->setQuery("SELECT  * FROM Studienfach "); //Durchsucht die Tabelle


    for (int i = 0; i < model->rowCount(); ++i) {// Geht alle Termine durch und sucht den Passenden
     int id = model->record(i).value("idStudienfach").toInt();
     QString name = model->record(i).value("Bezeichnung").toString();
     int date =model->record(i).value("ECTS").toInt();
     int beginn= model->record(i).value("SWS").toInt();
     int ende= model->record(i).value("Eigenstunden").toInt();
     int idnutzer_fk =model->record(i).value("idNutzer_FK").toInt();

    if(idNutzer_fk==idnutzer_fk){//Vergleiche ob es der richtige Tag und Nutzer ist

        //Daten in die QListen schreiben:
        BLidStudienfach.append(id);
        BLBezeichnung.append(name);
        BLECTS.append(date);
        BLSWS.append(beginn);
        BLEigenstunden.append(ende);
    }

    }

    // Modell erschaffen:
    TTestModel *TagesansichtModel = new TTestModel(this);

    // Model mit den Daten von den QListen füllen:
    TagesansichtModel->populateData(BLidStudienfach,BLBezeichnung,BLECTS,BLSWS,BLEigenstunden);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->faecher->setModel(TagesansichtModel);

    // zeige die Tabelle an:
    ui->faecher->horizontalHeader()->setVisible(true);
    ui->faecher->show();

    //Test Datenbank
    conn->connClose();

}


studifaecher::~studifaecher()
{
    delete ui;
}

//speichern Button betätigt
void studifaecher::on_speichern_clicked()
{
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

        Datenbank * db = Datenbank::getInstance();
        db->connOpen();

        Studienfach ST;
        QSqlQuery Query;
        int i =NP.idNutzer;
        ST.insert_Studienfach(Query,Name,ects,sws,stunden,i);

        db->connClose();
    }

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

    Studifaecher_verwalten verwalten;
    verwalten.setModal(true);
    verwalten.setData_fach(i);
    verwalten.exec();

}
