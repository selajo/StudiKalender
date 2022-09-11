/********************************************************************************
** Form generated from reading UI file 'pbearbeiten.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PBEARBEITEN_H
#define UI_PBEARBEITEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PBearbeiten
{
public:
    QLabel *lblUsername;
    QLabel *berschhirft;
    QPushButton *ButtonProfil;
    QLabel *Username;
    QPushButton *ButtonExit;
    QLabel *lblemail_3;
    QLineEdit *email;
    QLineEdit *passwortAlt;
    QLineEdit *passwortNeu;
    QLabel *lblemail_2;
    QLabel *lblemail;
    QPushButton *ProfilLoeschen;
    QLabel *profilePicture;
    QLabel *blackBackround;
    QLabel *LogoKlein;
    QLabel *lbl1;
    QLabel *lbl2;
    QLabel *lbl4;
    QLabel *lbl3;
    QLabel *label_12;
    QPushButton *ProfilbildHochladen;

    void setupUi(QWidget *PBearbeiten)
    {
        if (PBearbeiten->objectName().isEmpty())
            PBearbeiten->setObjectName(QString::fromUtf8("PBearbeiten"));
        PBearbeiten->resize(820, 720);
        PBearbeiten->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lblUsername = new QLabel(PBearbeiten);
        lblUsername->setObjectName(QString::fromUtf8("lblUsername"));
        lblUsername->setGeometry(QRect(40, 180, 171, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        font.setPointSize(12);
        lblUsername->setFont(font);
        berschhirft = new QLabel(PBearbeiten);
        berschhirft->setObjectName(QString::fromUtf8("berschhirft"));
        berschhirft->setGeometry(QRect(300, 110, 141, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MV Boli"));
        font1.setPointSize(18);
        berschhirft->setFont(font1);
        ButtonProfil = new QPushButton(PBearbeiten);
        ButtonProfil->setObjectName(QString::fromUtf8("ButtonProfil"));
        ButtonProfil->setGeometry(QRect(280, 470, 161, 41));
        ButtonProfil->setFont(font);
        ButtonProfil->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonProfil->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 121, 0);\n"
"}\n"
""));
        Username = new QLabel(PBearbeiten);
        Username->setObjectName(QString::fromUtf8("Username"));
        Username->setGeometry(QRect(40, 210, 421, 31));
        Username->setFont(font);
        Username->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        ButtonExit = new QPushButton(PBearbeiten);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        ButtonExit->setGeometry(QRect(280, 520, 161, 41));
        ButtonExit->setFont(font);
        ButtonExit->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonExit->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 170, 0);\n"
"}\n"
""));
        lblemail_3 = new QLabel(PBearbeiten);
        lblemail_3->setObjectName(QString::fromUtf8("lblemail_3"));
        lblemail_3->setGeometry(QRect(540, 370, 171, 21));
        lblemail_3->setFont(font);
        lblemail_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 22, 25);"));
        email = new QLineEdit(PBearbeiten);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(40, 300, 261, 41));
        email->setFont(font);
        passwortAlt = new QLineEdit(PBearbeiten);
        passwortAlt->setObjectName(QString::fromUtf8("passwortAlt"));
        passwortAlt->setGeometry(QRect(40, 400, 261, 41));
        passwortAlt->setFont(font);
        passwortAlt->setEchoMode(QLineEdit::Password);
        passwortNeu = new QLineEdit(PBearbeiten);
        passwortNeu->setObjectName(QString::fromUtf8("passwortNeu"));
        passwortNeu->setGeometry(QRect(540, 400, 261, 41));
        passwortNeu->setFont(font);
        passwortNeu->setEchoMode(QLineEdit::Password);
        lblemail_2 = new QLabel(PBearbeiten);
        lblemail_2->setObjectName(QString::fromUtf8("lblemail_2"));
        lblemail_2->setGeometry(QRect(40, 370, 171, 21));
        lblemail_2->setFont(font);
        lblemail_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        lblemail = new QLabel(PBearbeiten);
        lblemail->setObjectName(QString::fromUtf8("lblemail"));
        lblemail->setGeometry(QRect(40, 270, 171, 21));
        lblemail->setFont(font);
        ProfilLoeschen = new QPushButton(PBearbeiten);
        ProfilLoeschen->setObjectName(QString::fromUtf8("ProfilLoeschen"));
        ProfilLoeschen->setGeometry(QRect(550, 315, 161, 41));
        ProfilLoeschen->setFont(font);
        ProfilLoeschen->setCursor(QCursor(Qt::PointingHandCursor));
        ProfilLoeschen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(200, 24, 1);\n"
"}\n"
""));
        profilePicture = new QLabel(PBearbeiten);
        profilePicture->setObjectName(QString::fromUtf8("profilePicture"));
        profilePicture->setGeometry(QRect(545, 134, 170, 170));
        profilePicture->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        blackBackround = new QLabel(PBearbeiten);
        blackBackround->setObjectName(QString::fromUtf8("blackBackround"));
        blackBackround->setGeometry(QRect(540, 130, 180, 180));
        blackBackround->setStyleSheet(QString::fromUtf8("background-color: rgb(171, 171, 171);"));
        LogoKlein = new QLabel(PBearbeiten);
        LogoKlein->setObjectName(QString::fromUtf8("LogoKlein"));
        LogoKlein->setGeometry(QRect(250, 580, 248, 140));
        lbl1 = new QLabel(PBearbeiten);
        lbl1->setObjectName(QString::fromUtf8("lbl1"));
        lbl1->setGeometry(QRect(0, 0, 70, 74));
        lbl2 = new QLabel(PBearbeiten);
        lbl2->setObjectName(QString::fromUtf8("lbl2"));
        lbl2->setGeometry(QRect(250, 0, 74, 74));
        lbl4 = new QLabel(PBearbeiten);
        lbl4->setObjectName(QString::fromUtf8("lbl4"));
        lbl4->setGeometry(QRect(750, 0, 74, 74));
        lbl3 = new QLabel(PBearbeiten);
        lbl3->setObjectName(QString::fromUtf8("lbl3"));
        lbl3->setGeometry(QRect(500, 0, 74, 74));
        label_12 = new QLabel(PBearbeiten);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 60, 821, 51));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 24, 1);"));
        ProfilbildHochladen = new QPushButton(PBearbeiten);
        ProfilbildHochladen->setObjectName(QString::fromUtf8("ProfilbildHochladen"));
        ProfilbildHochladen->setGeometry(QRect(370, 310, 161, 41));
        ProfilbildHochladen->setFont(font);
        ProfilbildHochladen->setCursor(QCursor(Qt::PointingHandCursor));
        ProfilbildHochladen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(200, 24, 1);\n"
"}\n"
""));
        blackBackround->raise();
        profilePicture->raise();
        lblUsername->raise();
        berschhirft->raise();
        ButtonProfil->raise();
        Username->raise();
        ButtonExit->raise();
        lblemail_3->raise();
        email->raise();
        passwortAlt->raise();
        passwortNeu->raise();
        lblemail_2->raise();
        lblemail->raise();
        ProfilLoeschen->raise();
        LogoKlein->raise();
        lbl1->raise();
        lbl2->raise();
        lbl4->raise();
        lbl3->raise();
        label_12->raise();
        ProfilbildHochladen->raise();

        retranslateUi(PBearbeiten);

        QMetaObject::connectSlotsByName(PBearbeiten);
    } // setupUi

    void retranslateUi(QWidget *PBearbeiten)
    {
        PBearbeiten->setWindowTitle(QCoreApplication::translate("PBearbeiten", "Form", nullptr));
        lblUsername->setText(QCoreApplication::translate("PBearbeiten", "Username:", nullptr));
        berschhirft->setText(QCoreApplication::translate("PBearbeiten", "<html><head/><body><p align=\"center\">Dein Profil</p></body></html>", nullptr));
        ButtonProfil->setText(QCoreApplication::translate("PBearbeiten", "Speichern", nullptr));
        Username->setText(QString());
        ButtonExit->setText(QCoreApplication::translate("PBearbeiten", "Abbrechen ", nullptr));
        lblemail_3->setText(QCoreApplication::translate("PBearbeiten", "Neues Passwort", nullptr));
        lblemail_2->setText(QCoreApplication::translate("PBearbeiten", "Aktuelles Passwort", nullptr));
        lblemail->setText(QCoreApplication::translate("PBearbeiten", "e-Mail Adresse:", nullptr));
        ProfilLoeschen->setText(QCoreApplication::translate("PBearbeiten", "Profil l\303\266schen", nullptr));
        profilePicture->setText(QString());
        blackBackround->setText(QString());
        LogoKlein->setText(QCoreApplication::translate("PBearbeiten", "TextLabel", nullptr));
        lbl1->setText(QCoreApplication::translate("PBearbeiten", "TextLabel", nullptr));
        lbl2->setText(QCoreApplication::translate("PBearbeiten", "TextLabel", nullptr));
        lbl4->setText(QCoreApplication::translate("PBearbeiten", "TextLabel", nullptr));
        lbl3->setText(QCoreApplication::translate("PBearbeiten", "TextLabel", nullptr));
        label_12->setText(QString());
        ProfilbildHochladen->setText(QCoreApplication::translate("PBearbeiten", "Profil l\303\266schen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PBearbeiten: public Ui_PBearbeiten {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PBEARBEITEN_H
