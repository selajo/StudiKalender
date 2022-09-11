#ifndef NUTZERPROFIL_H
#define NUTZERPROFIL_H

#include "StartseiteStudikalender/mainwindow.h"


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
    bool ProfilCheckEmail(QString);
    bool ProfilCheckNutzername(QString);
    bool ProfilCheckPasswort(QString, QString);
    bool ProfilCheckVorhanden(QString, QString);
    bool ProfilInsert(QString, QString, QString, QString, QString);
    bool ProfilLoeschen(QString, QString, QString);
    bool ProfilUpdatePasswort(QString, QString, QString);
    bool ProfilPasswortVergessen(QString, QString, QString, QString, QString);
    void ProfilUploadImage(QString, QString);

    bool ProfilChangeEmail(QString);
    QString ProfilNutzernameVergessen(QString, QString, QString);
    QPixmap ProfilGetImage();


    bool ProfilLaden(QString, QString);


    //Singleton
    static NProfil * getInstance();
private:
    static NProfil * instance;
};


#endif // NUTZERPROFIL_H
