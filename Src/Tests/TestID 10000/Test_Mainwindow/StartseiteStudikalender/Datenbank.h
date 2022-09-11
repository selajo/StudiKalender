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
       mydb.removeDatabase("qt_sql_default_connection");
    }


    bool connOpen(){
        mydb = QSqlDatabase::addDatabase("QMYSQL");
        mydb.setHostName("194.95.108.24");
        mydb.setUserName("root");
        mydb.setPassword("root");
        mydb.setDatabaseName("kalender");

        if(!mydb.open()){
            return false;
                        }
        else{
            return true;
        }


    }



    static Datenbank * getInstance();


 private:
     static Datenbank * instance;

    Datenbank();

};



#endif // DATENBANK_H
