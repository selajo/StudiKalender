#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

/*
 * Author: Irma Krieger
 *
 */
NProfil NP;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QWidget *q = &w;
    try {

        w.show();
        return a.exec();
    }
    catch(const char* e) {
        QMessageBox::warning(q, "Login", e);
    }
}
