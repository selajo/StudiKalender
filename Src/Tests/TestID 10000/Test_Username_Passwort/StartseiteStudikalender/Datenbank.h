#ifndef DATENBANK_H
#define DATENBANK_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include "mainwindow.h"

/*
 *Author André Zimmer
 *
 */

 class Datenbank : public QMainWindow{

    Q_OBJECT

public:
    QSqlDatabase mydb;

    void connClose(){
       mydb.close();
       mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }


    bool connOpen(){
        mydb = QSqlDatabase::addDatabase("QMYSQL");
        mydb.setHostName("194.95.108.24");
        mydb.setUserName("root");
        mydb.setPassword("root");
        mydb.setDatabaseName("kalender");

        if(!mydb.open()){
            qDebug()<<"Failed to open the database";
            return false;
                        }
        else{
            qDebug()<<"Connected ....";
            return true;
        }


    }



    static Datenbank * getInstance();


 private:
     static Datenbank * instance;

    Datenbank();

};



#endif // DATENBANK_H
