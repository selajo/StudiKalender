/********************************************************************************
** Form generated from reading UI file 'deleteprofil.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEPROFIL_H
#define UI_DELETEPROFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteProfil
{
public:
    QLabel *lblemail_2;
    QLabel *lblemail_3;
    QLineEdit *passwortAlt;
    QLabel *lblemail_5;
    QLineEdit *s1;
    QLineEdit *s2;
    QLabel *lblemail_4;
    QLabel *lbl3;
    QLabel *lbl4;
    QLabel *lbl1;
    QLabel *lbl2;
    QLabel *LogoKlein;
    QLabel *blackBackround;
    QLabel *profilePicture;
    QPushButton *ButtonExit;
    QPushButton *ButtonLoeschen;
    QLabel *label_12;

    void setupUi(QDialog *DeleteProfil)
    {
        if (DeleteProfil->objectName().isEmpty())
            DeleteProfil->setObjectName(QString::fromUtf8("DeleteProfil"));
        DeleteProfil->resize(820, 720);
        DeleteProfil->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lblemail_2 = new QLabel(DeleteProfil);
        lblemail_2->setObjectName(QString::fromUtf8("lblemail_2"));
        lblemail_2->setGeometry(QRect(40, 170, 171, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        font.setPointSize(12);
        lblemail_2->setFont(font);
        lblemail_3 = new QLabel(DeleteProfil);
        lblemail_3->setObjectName(QString::fromUtf8("lblemail_3"));
        lblemail_3->setGeometry(QRect(300, 120, 231, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MV Boli"));
        font1.setPointSize(18);
        lblemail_3->setFont(font1);
        passwortAlt = new QLineEdit(DeleteProfil);
        passwortAlt->setObjectName(QString::fromUtf8("passwortAlt"));
        passwortAlt->setGeometry(QRect(40, 200, 261, 41));
        passwortAlt->setFont(font);
        lblemail_5 = new QLabel(DeleteProfil);
        lblemail_5->setObjectName(QString::fromUtf8("lblemail_5"));
        lblemail_5->setGeometry(QRect(40, 370, 171, 21));
        lblemail_5->setFont(font);
        s1 = new QLineEdit(DeleteProfil);
        s1->setObjectName(QString::fromUtf8("s1"));
        s1->setGeometry(QRect(40, 300, 261, 41));
        s1->setFont(font);
        s2 = new QLineEdit(DeleteProfil);
        s2->setObjectName(QString::fromUtf8("s2"));
        s2->setGeometry(QRect(40, 400, 261, 41));
        s2->setFont(font);
        lblemail_4 = new QLabel(DeleteProfil);
        lblemail_4->setObjectName(QString::fromUtf8("lblemail_4"));
        lblemail_4->setGeometry(QRect(40, 270, 171, 21));
        lblemail_4->setFont(font);
        lbl3 = new QLabel(DeleteProfil);
        lbl3->setObjectName(QString::fromUtf8("lbl3"));
        lbl3->setGeometry(QRect(500, 0, 74, 74));
        lbl4 = new QLabel(DeleteProfil);
        lbl4->setObjectName(QString::fromUtf8("lbl4"));
        lbl4->setGeometry(QRect(750, 0, 74, 74));
        lbl1 = new QLabel(DeleteProfil);
        lbl1->setObjectName(QString::fromUtf8("lbl1"));
        lbl1->setGeometry(QRect(0, 0, 74, 74));
        lbl2 = new QLabel(DeleteProfil);
        lbl2->setObjectName(QString::fromUtf8("lbl2"));
        lbl2->setGeometry(QRect(250, 0, 74, 74));
        LogoKlein = new QLabel(DeleteProfil);
        LogoKlein->setObjectName(QString::fromUtf8("LogoKlein"));
        LogoKlein->setGeometry(QRect(250, 580, 248, 140));
        blackBackround = new QLabel(DeleteProfil);
        blackBackround->setObjectName(QString::fromUtf8("blackBackround"));
        blackBackround->setGeometry(QRect(540, 130, 180, 180));
        blackBackround->setStyleSheet(QString::fromUtf8("background-color: rgb(171, 171, 171);"));
        profilePicture = new QLabel(DeleteProfil);
        profilePicture->setObjectName(QString::fromUtf8("profilePicture"));
        profilePicture->setGeometry(QRect(545, 135, 170, 170));
        profilePicture->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ButtonExit = new QPushButton(DeleteProfil);
        ButtonExit->setObjectName(QString::fromUtf8("ButtonExit"));
        ButtonExit->setGeometry(QRect(320, 520, 161, 41));
        ButtonExit->setFont(font);
        ButtonLoeschen = new QPushButton(DeleteProfil);
        ButtonLoeschen->setObjectName(QString::fromUtf8("ButtonLoeschen"));
        ButtonLoeschen->setGeometry(QRect(320, 470, 161, 41));
        ButtonLoeschen->setFont(font);
        label_12 = new QLabel(DeleteProfil);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 60, 821, 51));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 24, 1);"));

        retranslateUi(DeleteProfil);

        QMetaObject::connectSlotsByName(DeleteProfil);
    } // setupUi

    void retranslateUi(QDialog *DeleteProfil)
    {
        DeleteProfil->setWindowTitle(QCoreApplication::translate("DeleteProfil", "Dialog", nullptr));
        lblemail_2->setText(QCoreApplication::translate("DeleteProfil", "Aktuelles Passwort", nullptr));
        lblemail_3->setText(QCoreApplication::translate("DeleteProfil", "Passwort l\303\266schen", nullptr));
        lblemail_5->setText(QCoreApplication::translate("DeleteProfil", "Sicherheitsfrage 2", nullptr));
        lblemail_4->setText(QCoreApplication::translate("DeleteProfil", "Sicherheitsfrage 1", nullptr));
        lbl3->setText(QCoreApplication::translate("DeleteProfil", "TextLabel", nullptr));
        lbl4->setText(QCoreApplication::translate("DeleteProfil", "TextLabel", nullptr));
        lbl1->setText(QCoreApplication::translate("DeleteProfil", "TextLabel", nullptr));
        lbl2->setText(QCoreApplication::translate("DeleteProfil", "TextLabel", nullptr));
        LogoKlein->setText(QCoreApplication::translate("DeleteProfil", "TextLabel", nullptr));
        blackBackround->setText(QString());
        profilePicture->setText(QString());
        ButtonExit->setText(QCoreApplication::translate("DeleteProfil", "Abbrechen ", nullptr));
        ButtonLoeschen->setText(QCoreApplication::translate("DeleteProfil", "Profil l\303\266schen", nullptr));
        label_12->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DeleteProfil: public Ui_DeleteProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEPROFIL_H
