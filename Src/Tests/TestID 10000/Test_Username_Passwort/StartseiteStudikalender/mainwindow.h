#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QDialog>
#include "Globals.h"


#include "Nutzerprofil.h"

#include "tagesansicht.h"


/*
 * Author: Irma Krieger
 *
 */




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;
             }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButtonLogIn_clicked();

    void on_pushRegistrieren_clicked();

    void on_pushButtonPassword_clicked();

#

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
