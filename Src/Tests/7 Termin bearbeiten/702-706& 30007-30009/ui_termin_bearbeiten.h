/********************************************************************************
** Form generated from reading UI file 'termin_bearbeiten.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMIN_BEARBEITEN_H
#define UI_TERMIN_BEARBEITEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_Termin_bearbeiten
{
public:
    QLabel *label;
    QPushButton *Termin_loeschen;
    QPushButton *speichern;
    QPushButton *abbrechen;
    QDateEdit *Datum;
    QTimeEdit *beginn;
    QLabel *label_2;
    QLabel *label_3;
    QTimeEdit *Erinnerung;
    QLineEdit *Titel;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTimeEdit *ende;
    QLabel *label_9;
    QLineEdit *beschreibung;
    QCheckBox *erledigt;
    QLineEdit *Id;
    QLabel *l1;
    QLabel *l3;
    QLabel *l2;
    QLabel *l4;
    QLabel *label_12;

    void setupUi(QDialog *Termin_bearbeiten)
    {
        if (Termin_bearbeiten->objectName().isEmpty())
            Termin_bearbeiten->setObjectName(QString::fromUtf8("Termin_bearbeiten"));
        Termin_bearbeiten->resize(714, 846);
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        Termin_bearbeiten->setFont(font);
        Termin_bearbeiten->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(Termin_bearbeiten);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 140, 411, 71));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);"));
        Termin_loeschen = new QPushButton(Termin_bearbeiten);
        Termin_loeschen->setObjectName(QString::fromUtf8("Termin_loeschen"));
        Termin_loeschen->setGeometry(QRect(160, 640, 161, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MV Boli"));
        font1.setPointSize(12);
        Termin_loeschen->setFont(font1);
        Termin_loeschen->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"  \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(200, 24, 1);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        speichern = new QPushButton(Termin_bearbeiten);
        speichern->setObjectName(QString::fromUtf8("speichern"));
        speichern->setGeometry(QRect(390, 640, 151, 41));
        speichern->setFont(font1);
        speichern->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(0, 121, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        abbrechen = new QPushButton(Termin_bearbeiten);
        abbrechen->setObjectName(QString::fromUtf8("abbrechen"));
        abbrechen->setGeometry(QRect(540, 790, 151, 41));
        abbrechen->setFont(font1);
        abbrechen->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"  \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(255, 170, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        Datum = new QDateEdit(Termin_bearbeiten);
        Datum->setObjectName(QString::fromUtf8("Datum"));
        Datum->setGeometry(QRect(450, 250, 141, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MV Boli"));
        font2.setPointSize(10);
        Datum->setFont(font2);
        Datum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        beginn = new QTimeEdit(Termin_bearbeiten);
        beginn->setObjectName(QString::fromUtf8("beginn"));
        beginn->setGeometry(QRect(200, 330, 141, 31));
        beginn->setFont(font2);
        beginn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(Termin_bearbeiten);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 530, 131, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(Termin_bearbeiten);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 410, 541, 31));
        label_3->setFont(font1);
        Erinnerung = new QTimeEdit(Termin_bearbeiten);
        Erinnerung->setObjectName(QString::fromUtf8("Erinnerung"));
        Erinnerung->setGeometry(QRect(300, 460, 141, 31));
        Erinnerung->setFont(font2);
        Erinnerung->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Titel = new QLineEdit(Termin_bearbeiten);
        Titel->setObjectName(QString::fromUtf8("Titel"));
        Titel->setGeometry(QRect(200, 250, 141, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MV Boli"));
        font3.setPointSize(11);
        Titel->setFont(font3);
        Titel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        label_6 = new QLabel(Termin_bearbeiten);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 250, 61, 21));
        label_6->setFont(font1);
        label_7 = new QLabel(Termin_bearbeiten);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(360, 250, 81, 21));
        label_7->setFont(font1);
        label_8 = new QLabel(Termin_bearbeiten);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(120, 330, 71, 21));
        label_8->setFont(font1);
        ende = new QTimeEdit(Termin_bearbeiten);
        ende->setObjectName(QString::fromUtf8("ende"));
        ende->setGeometry(QRect(450, 330, 141, 31));
        ende->setFont(font2);
        ende->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(Termin_bearbeiten);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(380, 330, 61, 21));
        label_9->setFont(font1);
        beschreibung = new QLineEdit(Termin_bearbeiten);
        beschreibung->setObjectName(QString::fromUtf8("beschreibung"));
        beschreibung->setGeometry(QRect(250, 540, 151, 31));
        beschreibung->setFont(font3);
        beschreibung->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        erledigt = new QCheckBox(Termin_bearbeiten);
        erledigt->setObjectName(QString::fromUtf8("erledigt"));
        erledigt->setGeometry(QRect(450, 530, 101, 41));
        erledigt->setFont(font1);
        Id = new QLineEdit(Termin_bearbeiten);
        Id->setObjectName(QString::fromUtf8("Id"));
        Id->setGeometry(QRect(240, 250, 81, 20));
        l1 = new QLabel(Termin_bearbeiten);
        l1->setObjectName(QString::fromUtf8("l1"));
        l1->setGeometry(QRect(80, -10, 74, 74));
        l3 = new QLabel(Termin_bearbeiten);
        l3->setObjectName(QString::fromUtf8("l3"));
        l3->setGeometry(QRect(400, -10, 74, 74));
        l2 = new QLabel(Termin_bearbeiten);
        l2->setObjectName(QString::fromUtf8("l2"));
        l2->setGeometry(QRect(230, -10, 74, 74));
        l4 = new QLabel(Termin_bearbeiten);
        l4->setObjectName(QString::fromUtf8("l4"));
        l4->setGeometry(QRect(560, -10, 74, 74));
        label_12 = new QLabel(Termin_bearbeiten);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 70, 721, 51));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 24, 1);"));
        Id->raise();
        label->raise();
        Termin_loeschen->raise();
        speichern->raise();
        abbrechen->raise();
        Datum->raise();
        beginn->raise();
        label_2->raise();
        label_3->raise();
        Erinnerung->raise();
        Titel->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        ende->raise();
        label_9->raise();
        beschreibung->raise();
        erledigt->raise();
        l1->raise();
        l3->raise();
        l2->raise();
        l4->raise();
        label_12->raise();

        retranslateUi(Termin_bearbeiten);

        QMetaObject::connectSlotsByName(Termin_bearbeiten);
    } // setupUi

    void retranslateUi(QDialog *Termin_bearbeiten)
    {
        Termin_bearbeiten->setWindowTitle(QCoreApplication::translate("Termin_bearbeiten", "Termin bearbeiten/l\303\266schen", nullptr));
        label->setText(QCoreApplication::translate("Termin_bearbeiten", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; text-decoration: underline;\">Termin bearbeiten/l\303\266schen</span></p></body></html>", nullptr));
        Termin_loeschen->setText(QCoreApplication::translate("Termin_bearbeiten", "Termin l\303\266schen", nullptr));
        speichern->setText(QCoreApplication::translate("Termin_bearbeiten", "Speichern", nullptr));
        abbrechen->setText(QCoreApplication::translate("Termin_bearbeiten", "Abbrechen", nullptr));
        label_2->setText(QCoreApplication::translate("Termin_bearbeiten", "Beschreibung:", nullptr));
        label_3->setText(QCoreApplication::translate("Termin_bearbeiten", "Um welche Uhrzeit davor wollen Sie erinnert werden?", nullptr));
        label_6->setText(QCoreApplication::translate("Termin_bearbeiten", "Titel:", nullptr));
        label_7->setText(QCoreApplication::translate("Termin_bearbeiten", "Datum:", nullptr));
        label_8->setText(QCoreApplication::translate("Termin_bearbeiten", "Beginn:", nullptr));
        label_9->setText(QCoreApplication::translate("Termin_bearbeiten", "Ende:", nullptr));
        erledigt->setText(QCoreApplication::translate("Termin_bearbeiten", "erledigt", nullptr));
        l1->setText(QCoreApplication::translate("Termin_bearbeiten", "TextLabel", nullptr));
        l3->setText(QCoreApplication::translate("Termin_bearbeiten", "TextLabel", nullptr));
        l2->setText(QCoreApplication::translate("Termin_bearbeiten", "TextLabel", nullptr));
        l4->setText(QCoreApplication::translate("Termin_bearbeiten", "TextLabel", nullptr));
        label_12->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Termin_bearbeiten: public Ui_Termin_bearbeiten {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMIN_BEARBEITEN_H
