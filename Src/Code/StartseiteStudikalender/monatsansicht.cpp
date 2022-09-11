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
#include "Lernplan.h"
#include "lernplanui.h"
#include <QCommonStyle>
#include <QStyle>
/*
 * Author: Elena Schmidmeier
 *
 */

Monatsansicht::Monatsansicht(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Monatsansicht)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(showFullScreen())); //Vollbild

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


    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader); //CalendarWidget verändern
    ui->DateLabel->setText(ui->calendarWidget->selectedDate().toString("dddd dd.MM.yyyy"));//aktuelles Datum anzeigen
    //Nutzer darf nur ganze Reihe auswählen
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Buttonpfeile einsetzen
    QCommonStyle styleForward;
    ui->monat_vor->setIcon(styleForward.standardIcon(QStyle::SP_ArrowRight));
    QCommonStyle styleBackward;
    ui->monat_zurueck->setIcon(styleBackward.standardIcon(QStyle::SP_ArrowLeft));

    //Bergüßung und Datum anzeigen
    NProfil *NP = NProfil::getInstance();   
    QString username=NP->Nutzername;
    QDate curdate= QDate::currentDate();
    QString day= curdate.toString("dddd");
    QString curdatetext= curdate.toString("dd.MM.yyyy");
    QString calendarDay= ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");
    QString welcomeLabel="Hallo " + username + "!";
    QString welcome_2="Heute ist " + day + " der " + curdatetext;
    QString terminText="Deine Termine am " + calendarDay;
    ui->label_2->setText(welcomeLabel);
    ui->label_6->setText(welcome_2);
    ui->terminlabel->setText(terminText);

    //Profilbild anzeigen
    ui->profilePicture->setPixmap(NP->ProfilGetImage().scaled(ui->profilePicture->width(), ui->profilePicture->height(), Qt::KeepAspectRatio));

    anzeige();
}

Monatsansicht::~Monatsansicht()
{
    delete ui;
}
//Termine anzeigen
void Monatsansicht::anzeige()
{
    QDate Datum = ui->calendarWidget->selectedDate();//Die Werte die Gesucht sind

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

//Zeile 106-117: abgeänderter Code von: https://wiki.qt.io/How_to_create_a_Custom_Calendar
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
    QString calendarDay= ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);
}
//ein Monat zurück
void Monatsansicht::on_monat_zurueck_clicked()
{
    QDate date = selectedDate();
    date = date.addMonths(-1);
    setDate(date);
    QString calendarDay= ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);
}

//Termin hinzufügen Button
void Monatsansicht::on_termin_erstellen_clicked()
{
    Termin_erstellen neuerTermin;
    neuerTermin.setModal(true);
    neuerTermin.exec();
    anzeige();
}

//Fächer Button
void Monatsansicht::on_faecher_clicked()
{
    studifaecher faecher;
    faecher.setModal(true);
    faecher.exec();
}
//Profil Button
void Monatsansicht::on_profil_clicked()
{
    profil profil;
    profil.setModal(true);
    profil.exec();
}
//Ansicht wählen
void Monatsansicht::on_ansicht_currentTextChanged()
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
//Calendarwidget anderes Datum auswählen
void Monatsansicht::on_calendarWidget_selectionChanged()
{
    anzeige();
    QString calendarDay= ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    QString day= ui->calendarWidget->selectedDate().toString("dddd dd.MM.yyyy");

    ui->terminlabel->setText(terminText);
    ui->DateLabel->setText(day);
}
//Termin per Doppelklick auswählen und Bearbeiten Fenster öffnen
void Monatsansicht::on_tableView_doubleClicked(const QModelIndex &index)
{
    int a= index.row();
    QString i= ui->tableView->model()->data(ui->tableView->model()->index(a,0)).toString();
    Termin_bearbeiten bearbeiten;
    bearbeiten.setModal(true);
    bearbeiten.setData(i);
    bearbeiten.exec();
    anzeige();
}
//Lernplan Button
void Monatsansicht::on_lernplan_clicked()
{
        lernplanUI l;
        l.setModal(true);
        l.exec();
        anzeige();
}


// X Button und Programm beenden
void Monatsansicht::on_exit_clicked()
{

        qApp->closeAllWindows();
        qApp->quit();

}
//Abmelden Button
void Monatsansicht::on_Abmelden_clicked()
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
