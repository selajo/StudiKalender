#ifndef TST_PROFILUPLOADPROFIL_H
#define TST_PROFILUPLOADPROFIL_H

#include <tst_tst.h>
#include <libgen.h>

//Author: Josef Lanzl

using namespace testing;

//ProfilUploadImage testen

TEST(test_20040, test)
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

        //Pfad zum Bild test.jpg
        QString path = "test.jpg";
        p.ProfilUploadImage("MaxMuster", path);


        QSqlQuery Query;
        //Jetzt prüfen, ob Bild auf PC = Bild in SQL
        QString NutzerN = "MaxMuster";
        Query.prepare("SELECT Image FROM Profil WHERE Nutzername = :NutzerN");
        Query.bindValue(":NutzerN", NutzerN);
        Query.exec();

        Query.first();
        QByteArray inSQL = Query.value(0).toByteArray();

        QByteArray inOrdner;
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        inOrdner = file.readAll();
        file.close();

        ASSERT_THAT(inOrdner, inSQL);
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

TEST(test_20041, test)
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

        //Pfad zum Bild test.jpg
        QString path = "tet.jpg";

        try {
        p.ProfilUploadImage("MaxMuster", path);
        }
        catch(const char *e) {
            ASSERT_THAT(e, "File error");
        }
    }

    //Aufräumen
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}



#endif // TST_PROFILUPLOADPROFIL_H
