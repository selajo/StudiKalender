#ifndef DELETEPROFIL_H
#define DELETEPROFIL_H

#include <QDialog>

namespace Ui {
class DeleteProfil;
}

class DeleteProfil : public QDialog
{
    Q_OBJECT
    friend class tst;

public:
    explicit DeleteProfil(QWidget *parent = nullptr);
    ~DeleteProfil();

private slots:




    void on_ButtonExit_destroyed();

    void on_ButtonLoeschen_clicked();

private:
    Ui::DeleteProfil *ui;
};

#endif // DELETEPROFIL_H
