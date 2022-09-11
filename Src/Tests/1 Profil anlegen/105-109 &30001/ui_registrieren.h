/********************************************************************************
** Form generated from reading UI file 'registrieren.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRIEREN_H
#define UI_REGISTRIEREN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Registrieren
{
public:
    QPushButton *Registrieren_2;
    QLineEdit *LEUsername;
    QLineEdit *LEPasswort;
    QLineEdit *LEPasswortwdh;
    QLineEdit *LEEMail;
    QLineEdit *LEs1;
    QLineEdit *LEs2;
    QLabel *label_7;
    QPushButton *login;
    QLabel *lbl5;
    QLabel *lbl4;
    QLabel *lbl2;
    QLabel *lbl3;
    QLabel *lbl1;
    QLabel *lbl7;
    QLabel *lbl6;
    QLabel *logo;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *exit;

    void setupUi(QDialog *Registrieren)
    {
        if (Registrieren->objectName().isEmpty())
            Registrieren->setObjectName(QString::fromUtf8("Registrieren"));
        Registrieren->resize(1920, 1080);
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        font.setPointSize(12);
        Registrieren->setFont(font);
        Registrieren->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Registrieren_2 = new QPushButton(Registrieren);
        Registrieren_2->setObjectName(QString::fromUtf8("Registrieren_2"));
        Registrieren_2->setGeometry(QRect(1020, 640, 131, 41));
        Registrieren_2->setFont(font);
        Registrieren_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"background-color: rgb(0, 121, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        LEUsername = new QLineEdit(Registrieren);
        LEUsername->setObjectName(QString::fromUtf8("LEUsername"));
        LEUsername->setGeometry(QRect(640, 320, 221, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MV Boli"));
        font1.setPointSize(11);
        LEUsername->setFont(font1);
        LEUsername->setStyleSheet(QString::fromUtf8(""));
        LEPasswort = new QLineEdit(Registrieren);
        LEPasswort->setObjectName(QString::fromUtf8("LEPasswort"));
        LEPasswort->setGeometry(QRect(640, 510, 221, 31));
        LEPasswort->setFont(font1);
        LEPasswort->setEchoMode(QLineEdit::Password);
        LEPasswortwdh = new QLineEdit(Registrieren);
        LEPasswortwdh->setObjectName(QString::fromUtf8("LEPasswortwdh"));
        LEPasswortwdh->setGeometry(QRect(640, 610, 221, 31));
        LEPasswortwdh->setFont(font1);
        LEPasswortwdh->setEchoMode(QLineEdit::Password);
        LEEMail = new QLineEdit(Registrieren);
        LEEMail->setObjectName(QString::fromUtf8("LEEMail"));
        LEEMail->setGeometry(QRect(640, 420, 221, 31));
        LEEMail->setFont(font1);
        LEs1 = new QLineEdit(Registrieren);
        LEs1->setObjectName(QString::fromUtf8("LEs1"));
        LEs1->setGeometry(QRect(970, 390, 281, 31));
        LEs1->setFont(font1);
        LEs2 = new QLineEdit(Registrieren);
        LEs2->setObjectName(QString::fromUtf8("LEs2"));
        LEs2->setGeometry(QRect(970, 550, 291, 31));
        LEs2->setFont(font1);
        label_7 = new QLabel(Registrieren);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(750, 150, 381, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MV Boli"));
        font2.setPointSize(18);
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 136, 0);"));
        login = new QPushButton(Registrieren);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(1660, 780, 201, 41));
        login->setFont(font);
        login->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  \n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"	background-color: rgb(255, 170, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        lbl5 = new QLabel(Registrieren);
        lbl5->setObjectName(QString::fromUtf8("lbl5"));
        lbl5->setGeometry(QRect(1170, 20, 74, 74));
        lbl4 = new QLabel(Registrieren);
        lbl4->setObjectName(QString::fromUtf8("lbl4"));
        lbl4->setGeometry(QRect(930, 20, 74, 74));
        lbl2 = new QLabel(Registrieren);
        lbl2->setObjectName(QString::fromUtf8("lbl2"));
        lbl2->setGeometry(QRect(430, 20, 74, 74));
        lbl3 = new QLabel(Registrieren);
        lbl3->setObjectName(QString::fromUtf8("lbl3"));
        lbl3->setGeometry(QRect(680, 20, 74, 74));
        lbl1 = new QLabel(Registrieren);
        lbl1->setObjectName(QString::fromUtf8("lbl1"));
        lbl1->setGeometry(QRect(180, 20, 74, 74));
        lbl7 = new QLabel(Registrieren);
        lbl7->setObjectName(QString::fromUtf8("lbl7"));
        lbl7->setGeometry(QRect(1680, 20, 74, 74));
        lbl6 = new QLabel(Registrieren);
        lbl6->setObjectName(QString::fromUtf8("lbl6"));
        lbl6->setGeometry(QRect(1420, 20, 74, 74));
        logo = new QLabel(Registrieren);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(190, 590, 911, 351));
        label_8 = new QLabel(Registrieren);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(970, 470, 441, 61));
        label_8->setFont(font);
        label_6 = new QLabel(Registrieren);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(970, 310, 311, 71));
        label_6->setFont(font);
        label = new QLabel(Registrieren);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 280, 171, 21));
        label->setFont(font);
        label_5 = new QLabel(Registrieren);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(640, 570, 231, 31));
        label_5->setFont(font);
        label_2 = new QLabel(Registrieren);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 480, 191, 21));
        label_2->setFont(font);
        label_3 = new QLabel(Registrieren);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(640, 380, 191, 31));
        label_3->setFont(font);
        exit = new QPushButton(Registrieren);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(1870, 10, 41, 41));
        exit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 22, 25);\n"
"\n"
"color: rgb(255, 255, 255);"));
        logo->raise();
        Registrieren_2->raise();
        LEUsername->raise();
        LEPasswort->raise();
        LEPasswortwdh->raise();
        LEEMail->raise();
        LEs1->raise();
        LEs2->raise();
        label_7->raise();
        login->raise();
        lbl5->raise();
        lbl4->raise();
        lbl2->raise();
        lbl3->raise();
        lbl1->raise();
        lbl7->raise();
        lbl6->raise();
        label_8->raise();
        label_6->raise();
        label->raise();
        label_5->raise();
        label_2->raise();
        label_3->raise();
        exit->raise();

        retranslateUi(Registrieren);

        QMetaObject::connectSlotsByName(Registrieren);
    } // setupUi

    void retranslateUi(QDialog *Registrieren)
    {
        Registrieren->setWindowTitle(QCoreApplication::translate("Registrieren", "Dialog", nullptr));
        Registrieren_2->setText(QCoreApplication::translate("Registrieren", "Registrieren", nullptr));
        label_7->setText(QCoreApplication::translate("Registrieren", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline; color:#7c0000;\">Registriere dich jetzt!</span></p></body></html>", nullptr));
        login->setText(QCoreApplication::translate("Registrieren", "Zur\303\274ck zum Login", nullptr));
        lbl5->setText(QCoreApplication::translate("Registrieren", "TextLabel", nullptr));
        lbl4->setText(QCoreApplication::translate("Registrieren", "TextLabel", nullptr));
        lbl2->setText(QCoreApplication::translate("Registrieren", "TextLabel", nullptr));
        lbl3->setText(QCoreApplication::translate("Registrieren", "TextLabel", nullptr));
        lbl1->setText(QCoreApplication::translate("Registrieren", "TextLabel", nullptr));
        lbl7->setText(QCoreApplication::translate("Registrieren", "TextLabel", nullptr));
        lbl6->setText(QCoreApplication::translate("Registrieren", "TextLabel", nullptr));
        logo->setText(QCoreApplication::translate("Registrieren", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("Registrieren", "<html><head/><body><p><span style=\" font-size:12pt;\">Sicherheitsfrage 2: </span></p><p><span style=\" font-size:12pt;\">Wie hei\303\237t der Geburtsname deiner Mutter?</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Registrieren", "<html><head/><body><p>Sicherheitsfrage 1: </p><p>Wie lautet dein Geburtsjahr?</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Registrieren", "Nutzername:", nullptr));
        label_5->setText(QCoreApplication::translate("Registrieren", "Passwort wiederholen:", nullptr));
        label_2->setText(QCoreApplication::translate("Registrieren", "Passwort:", nullptr));
        label_3->setText(QCoreApplication::translate("Registrieren", "E-Mail Adresse:", nullptr));
        exit->setText(QCoreApplication::translate("Registrieren", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registrieren: public Ui_Registrieren {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRIEREN_H
