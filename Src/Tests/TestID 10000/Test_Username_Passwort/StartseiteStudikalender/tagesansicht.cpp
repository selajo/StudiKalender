#include "tagesansicht.h"
#include "ui_tagesansicht.h"
#include "termin_erstellen.h"
#include "termin_bearbeiten.h"
#include "ui_termin_bearbeiten.h"
#include "studifaecher.h"
#include <QDateTime>
#include <QDate>
#include <QTimer>
#include <QCalendarWidget>
#include <QDate>
#include <QApplication>
#include <QMessageBox>
#include <QEvent>
#include "profil.h"
#include "monatsansicht.h"
#include "wochenansicht.h"
#include <QWidget>
#include "Datenbank.h"
#include "QList_Model_AusgabeTagesansicht.h"
#include "Lernplan.h"
#include "lernplanui.h"
#include "mainwindow.h"
#include <QCommonStyle>
#include <QStyle>

/*
 * Author: Elena Schmidmeier / André Zimmer
 *
 */

extern NProfil NP;

Tagesansicht::Tagesansicht(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Tagesansicht)
{
    ui->setupUi(this);
    QDate curdate= QDate::currentDate();
    QString curdatetext= curdate.toString("dd.MM.yyyy");

    ui->Date->setText(ui->calendar->selectedDate().toString("dddd dd.MM.yyyy"));
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->label->setText(curdatetext);


    QCommonStyle styleForward;
    ui->tag_vor->setIcon(styleForward.standardIcon(QStyle::SP_ArrowRight));
    QCommonStyle styleBackward;
    ui->tag_zurueck->setIcon(styleBackward.standardIcon(QStyle::SP_ArrowLeft));


    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = ui->calendar->selectedDate();//Die Werte die Gesucht sind


    int idNutzer_fk = NP.idNutzer;


    // Erschaffe QList Container um die gesuchten Daten hineinzuspeichern
    QList<int> BLidTermin;
    QList<QString> BLTerminname;
    QList<QDate> BLDatum;
    QList<QTime> BLBeginn;
    QList<QTime> BLEnde;

    model->setQuery("SELECT  * FROM Termin "); //Durchsucht die Tabelle


    for (int i = 0; i < model->rowCount(); ++i) {// Geht alle Termine durch und sucht den Passenden
     int id = model->record(i).value("idTermin").toInt();
     QString name = model->record(i).value("Terminname").toString();
     QDate date =model->record(i).value("Datum").toDate();
     QTime beginn= model->record(i).value("Beginn").toTime();
     QTime ende= model->record(i).value("Ende").toTime();
     int idnutzer_fk =model->record(i).value("idNutzer_fk").toInt();

    if(idNutzer_fk==idnutzer_fk&&Datum==date){//Vergleiche ob es der richtige Tag und Nutzer ist

        //Daten in die QListen schreiben:
        BLidTermin.append(id);
        BLTerminname.append(name);
        BLDatum.append(date);
        BLBeginn.append(beginn);
        BLEnde.append(ende);
    }

    }

    // Modell erschaffen:
    TestModel *TagesansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    TagesansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->tableView->setModel(TagesansichtModel);

    // zeige die Tabelle an:
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();

    ui->tableView_2->setModel(TagesansichtModel);

    // zeige die Tabelle an:
    ui->tableView_2->horizontalHeader()->setVisible(true);
    ui->tableView_2->show();

    //Test Datenbank
    conn->connClose();

}

Tagesansicht::~Tagesansicht()
{
    delete ui;
}
//Zeile 104-121 & 179-183: abgeänderter Code von: https://wiki.qt.io/How_to_create_a_Custom_Calendar
QDate Tagesansicht::selectedDate() const
{
    return ui->calendar->selectedDate();
}

void Tagesansicht::setDate(const QDate &d)
{
    QDate date = d;
    ui->calendar->setSelectedDate(date);
    ui->Date->setText(date.toString("dddd dd.MM.yyyy"));
}

