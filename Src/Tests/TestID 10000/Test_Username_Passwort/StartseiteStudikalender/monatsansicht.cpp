#include "monatsansicht.h"
#include "ui_monatsansicht.h"
#include "termin_erstellen.h"
#include "termin_bearbeiten.h"
#include "studifaecher.h"
#include "profil.h"
#include "tagesansicht.h"
#include <QMessageBox>
#include "wochenansicht.h"
#include "QList_Model_AusgabeTagesansicht.h"
#include "Datenbank.h"
#include "Lernplan.h"
#include "lernplanui.h"
#include <QCommonStyle>
#include <QStyle>
/*
 * Author: Elena Schmidmeier
 *
 */
extern NProfil NP;
Monatsansicht::Monatsansicht(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Monatsansicht)
{
    ui->setupUi(this);
    QDate curdate= QDate::currentDate();
    QString curdatetext= curdate.toString("dd.MM.yyyy");
    QString d=curdate.toString("dddd");
    ui->label_2->setText(curdatetext);
    ui->wochentag->setText(d);

    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    ui->DateLabel->setText(ui->calendarWidget->selectedDate().toString("dddd dd.MM.yyyy"));
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    QCommonStyle styleForward;
    ui->monat_vor->setIcon(styleForward.standardIcon(QStyle::SP_ArrowRight));
    QCommonStyle styleBackward;
    ui->monat_zurueck->setIcon(styleBackward.standardIcon(QStyle::SP_ArrowLeft));

    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = ui->calendarWidget->selectedDate();//Die Werte die Gesucht sind


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

    //Datenbankverbindung schließen
    conn->connClose();

}

Monatsansicht::~Monatsansicht()
{
    delete ui;
}
//Zeile 31-55: abgeänderter Code von: https://wiki.qt.io/How_to_create_a_Custom_Calendar
QDate Monatsansicht::selectedDate() const
{
    return ui->calendarWidget->selectedDate();
}
void Monatsansicht::setDate(const QDate &d)
{
    QDate date = d;
    ui->calendarWidget->setSelectedDate(date);
    ui->calendarWidget->showSelectedDate();
    ui->DateLabel->setText(date.toString("dddd dd.MM.yyyy"));
}
//ein Monat vor
void Monatsansicht::on_monat_vor_clicked()
{
    QDate date = selectedDate();
    date = date.addMonths(+1);
    setDate(date);
}
//ein Monat zurück
void Monatsansicht::on_monat_zurueck_clicked()
{
    QDate date = selectedDate();
    date = date.addMonths(-1);
    setDate(date);
}

//Termin erstellen
void Monatsansicht::on_termin_erstellen_clicked()
{
    Termin_erstellen neuerTermin;
    neuerTermin.setModal(true);
    neuerTermin.exec();
}

//Fächer anschauen
void Monatsansicht::on_faecher_clicked()
{
    studifaecher faecher;
    faecher.setModal(true);
    faecher.exec();
}
//Profil anschauen
void Monatsansicht::on_profil_clicked()
{
    profil profil;
    profil.setModal(true);
    profil.exec();
}
//Ansicht wählen
void Monatsansicht::on_ansicht_currentTextChanged(const QString &arg1)
{
    QString ansicht=ui->ansicht->currentText();
    Tagesansicht tagesansicht;
    if(ansicht== "Tagesansicht"){
        this->close();
        tagesansicht.setModal(true);
        tagesansicht.exec();
    }

    Wochenansicht wochenansicht;
    if(ansicht== "Wochenansicht"){
        this->close();
        wochenansicht.setModal(true);
        wochenansicht.exec();
    }
}

void Monatsansicht::on_calendarWidget_selectionChanged()
{
    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = ui->calendarWidget->selectedDate();//Die Werte die Gesucht sind
    ui->DateLabel->setText(Datum.toString("dddd dd.MM.yyyy"));


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

// Datenbankverbindung schließen
    conn->connClose();
}

void Monatsansicht::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString i= ui->tableView->model()->data(index).toString();
    Termin_bearbeiten bearbeiten;
    bearbeiten.setModal(true);
    bearbeiten.setData(i);
    bearbeiten.exec();
}

void Monatsansicht::on_lernplan_clicked()
{
        lernplanUI l;
        l.setModal(true);
        l.exec();

}

void Monatsansicht::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    QString i= ui->tableView->model()->data(index).toString();
    Termin_bearbeiten bearbeiten;
    bearbeiten.setModal(true);
    bearbeiten.setData(i);
    bearbeiten.exec();

}
