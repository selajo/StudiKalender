/********************************************************************************
** Form generated from reading UI file 'studifaecher.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDIFAECHER_H
#define UI_STUDIFAECHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_studifaecher
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *name;
    QSpinBox *sws;
    QSpinBox *ects;
    QSpinBox *stunden;
    QPushButton *abbrechen;
    QTableView *faecher;
    QLabel *label_6;
    QPushButton *speichern;
    QFrame *line;
    QLabel *l1;
    QLabel *l2;
    QLabel *l3;
    QLabel *l4;
    QLabel *l5;
    QLabel *l6;
    QLabel *l7;
    QLabel *logo;

    void setupUi(QDialog *studifaecher)
    {
        if (studifaecher->objectName().isEmpty())
            studifaecher->setObjectName(QString::fromUtf8("studifaecher"));
        studifaecher->resize(1920, 1080);
        studifaecher->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 248);\n"
""));
        label = new QLabel(studifaecher);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(820, 140, 271, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        font.setPointSize(24);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 144);"));
        label_2 = new QLabel(studifaecher);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 440, 61, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MV Boli"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(studifaecher);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(500, 580, 51, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(studifaecher);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(500, 510, 55, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(studifaecher);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 640, 571, 41));
        label_5->setFont(font1);
        name = new QLineEdit(studifaecher);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(530, 440, 221, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MV Boli"));
        font2.setPointSize(11);
        name->setFont(font2);
        name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        sws = new QSpinBox(studifaecher);
        sws->setObjectName(QString::fromUtf8("sws"));
        sws->setGeometry(QRect(570, 580, 61, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MV Boli"));
        font3.setPointSize(10);
        sws->setFont(font3);
        sws->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ects = new QSpinBox(studifaecher);
        ects->setObjectName(QString::fromUtf8("ects"));
        ects->setGeometry(QRect(570, 510, 61, 31));
        ects->setFont(font3);
        ects->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stunden = new QSpinBox(studifaecher);
        stunden->setObjectName(QString::fromUtf8("stunden"));
        stunden->setGeometry(QRect(570, 700, 61, 31));
        stunden->setFont(font3);
        stunden->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        abbrechen = new QPushButton(studifaecher);
        abbrechen->setObjectName(QString::fromUtf8("abbrechen"));
        abbrechen->setGeometry(QRect(1670, 910, 211, 41));
        abbrechen->setFont(font1);
        abbrechen->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
" \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(255, 170, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        faecher = new QTableView(studifaecher);
        faecher->setObjectName(QString::fromUtf8("faecher"));
        faecher->setGeometry(QRect(1160, 310, 631, 451));
        faecher->setStyleSheet(QString::fromUtf8("QTableView\n"
"\n"
"{\n"
"  border: 2px solid rgb(0, 0, 127);\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        label_6 = new QLabel(studifaecher);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(440, 350, 351, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("MV Boli"));
        font4.setPointSize(14);
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"\n"
""));
        speichern = new QPushButton(studifaecher);
        speichern->setObjectName(QString::fromUtf8("speichern"));
        speichern->setGeometry(QRect(540, 790, 121, 41));
        speichern->setFont(font1);
        speichern->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(0, 121, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        line = new QFrame(studifaecher);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 120, 1921, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        l1 = new QLabel(studifaecher);
        l1->setObjectName(QString::fromUtf8("l1"));
        l1->setGeometry(QRect(170, 0, 74, 74));
        l2 = new QLabel(studifaecher);
        l2->setObjectName(QString::fromUtf8("l2"));
        l2->setGeometry(QRect(420, 0, 74, 74));
        l3 = new QLabel(studifaecher);
        l3->setObjectName(QString::fromUtf8("l3"));
        l3->setGeometry(QRect(670, 0, 74, 74));
        l4 = new QLabel(studifaecher);
        l4->setObjectName(QString::fromUtf8("l4"));
        l4->setGeometry(QRect(920, 0, 74, 74));
        l5 = new QLabel(studifaecher);
        l5->setObjectName(QString::fromUtf8("l5"));
        l5->setGeometry(QRect(1170, 0, 74, 74));
        l6 = new QLabel(studifaecher);
        l6->setObjectName(QString::fromUtf8("l6"));
        l6->setGeometry(QRect(1420, 0, 74, 74));
        l7 = new QLabel(studifaecher);
        l7->setObjectName(QString::fromUtf8("l7"));
        l7->setGeometry(QRect(1670, 0, 74, 74));
        logo = new QLabel(studifaecher);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(840, 920, 248, 140));

        retranslateUi(studifaecher);

        QMetaObject::connectSlotsByName(studifaecher);
    } // setupUi

    void retranslateUi(QDialog *studifaecher)
    {
        studifaecher->setWindowTitle(QCoreApplication::translate("studifaecher", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("studifaecher", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Studienf\303\244cher</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("studifaecher", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("studifaecher", "SWS:", nullptr));
        label_4->setText(QCoreApplication::translate("studifaecher", "ECTS:", nullptr));
        label_5->setText(QCoreApplication::translate("studifaecher", "Wie viele Stunden in der Woche willst du daf\303\274r lernen?", nullptr));
        abbrechen->setText(QCoreApplication::translate("studifaecher", "Zur\303\274ck zur Ansicht", nullptr));
        label_6->setText(QCoreApplication::translate("studifaecher", "Neues Studienfach hinzuf\303\274gen:", nullptr));
        speichern->setText(QCoreApplication::translate("studifaecher", "Speichern", nullptr));
        l1->setText(QCoreApplication::translate("studifaecher", "TextLabel", nullptr));
        l2->setText(QCoreApplication::translate("studifaecher", "TextLabel", nullptr));
        l3->setText(QCoreApplication::translate("studifaecher", "TextLabel", nullptr));
        l4->setText(QCoreApplication::translate("studifaecher", "TextLabel", nullptr));
        l5->setText(QCoreApplication::translate("studifaecher", "TextLabel", nullptr));
        l6->setText(QCoreApplication::translate("studifaecher", "TextLabel", nullptr));
        l7->setText(QCoreApplication::translate("studifaecher", "TextLabel", nullptr));
        logo->setText(QCoreApplication::translate("studifaecher", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studifaecher: public Ui_studifaecher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDIFAECHER_H
