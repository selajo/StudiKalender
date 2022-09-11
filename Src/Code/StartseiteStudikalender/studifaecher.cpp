#include "studifaecher.h"
#include "ui_studifaecher.h"
#include "Studienfach_Klasse.h"
#include "QList_Model_FuerAusgabeStudienfaecher.h"
#include <QMessageBox>
#include "studifaecher_verwalten.h"
#include "Nutzerprofil.h"

/*
 * Author: Elena Schmidmeier
 *
 */

studifaecher::studifaecher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studifaecher)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(showFullScreen())); //Vollbild
    //Bilder einsetzen
    QPixmap calenderLogo("Images/Kalender1.png");
    QPixmap LogoKlein("Images/LogoKlein1.png");
    ui->logo->setPixmap(LogoKlein);
    ui->l1->setPixmap(calenderLogo);
    ui->l2->setPixmap(calenderLogo);
    ui->l3->setPixmap(calenderLogo);
    ui->l4->setPixmap(calenderLogo);
    ui->l5->setPixmap(calenderLogo);
    ui->l6->setPixmap(calenderLogo);
    ui->l7->setPixmap(calenderLogo);
    //Nutzer kann nur ganze Reihe auswählen
    ui->faecher->setSelectionBehavior(QAbstractItemView::SelectRows);

    studiAnzeige();
}


studifaecher::~studifaecher()
{
    delete ui;
}
//Fächer anzeigen
void studifaecher::studiAnzeige()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    NProfil *NP = NProfil::getInstance();

    int idNutzer_fk = NP->idNutzer;


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
}


//speichern Button betätigt
void studifaecher::on_speichern_clicked()
{
    NProfil *NP = NProfil::getInstance();

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

        Studienfach ST;

        int i =NP->idNutzer;
        ST.insert_Studienfach(Name,ects,sws,stunden,i);

    }
    studiAnzeige();
}
//abbrechen
void studifaecher::on_abbrechen_clicked()
{
    this->close();
}

//Nutzer klickt doppelt auf ein Fach und das Bearbeiten Fenster öffnet sich
void studifaecher::on_faecher_doubleClicked(const QModelIndex &index)
{
    int a= index.row();
    QString i= ui->faecher->model()->data(ui->faecher->model()->index(a,0)).toString();

    Studifaecher_verwalten verwalten;
    verwalten.setModal(true);
    verwalten.setData_fach(i);
    verwalten.exec();
    studiAnzeige();

}

