#ifndef PROFIL_H
#define PROFIL_H

#include <QDialog>

/*
 * Author: Elena Schmidmeier, Irma Krieger
 *
 */

namespace Ui {
class profil;
}

class profil : public QDialog
{
    Q_OBJECT

public:
    explicit profil(QWidget *parent = nullptr);
    ~profil();

private slots:

    void on_ButtonExit_destroyed();

    void on_ButtonProfil_clicked();

private:
    Ui::profil *ui;
};

#endif // PROFIL_H
