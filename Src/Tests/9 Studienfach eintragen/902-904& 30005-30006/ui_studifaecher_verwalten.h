/********************************************************************************
** Form generated from reading UI file 'studifaecher_verwalten.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDIFAECHER_VERWALTEN_H
#define UI_STUDIFAECHER_VERWALTEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Studifaecher_verwalten
{
public:
    QLineEdit *ID;
    QSpinBox *sws;
    QSpinBox *ects;
    QSpinBox *stunden;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *name;
    QLabel *label_5;
    QPushButton *abbrechen;
    QPushButton *speichern;
    QPushButton *loeschen;
    QLabel *label;
    QLabel *label_12;
    QLabel *l1;
    QLabel *l2;
    QLabel *l4;
    QLabel *l3;

    void setupUi(QDialog *Studifaecher_verwalten)
    {
        if (Studifaecher_verwalten->objectName().isEmpty())
            Studifaecher_verwalten->setObjectName(QString::fromUtf8("Studifaecher_verwalten"));
        Studifaecher_verwalten->resize(714, 714);
        QFont font;
        font.setPointSize(10);
        Studifaecher_verwalten->setFont(font);
        Studifaecher_verwalten->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ID = new QLineEdit(Studifaecher_verwalten);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setGeometry(QRect(340, 230, 71, 20));
        sws = new QSpinBox(Studifaecher_verwalten);
        sws->setObjectName(QString::fromUtf8("sws"));
        sws->setGeometry(QRect(330, 370, 61, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MV Boli"));
        font1.setPointSize(10);
        sws->setFont(font1);
        sws->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ects = new QSpinBox(Studifaecher_verwalten);
        ects->setObjectName(QString::fromUtf8("ects"));
        ects->setGeometry(QRect(330, 300, 61, 31));
        ects->setFont(font1);
        ects->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stunden = new QSpinBox(Studifaecher_verwalten);
        stunden->setObjectName(QString::fromUtf8("stunden"));
        stunden->setGeometry(QRect(330, 490, 61, 31));
        stunden->setFont(font1);
        stunden->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(Studifaecher_verwalten);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 430, 541, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MV Boli"));
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_3 = new QLabel(Studifaecher_verwalten);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 300, 61, 20));
        label_3->setFont(font2);
        label_4 = new QLabel(Studifaecher_verwalten);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(264, 370, 61, 21));
        label_4->setFont(font2);
        name = new QLineEdit(Studifaecher_verwalten);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(260, 230, 221, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MV Boli"));
        font3.setPointSize(11);
        name->setFont(font3);
        name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(Studifaecher_verwalten);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 230, 61, 20));
        label_5->setFont(font2);
        abbrechen = new QPushButton(Studifaecher_verwalten);
        abbrechen->setObjectName(QString::fromUtf8("abbrechen"));
        abbrechen->setGeometry(QRect(560, 660, 121, 41));
        abbrechen->setFont(font2);
        abbrechen->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 170, 0);\n"
"}"));
        speichern = new QPushButton(Studifaecher_verwalten);
        speichern->setObjectName(QString::fromUtf8("speichern"));
        speichern->setGeometry(QRect(400, 560, 121, 41));
        speichern->setFont(font2);
        speichern->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(0, 121, 0);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
""));
        loeschen = new QPushButton(Studifaecher_verwalten);
        loeschen->setObjectName(QString::fromUtf8("loeschen"));
        loeschen->setGeometry(QRect(190, 560, 121, 41));
        loeschen->setFont(font2);
        loeschen->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"  \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(200, 24, 1);\n"
"}"));
        label = new QLabel(Studifaecher_verwalten);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 140, 521, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("MV Boli"));
        font4.setPointSize(18);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);"));
        label_12 = new QLabel(Studifaecher_verwalten);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 70, 721, 51));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 24, 1);"));
        l1 = new QLabel(Studifaecher_verwalten);
        l1->setObjectName(QString::fromUtf8("l1"));
        l1->setGeometry(QRect(80, -10, 74, 74));
        l2 = new QLabel(Studifaecher_verwalten);
        l2->setObjectName(QString::fromUtf8("l2"));
        l2->setGeometry(QRect(230, -10, 74, 74));
        l4 = new QLabel(Studifaecher_verwalten);
        l4->setObjectName(QString::fromUtf8("l4"));
        l4->setGeometry(QRect(560, -10, 74, 74));
        l3 = new QLabel(Studifaecher_verwalten);
        l3->setObjectName(QString::fromUtf8("l3"));
        l3->setGeometry(QRect(400, -10, 74, 74));

        retranslateUi(Studifaecher_verwalten);

        QMetaObject::connectSlotsByName(Studifaecher_verwalten);
    } // setupUi

    void retranslateUi(QDialog *Studifaecher_verwalten)
    {
        Studifaecher_verwalten->setWindowTitle(QCoreApplication::translate("Studifaecher_verwalten", "Studeinf\303\244cher bearbeiten/l\303\266schen", nullptr));
        label_2->setText(QCoreApplication::translate("Studifaecher_verwalten", "Wie viele Stunden in der Woche willst du daf\303\274r lernen?", nullptr));
        label_3->setText(QCoreApplication::translate("Studifaecher_verwalten", "ECTS:", nullptr));
        label_4->setText(QCoreApplication::translate("Studifaecher_verwalten", "SWS:", nullptr));
        label_5->setText(QCoreApplication::translate("Studifaecher_verwalten", "Name:", nullptr));
        abbrechen->setText(QCoreApplication::translate("Studifaecher_verwalten", "Abbrechen", nullptr));
        speichern->setText(QCoreApplication::translate("Studifaecher_verwalten", "Speichern", nullptr));
        loeschen->setText(QCoreApplication::translate("Studifaecher_verwalten", "L\303\266schen", nullptr));
        label->setText(QCoreApplication::translate("Studifaecher_verwalten", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Studienf\303\244cher bearbieten/l\303\266schen</span></p></body></html>", nullptr));
        label_12->setText(QString());
        l1->setText(QCoreApplication::translate("Studifaecher_verwalten", "TextLabel", nullptr));
        l2->setText(QCoreApplication::translate("Studifaecher_verwalten", "TextLabel", nullptr));
        l4->setText(QCoreApplication::translate("Studifaecher_verwalten", "TextLabel", nullptr));
        l3->setText(QCoreApplication::translate("Studifaecher_verwalten", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Studifaecher_verwalten: public Ui_Studifaecher_verwalten {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDIFAECHER_VERWALTEN_H
