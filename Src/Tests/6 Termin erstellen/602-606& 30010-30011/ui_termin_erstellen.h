/********************************************************************************
** Form generated from reading UI file 'termin_erstellen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMIN_ERSTELLEN_H
#define UI_TERMIN_ERSTELLEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_Termin_erstellen
{
public:
    QPushButton *termin_hinzufuegen;
    QPushButton *abbrechen;
    QLabel *label_2;
    QLabel *label_12;
    QLabel *l1;
    QLabel *l3;
    QLabel *l2;
    QLabel *l4;
    QLineEdit *Titel;
    QCheckBox *erledigt;
    QTimeEdit *Erinnerung;
    QLabel *label_8;
    QLabel *label_10;
    QTimeEdit *ende;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_14;
    QTimeEdit *beginn;
    QSpinBox *wiederholungen;
    QLabel *label_15;
    QDateEdit *Datum;
    QLabel *label_16;
    QLineEdit *beschreibung;

    void setupUi(QDialog *Termin_erstellen)
    {
        if (Termin_erstellen->objectName().isEmpty())
            Termin_erstellen->setObjectName(QString::fromUtf8("Termin_erstellen"));
        Termin_erstellen->resize(714, 846);
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        Termin_erstellen->setFont(font);
        Termin_erstellen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        termin_hinzufuegen = new QPushButton(Termin_erstellen);
        termin_hinzufuegen->setObjectName(QString::fromUtf8("termin_hinzufuegen"));
        termin_hinzufuegen->setGeometry(QRect(240, 720, 201, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MV Boli"));
        font1.setPointSize(12);
        termin_hinzufuegen->setFont(font1);
        termin_hinzufuegen->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"  \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(0, 121, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        abbrechen = new QPushButton(Termin_erstellen);
        abbrechen->setObjectName(QString::fromUtf8("abbrechen"));
        abbrechen->setGeometry(QRect(550, 790, 141, 41));
        abbrechen->setFont(font1);
        abbrechen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(255, 170, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        label_2 = new QLabel(Termin_erstellen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 140, 291, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(0, 0, 127);"));
        label_12 = new QLabel(Termin_erstellen);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(-2, 70, 721, 51));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 24, 1);"));
        l1 = new QLabel(Termin_erstellen);
        l1->setObjectName(QString::fromUtf8("l1"));
        l1->setGeometry(QRect(78, -10, 74, 74));
        l3 = new QLabel(Termin_erstellen);
        l3->setObjectName(QString::fromUtf8("l3"));
        l3->setGeometry(QRect(398, -10, 74, 74));
        l2 = new QLabel(Termin_erstellen);
        l2->setObjectName(QString::fromUtf8("l2"));
        l2->setGeometry(QRect(228, -10, 74, 74));
        l4 = new QLabel(Termin_erstellen);
        l4->setObjectName(QString::fromUtf8("l4"));
        l4->setGeometry(QRect(558, -10, 74, 74));
        Titel = new QLineEdit(Termin_erstellen);
        Titel->setObjectName(QString::fromUtf8("Titel"));
        Titel->setGeometry(QRect(160, 240, 141, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MV Boli"));
        font2.setPointSize(10);
        Titel->setFont(font2);
        Titel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        erledigt = new QCheckBox(Termin_erstellen);
        erledigt->setObjectName(QString::fromUtf8("erledigt"));
        erledigt->setGeometry(QRect(440, 620, 101, 51));
        erledigt->setFont(font1);
        Erinnerung = new QTimeEdit(Termin_erstellen);
        Erinnerung->setObjectName(QString::fromUtf8("Erinnerung"));
        Erinnerung->setGeometry(QRect(280, 550, 141, 31));
        Erinnerung->setFont(font2);
        Erinnerung->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(Termin_erstellen);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(350, 240, 71, 31));
        label_8->setFont(font1);
        label_10 = new QLabel(Termin_erstellen);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(70, 380, 551, 41));
        label_10->setFont(font1);
        ende = new QTimeEdit(Termin_erstellen);
        ende->setObjectName(QString::fromUtf8("ende"));
        ende->setGeometry(QRect(440, 310, 141, 31));
        ende->setFont(font2);
        ende->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_11 = new QLabel(Termin_erstellen);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(90, 240, 61, 31));
        label_11->setFont(font1);
        label_13 = new QLabel(Termin_erstellen);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(370, 310, 61, 31));
        label_13->setFont(font1);
        label_14 = new QLabel(Termin_erstellen);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(80, 500, 541, 31));
        label_14->setFont(font1);
        beginn = new QTimeEdit(Termin_erstellen);
        beginn->setObjectName(QString::fromUtf8("beginn"));
        beginn->setGeometry(QRect(160, 310, 141, 31));
        beginn->setFont(font2);
        beginn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        wiederholungen = new QSpinBox(Termin_erstellen);
        wiederholungen->setObjectName(QString::fromUtf8("wiederholungen"));
        wiederholungen->setGeometry(QRect(320, 430, 61, 31));
        wiederholungen->setFont(font2);
        wiederholungen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_15 = new QLabel(Termin_erstellen);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(80, 310, 71, 31));
        label_15->setFont(font1);
        Datum = new QDateEdit(Termin_erstellen);
        Datum->setObjectName(QString::fromUtf8("Datum"));
        Datum->setGeometry(QRect(440, 240, 141, 31));
        Datum->setFont(font2);
        Datum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_16 = new QLabel(Termin_erstellen);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(100, 620, 131, 41));
        label_16->setFont(font1);
        beschreibung = new QLineEdit(Termin_erstellen);
        beschreibung->setObjectName(QString::fromUtf8("beschreibung"));
        beschreibung->setGeometry(QRect(240, 630, 141, 31));
        beschreibung->setFont(font2);
        beschreibung->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(Termin_erstellen);

        QMetaObject::connectSlotsByName(Termin_erstellen);
    } // setupUi

    void retranslateUi(QDialog *Termin_erstellen)
    {
        Termin_erstellen->setWindowTitle(QCoreApplication::translate("Termin_erstellen", "Termin hinzuf\303\274gen", nullptr));
        termin_hinzufuegen->setText(QCoreApplication::translate("Termin_erstellen", "Termin hinzuf\303\274gen", nullptr));
        abbrechen->setText(QCoreApplication::translate("Termin_erstellen", "Abbrechen", nullptr));
        label_2->setText(QCoreApplication::translate("Termin_erstellen", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; text-decoration: underline;\">Termin hinzuf\303\274gen</span></p></body></html>", nullptr));
        label_12->setText(QString());
        l1->setText(QCoreApplication::translate("Termin_erstellen", "TextLabel", nullptr));
        l3->setText(QCoreApplication::translate("Termin_erstellen", "TextLabel", nullptr));
        l2->setText(QCoreApplication::translate("Termin_erstellen", "TextLabel", nullptr));
        l4->setText(QCoreApplication::translate("Termin_erstellen", "TextLabel", nullptr));
        erledigt->setText(QCoreApplication::translate("Termin_erstellen", "erledigt", nullptr));
        label_8->setText(QCoreApplication::translate("Termin_erstellen", "Datum:", nullptr));
        label_10->setText(QCoreApplication::translate("Termin_erstellen", "Wie oft soll der Termin w\303\266chentlich wiederholt werden?", nullptr));
        label_11->setText(QCoreApplication::translate("Termin_erstellen", "Titel:", nullptr));
        label_13->setText(QCoreApplication::translate("Termin_erstellen", "Ende:", nullptr));
        label_14->setText(QCoreApplication::translate("Termin_erstellen", "Um welche Uhrzeit davor wollen Sie erinnert werden?", nullptr));
        label_15->setText(QCoreApplication::translate("Termin_erstellen", "Beginn:", nullptr));
        label_16->setText(QCoreApplication::translate("Termin_erstellen", "Beschreibung:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Termin_erstellen: public Ui_Termin_erstellen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMIN_ERSTELLEN_H