//einen Tag vor
void Tagesansicht::on_tag_vor_clicked()
{
    QDate date = selectedDate();
    date = date.addDays(+1);
    setDate(date);

    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = date;//Die Werte die Gesucht sind


    int idNutzer_fk = NP.idNutzer;


    // Erschaffe QList Container um die gesuchten Daten hineinzuspeichern
    QList<int> BLidTermin;
    QList<QString> BLTerminname;
    QList<QDate> BLDatum;
    QList<QTime> BLBeginn;
    QList<QTime> BLEnde;

    model->setQuery("SELECT  * FROM Termin "); //Durchsucht die Tabelle


    for (int i = 0; i < model->rowCount(); ++i) {// Geht alle Termine durch und sucht den Passenden
     int id = model->record(i).value("idTermin").toInt();
     QString name = model->record(i).value("Terminname").toString();
     QDate date =model->record(i).value("Datum").toDate();
     QTime beginn= model->record(i).value("Beginn").toTime();
     QTime ende= model->record(i).value("Ende").toTime();
     int idnutzer_fk =model->record(i).value("idNutzer_fk").toInt();

    if(idNutzer_fk==idnutzer_fk&&Datum==date){//Vergleiche ob es der richtige Tag und Nutzer ist

        //Daten in die QListen schreiben:
        BLidTermin.append(id);
        BLTerminname.append(name);
        BLDatum.append(date);
        BLBeginn.append(beginn);
        BLEnde.append(ende);
    }

    }

    // Modell erschaffen:
    TestModel *TagesansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    TagesansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->tableView->setModel(TagesansichtModel);

    // zeige die Tabelle an:
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();


    //Test Datenbank
    conn->connClose();

}
//einen Tag zurück
void Tagesansicht::on_tag_zurueck_clicked()
{
    QDate date = selectedDate();
    date = date.addDays(-1);
    setDate(date);

    Datenbank * conn= Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = date;//Die Werte die Gesucht sind


    int idNutzer_fk = NP.idNutzer;


    // Erschaffe QList Container um die gesuchten Daten hineinzuspeichern
    QList<int> BLidTermin;
    QList<QString> BLTerminname;
    QList<QDate> BLDatum;
    QList<QTime> BLBeginn;
    QList<QTime> BLEnde;

    model->setQuery("SELECT  * FROM Termin "); //Durchsucht die Tabelle


    for (int i = 0; i < model->rowCount(); ++i) {// Geht alle Termine durch und sucht den Passenden
     int id = model->record(i).value("idTermin").toInt();
     QString name = model->record(i).value("Terminname").toString();
     QDate date =model->record(i).value("Datum").toDate();
     QTime beginn= model->record(i).value("Beginn").toTime();
     QTime ende= model->record(i).value("Ende").toTime();
     int idnutzer_fk =model->record(i).value("idNutzer_fk").toInt();

    if(idNutzer_fk==idnutzer_fk&&Datum==date){//Vergleiche ob es der richtige Tag und Nutzer ist

        //Daten in die QListen schreiben:
        BLidTermin.append(id);
        BLTerminname.append(name);
        BLDatum.append(date);
        BLBeginn.append(beginn);
        BLEnde.append(ende);
    }

    }

    // Modell erschaffen:
    TestModel *TagesansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    TagesansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->tableView->setModel(TagesansichtModel);

    // zeige die Tabelle an:
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();

    //Test Datenbank
    conn->connClose();

}


// Termin erstellen Button
void Tagesansicht::on_neuer_Termin_clicked()
{
    Termin_erstellen neuerTermin;
    neuerTermin.setModal(true);
    neuerTermin.exec();

}

//Fächer anschauen Button
void Tagesansicht::on_faecher_clicked()
{
    studifaecher faecher;
    faecher.setModal(true);
    faecher.exec();

}
//Profil anschauen Button
void Tagesansicht::on_profil_clicked()
{
    profil profil;
    profil.setModal(true);
    profil.exec();
}

//Ansichten auswählen
void Tagesansicht::on_ansicht_currentTextChanged(const QString &arg1)
{
    QString ansicht=ui->ansicht->currentText();
    Monatsansicht monatsansicht;
    if(ansicht== "Monatsansicht"){
        this->close();
        monatsansicht.setModal(true);
        monatsansicht.exec();}

    Wochenansicht wochenansicht;
    if(ansicht== "Wochenansicht"){
        this->close();
        wochenansicht.setModal(true);
        wochenansicht.exec();
}
}

//aktualisieren Button aktualisiert Terminanzeige
void Tagesansicht::on_pushButton_clicked()
{

    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = ui->calendar->selectedDate();//Die Werte die Gesucht sind


    int idNutzer_fk = NP.idNutzer;


    // Erschaffe QList Container um die gesuchten Daten hineinzuspeichern
    QList<int> BLidTermin;
    QList<QString> BLTerminname;
    QList<QDate> BLDatum;
    QList<QTime> BLBeginn;
    QList<QTime> BLEnde;

    model->setQuery("SELECT  * FROM Termin "); //Durchsucht die Tabelle


    for (int i = 0; i < model->rowCount(); ++i) {// Geht alle Termine durch und sucht den Passenden
     int id = model->record(i).value("idTermin").toInt();
     QString name = model->record(i).value("Terminname").toString();
     QDate date =model->record(i).value("Datum").toDate();
     QTime beginn= model->record(i).value("Beginn").toTime();
     QTime ende= model->record(i).value("Ende").toTime();
     int idnutzer_fk =model->record(i).value("idNutzer_fk").toInt();

    if(idNutzer_fk==idnutzer_fk&&Datum==date){//Vergleiche ob es der richtige Tag und Nutzer ist

        //Daten in die QListen schreiben:
        BLidTermin.append(id);
        BLTerminname.append(name);
        BLDatum.append(date);
        BLBeginn.append(beginn);
        BLEnde.append(ende);
    }

    }

    // Modell erschaffen:
    TestModel *TagesansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    TagesansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->tableView->setModel(TagesansichtModel);

    // zeige die Tabelle an:
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();

    ui->tableView_2->setModel(TagesansichtModel);

    // zeige die Tabelle an:
    ui->tableView_2->horizontalHeader()->setVisible(true);
    ui->tableView_2->show();

    //Test Datenbank
    conn->connClose();
}

void Tagesansicht::on_tableView_doubleClicked(const QModelIndex &index)
{
    int a= index.row();
    QString i= ui->tableView->model()->data(ui->tableView->model()->index(a,0)).toString();
    Termin_bearbeiten bearbeiten;
    bearbeiten.setModal(true);
    bearbeiten.setData(i);
    bearbeiten.exec();

}

void Tagesansicht::on_Lernplan_clicked()
{
    lernplanUI l;
    l.setModal(true);
    l.exec();

}

void Tagesansicht::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    int a= index.row();
    QString i= ui->tableView->model()->data(ui->tableView->model()->index(a,0)).toString();
    Termin_bearbeiten bearbeiten;
    bearbeiten.setModal(true);
    bearbeiten.setData(i);
    bearbeiten.exec();


}
