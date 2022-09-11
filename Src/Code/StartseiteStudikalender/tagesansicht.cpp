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
#include "QList_Model_AusgabeTagesansicht.h"
#include "Lernplan.h"
#include "lernplanui.h"
#include "mainwindow.h"
#include "Reminder_Klasse.h"
#include <QCommonStyle>
#include <QStyle>

/*
 * Author: Elena Schmidmeier / André Zimmer(Ansichtsfunktion)
 *
 */


Tagesansicht::Tagesansicht(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Tagesansicht)
{  
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(showFullScreen())); //Vollbild

    NProfil *NP = NProfil::getInstance();

    QString username=NP->Nutzername;
    QDate curdate= QDate::currentDate();
    QString day= curdate.toString("dddd");
    QString curdatetext= curdate.toString("dd.MM.yyyy");
    QString welcomeLabel="Hallo " + username + "!";
    QString welcome_2="Heute ist " + day + " der " + curdatetext;

    //Bilder einsetzen
    QPixmap calenderLogo("Images/Kalender11.png");
    QPixmap LogoKlein("Images/LogoKlein1.png");
    ui->logo->setPixmap(LogoKlein);
    ui->l1->setPixmap(calenderLogo);
    ui->l2->setPixmap(calenderLogo);
    ui->l3->setPixmap(calenderLogo);
    ui->l4->setPixmap(calenderLogo);
    ui->l5->setPixmap(calenderLogo);
    ui->l6->setPixmap(calenderLogo);
    ui->l7->setPixmap(calenderLogo);


    // Nutzer kann nur ganze Reihe auswählen
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    //Begrüßung und Datum einsetzen
    ui->label->setText(welcomeLabel);
    ui->username->setText(welcome_2);
    ui->Date->setText(ui->calendar->selectedDate().toString("dddd dd.MM.yyyy"));

    //Buttonpfeile einsetzen
    QCommonStyle styleForward;
    ui->tag_vor->setIcon(styleForward.standardIcon(QStyle::SP_ArrowRight));
    QCommonStyle styleBackward;
    ui->tag_zurueck->setIcon(styleBackward.standardIcon(QStyle::SP_ArrowLeft));

    //Profilbild anzeigen
    ui->profilePicture->setPixmap(NP->ProfilGetImage().scaled(ui->profilePicture->width(), ui->profilePicture->height(), Qt::KeepAspectRatio));

    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(MyTimerSlot()));

    // msec
    timer->start(10000);
    ansicht();

}

Tagesansicht::~Tagesansicht()
{
    delete ui;
}
//Ansicht aktualisieren
void Tagesansicht::ansicht()
{
    QDate Datum = ui->calendar->selectedDate();//Die Werte die Gesucht sind

    Kalender k;
    k.getTermin(Datum);

    // Modell erschaffen:
    TestModel *TagesansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    TagesansichtModel->populateData(k.BLidTermin,k.BLTerminname,k.BLDatum,k.BLBeginn,k.BLEnde,k.BLBeschreibung);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->tableView->setModel(TagesansichtModel);

    // zeige die Tabelle an:
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();

    QDate cur=QDate::currentDate();
    if(Datum==cur){
        ui->tableView_2->setModel(TagesansichtModel);

        // zeige die Tabelle an:
        ui->tableView_2->horizontalHeader()->setVisible(true);
        ui->tableView_2->show();
    }
}

//Zeile 123-134: abgeänderter Code von: https://wiki.qt.io/How_to_create_a_Custom_Calendar
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
    ansicht();

}
//einen Tag zurück
void Tagesansicht::on_tag_zurueck_clicked()
{
    QDate date = selectedDate();
    date = date.addDays(-1);
    setDate(date);
    ansicht();

}


// Termin erstellen Button
void Tagesansicht::on_neuer_Termin_clicked()
{
    Termin_erstellen neuerTermin;
    neuerTermin.setModal(true);
    neuerTermin.exec();
    ansicht();

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
void Tagesansicht::on_ansicht_currentTextChanged()
{
    QString ansicht=ui->ansicht->currentText();
    Monatsansicht monatsansicht;
    if(ansicht== "Monatsansicht"){
        this->close();
        monatsansicht.setModal(true);
        monatsansicht.exec();
    }

    Wochenansicht wochenansicht;
    if(ansicht== "Wochenansicht"){
        this->close();
        wochenansicht.setModal(true);
        wochenansicht.exec();
    }
}

//Termin per Doppelklick auswählen und Bearbeiten Fenster öffnen
void Tagesansicht::on_tableView_doubleClicked(const QModelIndex &index)
{
    int a= index.row();
    QString i= ui->tableView->model()->data(ui->tableView->model()->index(a,0)).toString();
    Termin_bearbeiten bearbeiten;
    bearbeiten.setModal(true);
    bearbeiten.setData(i);
    bearbeiten.exec();
    ansicht();

}
//Lernplan Button
void Tagesansicht::on_Lernplan_clicked()
{
    lernplanUI l;
    l.setModal(true);
    l.exec();
    ansicht();
}


void Tagesansicht::MyTimerSlot()
{
    Reminder REM;
    REM.runReminer();
}

// X Button geklickt, Programm beenden
void Tagesansicht::on_exit_clicked()
{

        qApp->closeAllWindows();
        qApp->quit();

}
//Nutzer meldet sich ab
void Tagesansicht::on_abmelden_clicked()
{
    QMessageBox messageBox(QMessageBox::Question,
                tr("Logout"),
                tr("Möchtest du wirklich abmelden?"),
                QMessageBox::Yes | QMessageBox::No,
                this);
        messageBox.setButtonText(QMessageBox::Yes, tr("Ja"));
        messageBox.setButtonText(QMessageBox::No, tr("Nein"));


    int t=messageBox.exec();
    switch(t){
      case QMessageBox::No:
        break;
      case QMessageBox::Yes:

        QMessageBox::information(this, "Logout", "Du wirst abgemeldet...");
        MainWindow *qmain= new MainWindow(0);
        this->close();
        qmain->show();


    }
}
