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
#include "Datenbank.h"
#include "QList_Model_AusgabeTagesansicht.h"
#include "Globals.h"
#include <QStyle>
#include <QCommonStyle>




/*
 * Author: Irma Krieger
 *
 */

extern NProfil NP;

Wochenansicht::Wochenansicht(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wochenansicht)
{
    ui->setupUi(this);
    ui->calendarWidget->setNavigationBarVisible(false);
    ui->calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);


    ui->DateLable->setText(ui->calendarWidget->selectedDate().toString("dd MMMM yyyy"));
    weekday(2010, 10, 4); //Random Wert, der später geändert wird
    QCommonStyle styleForward;
    ui->dayFrontButton->setIcon(styleForward.standardIcon(QStyle::SP_ArrowRight));
    QCommonStyle styleBackward;
    ui->dayBackButton->setIcon(styleBackward.standardIcon(QStyle::SP_ArrowLeft));


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
void Wochenansicht::weekday(int y, int m, int d)
{
    d = QDate::currentDate().day();
    m = QDate::currentDate().month();
    y = QDate::currentDate().year();

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
    weekday(1, 2, 3);

}

void Wochenansicht::on_dayBackButton_clicked()
{
    QDate date = currentDate();
    date = date.addDays(-7);
    setDate(date);
    weekday(1, 2, 3);

}

// Termin erstellen Button
void Wochenansicht::on_neuer_Termin_clicked()
{
    Termin_erstellen neuerTermin;
    neuerTermin.setModal(true);
    neuerTermin.exec();

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

void Wochenansicht::on_ansicht_currentTextChanged(const QString &arg1)
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


    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = Wochentag[0];//Die Werte die Gesucht sind


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
    TestModel *WochenansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    WochenansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->Anzeige->setModel(WochenansichtModel);

    // zeige die Tabelle an:
    ui->Anzeige->horizontalHeader()->setVisible(true);
    ui->Anzeige->show();


    //Test Datenbank
    conn->connClose();

}

void Wochenansicht::on_Di_clicked()
{

    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = Wochentag[1]; //Die Werte die Gesucht sind


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
    TestModel *WochenansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    WochenansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->Anzeige->setModel(WochenansichtModel);

    // zeige die Tabelle an:
    ui->Anzeige->horizontalHeader()->setVisible(true);
    ui->Anzeige->show();

    //Test Datenbank
    conn->connClose();
}

void Wochenansicht::on_Mi_clicked()
{


    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = Wochentag[2];;//Die Werte die Gesucht sind


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
    TestModel *WochenansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    WochenansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->Anzeige->setModel(WochenansichtModel);

    // zeige die Tabelle an:
    ui->Anzeige->horizontalHeader()->setVisible(true);
    ui->Anzeige->show();


    //Test Datenbank
    conn->connClose();
}

void Wochenansicht::on_Do_clicked()
{


    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = Wochentag[3];//Die Werte die Gesucht sind


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
    TestModel *WochenansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    WochenansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->Anzeige->setModel(WochenansichtModel);

    // zeige die Tabelle an:
    ui->Anzeige->horizontalHeader()->setVisible(true);
    ui->Anzeige->show();


    //Test Datenbank
    conn->connClose();
}

void Wochenansicht::on_Fr_clicked()
{

    QDate date = selectedDate();
    setDate(date);

    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = Wochentag[4];//Die Werte die Gesucht sind


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
    TestModel *WochenansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    WochenansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->Anzeige->setModel(WochenansichtModel);

    // zeige die Tabelle an:
    ui->Anzeige->horizontalHeader()->setVisible(true);
    ui->Anzeige->show();


    //Test Datenbank
    conn->connClose();
}

void Wochenansicht::on_Sa_clicked()
{


    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = Wochentag[5];//Die Werte die Gesucht sind


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
        TestModel *WochenansichtModel = new TestModel(this);

        // Model mit den Daten von den QListen füllen:
        WochenansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

        // Verbinde Tabelle mit Tabellenansicht:
        ui->Anzeige->setModel(WochenansichtModel);

        // zeige die Tabelle an:
        ui->Anzeige->horizontalHeader()->setVisible(true);
        ui->Anzeige->show();


    //Test Datenbank
    conn->connClose();
}

void Wochenansicht::on_So_clicked()
{
    QDate date = selectedDate();
    setDate(date);

    Datenbank * conn = Datenbank::getInstance();
    QSqlQueryModel * model = new QSqlQueryModel();
    conn->connOpen();


    QDate Datum = Wochentag[6];//Die Werte die Gesucht sind


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
    TestModel *WochenansichtModel = new TestModel(this);

    // Model mit den Daten von den QListen füllen:
    WochenansichtModel->populateData(BLidTermin,BLTerminname,BLDatum,BLBeginn,BLEnde);

    // Verbinde Tabelle mit Tabellenansicht:
    ui->Anzeige->setModel(WochenansichtModel);

    // zeige die Tabelle an:
    ui->Anzeige->horizontalHeader()->setVisible(true);
    ui->Anzeige->show();


    //Test Datenbank
    conn->connClose();
}
