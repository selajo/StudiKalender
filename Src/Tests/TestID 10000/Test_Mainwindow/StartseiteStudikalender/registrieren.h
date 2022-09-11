#ifndef REGISTRIEREN_H
#define REGISTRIEREN_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMainWindow>
#include <mainwindow.h>

/*
 * Author: Elena Schmidmeier
 *
 */

namespace Ui {
class Registrieren;
}

class Registrieren : public QDialog
{
    Q_OBJECT

public:
    explicit Registrieren(QWidget *parent = nullptr);
    ~Registrieren();

private slots:

    void on_Registrieren_2_clicked();



    void on_login_clicked();

    void on_exit_clicked();

private:
    Ui::Registrieren *ui;
};

#endif // REGISTRIEREN_H
