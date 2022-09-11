#ifndef TST_PROFILGETIMAGE_H
#define TST_PROFILGETIMAGE_H

#include <tst_tst.h>
#include <libgen.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilGetImage testen

TEST(test_20014, test)
{
    {
        //setup
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("194.95.108.24");
        db.setUserName("root");
        db.setPassword("root");
        db.setDatabaseName("kalender");
        db.open();

        //MaxMuster wird hier verwendet
        NProfil p;
        p.ProfilLaden("MaxMuster", "Test123!");

        QString path = "test.jpg";

        p.ProfilUploadImage("MaxMuster", path);

        QPixmap img = p.ProfilGetImage();

        //Jetzt prüfen, ob Bild auf PC = Bild in SQL
        QByteArray inOrdner;
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        inOrdner = file.readAll();
        file.close();
        QPixmap ergebnis;
        ergebnis.loadFromData(inOrdner, "JPG");

        ASSERT_THAT(ergebnis, img);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}


#endif // TST_PROFILGETIMAGE_H
