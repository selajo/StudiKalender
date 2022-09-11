#include "wochenansicht.h"
#include "ui_wochenansicht.h"
#include "termin_erstellen.h"
#include "termin_bearbeiten.h"
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
#include "tagesansicht.h"
#include <QWidget>
#include "QList_Model_AusgabeTagesansicht.h"
#include <QStyle>
#include <QCommonStyle>
#include "lernplanui.h"
#include "Kalender.h"




/*
 * Author: Irma Krieger
 *
 */

Wochenansicht::Wochenansicht(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wochenansicht)
{
    setWindowFlags(Qt::WindowTitleHint);

    QTimer::singleShot(0, this, SLOT(showFullScreen()));
    ui->setupUi(this);
    ui->calendarWidget->setNavigationBarVisible(false);
    ui->calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    NProfil *NP = NProfil::getInstance();

    QString username=NP->Nutzername;
    QDate curdate= QDate::currentDate();
    QString day= curdate.toString("dddd");
    QString curdatetext= curdate.toString("dd.MM.yyyy");
    QString Welcomelbl="Hallo " + username + "!";
    QString Welcomelbl2="Heute ist " + day + " der " + curdatetext;
    QString calendarDay= ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);
    ansicht(curdate);
    ui->Welcomelbl->setText(Welcomelbl);
    ui->Welcomelbl2->setText(Welcomelbl2);



    ui->DateLable->setText(ui->calendarWidget->selectedDate().toString("dd MMMM yyyy"));
    weekday(); //Random Wert, der später geändert wird
    QCommonStyle styleForward;
    ui->dayFrontButton->setIcon(styleForward.standardIcon(QStyle::SP_ArrowRight));
    QCommonStyle styleBackward;
    ui->dayBackButton->setIcon(styleBackward.standardIcon(QStyle::SP_ArrowLeft));
    QPixmap calenderLogo("C:/Users/Public/StudiKalender/Images/Kalender1.png");
    QPixmap LogoKlein("C:/Users/Public/StudiKalender/Images/LogoKlein1.png");
    ui->lbl2->setPixmap(calenderLogo);
    ui->lbl3->setPixmap(calenderLogo);
    ui->lbl4->setPixmap(calenderLogo);
    ui->lbl5->setPixmap(calenderLogo);
    ui->lbl6->setPixmap(calenderLogo);
    ui->lbl7->setPixmap(calenderLogo);
    ui->lbl1->setPixmap(calenderLogo);


    ui->LogoKlein->setPixmap(LogoKlein);

    ui->profilePicture->setPixmap(NP->ProfilGetImage().scaled(ui->profilePicture->width(), ui->profilePicture->height(), Qt::KeepAspectRatio));

    this->lastDate = QDate::currentDate();
}

void Wochenansicht::ansicht(QDate Datum) {
    Kalender k;
    k.getTermin(Datum);

    // Modell erschaffen:
    TestModel *WochenansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    WochenansichtModel->populateData(k.BLidTermin,k.BLTerminname,k.BLDatum,k.BLBeginn,k.BLEnde,k.BLBeschreibung);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->Anzeige->setModel(WochenansichtModel);

    // zeige die Tabelle an:
    ui->Anzeige->horizontalHeader()->setVisible(true);
    ui->Anzeige->show();
    QDate cur=QDate::currentDate();
    if(Datum==cur){
        ui->tableView_2->setModel(WochenansichtModel);

        // zeige die Tabelle an:
        ui->tableView_2->horizontalHeader()->setVisible(true);
        ui->tableView_2->show();
    }

}


Wochenansicht::~Wochenansicht()
{
    delete ui;


}


QDate Wochenansicht::currentDate() const{
    return ui->calendarWidget->selectedDate();
}

QDate Wochenansicht::selectedDate() const
{
    return ui->calendarWidget->selectedDate();
}

void Wochenansicht::setCurrentDate(const QDate &d)
{
    QDate date=d;
    if(!date.isValid())
            date = QDate::currentDate();
}
void Wochenansicht::setDate(const QDate &d)
{
    QDate date = d;
    ui->calendarWidget->setSelectedDate(date);
    ui->DateLable->setText(date.toString("dd MMMM yyyy"));
}

