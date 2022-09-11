#ifndef LERNPLANUI_H
#define LERNPLANUI_H

#include <QDialog>

namespace Ui {
class lernplanUI;
}

class lernplanUI : public QDialog
{
    Q_OBJECT
    friend class tst;

public:
    explicit lernplanUI(QWidget *parent = nullptr);
    ~lernplanUI();

private slots:
    void on_Loeschen_clicked();

    void on_abbrechen_clicked();

    void on_ok_clicked();

private:
    Ui::lernplanUI *ui;
};

#endif // LERNPLANUI_H
