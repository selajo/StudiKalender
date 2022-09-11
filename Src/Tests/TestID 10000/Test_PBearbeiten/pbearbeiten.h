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

public:
    explicit PBearbeiten(QWidget *parent = nullptr);
    ~PBearbeiten();

private slots:
    void on_ButtonExit_destroyed();

    void on_ButtonProfil_clicked();

private:
    Ui::PBearbeiten *ui;
};

#endif // PBEARBEITEN_H
