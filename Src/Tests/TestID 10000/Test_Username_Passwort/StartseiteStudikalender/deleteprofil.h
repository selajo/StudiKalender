#ifndef DELETEPROFIL_H
#define DELETEPROFIL_H

#include <QDialog>

namespace Ui {
class DeleteProfil;
}

class DeleteProfil : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteProfil(QWidget *parent = nullptr);
    ~DeleteProfil();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DeleteProfil *ui;
};

#endif // DELETEPROFIL_H
