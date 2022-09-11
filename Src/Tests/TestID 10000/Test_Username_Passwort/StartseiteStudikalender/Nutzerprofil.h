#ifndef NUTZERPROFIL_H
#define NUTZERPROFIL_H

#include "mainwindow.h"


//Author: Josef Lanzl
//Informationsbeschaffung: https://doc.qt.io/qt-5/sql-sqlstatements.html



class NProfil {
public:
    int idNutzer;
    QString Email;
    QString Nutzername;
    QString Passwort;

    NProfil();
    ~NProfil();
    bool ProfilCheckEmail(QSqlQuery, QString);
    bool ProfilCheckNutzername(QSqlQuery, QString);
    bool ProfilCheckPasswort(QSqlQuery, QString, QString);
    bool ProfilCheckVorhanden(QSqlQuery, QString, QString);
    bool ProfilInsert(QSqlQuery, QString, QString, QString, QString, QString);
    bool ProfilLoeschen(QSqlQuery, QString, QString, QString);
    bool ProfilUpdatePasswort(QSqlQuery, QString, QString, QString);
    bool ProfilPasswortVergessen(QSqlQuery, QString, QString, QString, QString, QString);
    void ProfilUploadImage(QSqlQuery, QString, QString);

    bool ProfilChangeEmail(QSqlQuery, QString);
    QString ProfilNutzernameVergessen(QSqlQuery, QString, QString, QString);
    QPixmap ProfilGetImage(QSqlQuery);


    bool ProfilLaden(QSqlQuery, QString, QString);
};


#endif // NUTZERPROFIL_H