//Algorithmus rechnet aus, welcher Wochentag der Tag X hat und macht eine Fallunterscheidung
void Wochenansicht::weekday()
{
    int d = QDate::currentDate().day();
    int m = QDate::currentDate().month();
    int y = QDate::currentDate().year();

  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  int ergebnis;
  ergebnis=(y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;

  QDate date = currentDate();

  switch (ergebnis) {
  case 0: //Sonntag
      ui->So->setText(currentDate().toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Sa->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Fr->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Do->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Mi->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Di->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Mo->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      break;
  case 1: //Montag
      ui->Mo->setText(currentDate().toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(+1);
      ui->Di->setText(date.toString("dd"));
      Wochentag.insert(1,date);
      date = date.addDays(+1);
      ui->Mi->setText(date.toString("dd"));
      Wochentag.insert(2,date);
      date = date.addDays(+1);
      ui->Do->setText(date.toString("dd"));
      Wochentag.insert(3,date);
      date = date.addDays(+1);
      ui->Fr->setText(date.toString("dd"));
      Wochentag.insert(4,date);
      date = date.addDays(+1);
      ui->Sa->setText(date.toString("dd"));
      Wochentag.insert(5,date);
      date = date.addDays(+1);
      ui->So->setText(date.toString("dd"));
      Wochentag.insert(6,date);
      break;
  case 2: //Dienstag
      ui->Di->setText(currentDate().toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(+1);
      ui->Mi->setText(date.toString("dd"));
      Wochentag.insert(1,date);
      date = date.addDays(+1);
      ui->Do->setText(date.toString("dd"));
      Wochentag.insert(2,date);
      date = date.addDays(+1);
      ui->Fr->setText(date.toString("dd"));
      Wochentag.insert(3,date);
      date = date.addDays(+1);
      ui->Sa->setText(date.toString("dd"));
      Wochentag.insert(4,date);
      date = date.addDays(+1);
      ui->So->setText(date.toString("dd"));
      Wochentag.insert(5,date);
      date = date.addDays(-6);
      ui->Mo->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      break;
  case 3: //Mittwoch
      ui->Mi->setText(currentDate().toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(+1);
      ui->Do->setText(date.toString("dd"));
      Wochentag.insert(1,date);
      date = date.addDays(+1);
      ui->Fr->setText(date.toString("dd"));
      Wochentag.insert(2,date);
      date = date.addDays(+1);
      ui->Sa->setText(date.toString("dd"));
      Wochentag.insert(3,date);
      date = date.addDays(+1);
      ui->So->setText(date.toString("dd"));
      Wochentag.insert(4,date);
      date = date.addDays(-5);
      ui->Di->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Mo->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      break;
  case 4: //Donnerstag
      ui->Do->setText(currentDate().toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(+1);
      ui->Fr->setText(date.toString("dd"));
      Wochentag.insert(1,date);
      date = date.addDays(+1);
      ui->Sa->setText(date.toString("dd"));
      Wochentag.insert(2,date);
      date = date.addDays(+1);
      ui->So->setText(date.toString("dd"));
      Wochentag.insert(3,date);
      date = date.addDays(-4);
      ui->Mi->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Di->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Mo->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      break;
  case 5: //Freitag
      ui->Fr->setText(currentDate().toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(+1);
      ui->Sa->setText(date.toString("dd"));
      Wochentag.insert(1,date);
      date = date.addDays(+1);
      ui->So->setText(date.toString("dd"));
      Wochentag.insert(2,date);
      date = date.addDays(-3);
      ui->Do->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Mi->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Di->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Mo->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      break;
  case 6: //Samstag
      ui->Sa->setText(currentDate().toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(+1);
      ui->So->setText(date.toString("dd"));
      Wochentag.insert(1,date);
      date = date.addDays(-2);
      ui->Fr->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Do->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Mi->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Di->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      date = date.addDays(-1);
      ui->Mo->setText(date.toString("dd"));
      Wochentag.insert(0,date);
      break;
  }
}

void Wochenansicht::on_dayFrontButton_clicked()
{
    QDate date = currentDate();
    date = date.addDays(+7);
    setDate(date);
    weekday();


}

void Wochenansicht::on_dayBackButton_clicked()
{
    QDate date = currentDate();
    date = date.addDays(-7);
    setDate(date);
    weekday();


}

// Termin erstellen Button
void Wochenansicht::on_neuer_Termin_clicked()
{
    Termin_erstellen neuerTermin;
    neuerTermin.setModal(true);
    neuerTermin.exec();

    ansicht(lastDate);
}


//Fächer anschauen Button
void Wochenansicht::on_faecher_clicked()
{
    studifaecher faecher;
    faecher.setModal(true);
    faecher.exec();

}
//Profil anschauen Button
void Wochenansicht::on_profil_clicked()
{
    profil profil;
    profil.setModal(true);
    profil.exec();
}

void Wochenansicht::on_ansicht_currentTextChanged()
{
    QString ansicht=ui->ansicht->currentText();
        Monatsansicht monatsansicht;
        if(ansicht== "Monatsansicht"){
            this->hide();
            monatsansicht.setModal(true);
            monatsansicht.exec();}

        Tagesansicht tagesansicht;
        if(ansicht == "Tagesansicht")
        {this->hide();
            tagesansicht.setModal(true);
            tagesansicht.exec();}

}





void Wochenansicht::on_Mo_clicked()
{
    QDate Datum = Wochentag[0];//Die Werte die Gesucht sind
    ansicht(Datum);
    lastDate = Datum;
    QString calendarDay= Datum.toString("dd.MM.yyyy");

    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);

}

void Wochenansicht::on_Di_clicked()
{
    QDate Datum = Wochentag[1]; //Die Werte die Gesucht sind

    ansicht(Datum);
    lastDate = Datum;
    QString calendarDay= Datum.toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);
}

void Wochenansicht::on_Mi_clicked()
{
    QDate Datum = Wochentag[2];;//Die Werte die Gesucht sind

    ansicht(Datum);
    lastDate = Datum;
    QString calendarDay= Datum.toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);
}

void Wochenansicht::on_Do_clicked()
{
    QDate Datum = Wochentag[3];//Die Werte die Gesucht sind

    ansicht(Datum);
    lastDate = Datum;
    QString calendarDay= Datum.toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);
}

void Wochenansicht::on_Fr_clicked()
{
    QDate Datum = Wochentag[4];//Die Werte die Gesucht sind

    ansicht(Datum);
    lastDate = Datum;
    QString calendarDay= Datum.toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);
}

void Wochenansicht::on_Sa_clicked()
{
    QDate Datum = Wochentag[5];//Die Werte die Gesucht sind

    ansicht(Datum);
    lastDate = Datum;
    QString calendarDay= Datum.toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);
}

void Wochenansicht::on_So_clicked()
{
    QDate Datum = Wochentag[6];//Die Werte die Gesucht sind

    ansicht(Datum);
    lastDate = Datum;
    QString calendarDay= Datum.toString("dd.MM.yyyy");
    QString terminText="Deine Termine am " + calendarDay;
    ui->terminlabel->setText(terminText);
}

void Wochenansicht::on_Abmelden_destroyed()
{

}

void Wochenansicht::on_Abmelden_clicked()
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

void Wochenansicht::on_Lernplan_clicked()
{
    lernplanUI l;
    l.setModal(true);
    l.exec();
    ansicht(QDate::currentDate());
}




void Wochenansicht::on_Anzeige_doubleClicked(const QModelIndex &index)
{

        int a= index.row();
        QString i= ui->Anzeige->model()->data(ui->Anzeige->model()->index(a,0)).toString();
        Termin_bearbeiten bearbeiten;
        bearbeiten.setModal(true);
        bearbeiten.setData(i);
        bearbeiten.exec();
        ansicht(lastDate);



}

void Wochenansicht::on_exit_clicked()
{
    qApp->closeAllWindows();
    qApp->quit();
}
