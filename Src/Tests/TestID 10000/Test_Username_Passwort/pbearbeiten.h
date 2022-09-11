#ifndef PBEARBEITEN_H
#define PBEARBEITEN_H

#include <QDialog>

/*
 * Author: Irma Krieger
 *
 */

namespace Ui {
class PBearbeiten;
}

class PBearbeiten : public QDialog
{
    Q_OBJECT
    friend class tst;

public:
    explicit PBearbeiten(QWidget *parent = nullptr);
    ~PBearbeiten();

private slots:
    void on_ButtonExit_destroyed();

    void on_ButtonProfil_clicked();

    //void on_ProfilLoeschen_clicked();

    void on_ProfilbildHochladen_clicked();

private:
    Ui::PBearbeiten *ui;
};

#endif // PBEARBEITEN_H
