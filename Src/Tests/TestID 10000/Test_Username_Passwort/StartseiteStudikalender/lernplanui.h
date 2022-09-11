#ifndef LERNPLANUI_H
#define LERNPLANUI_H

#include <QDialog>

namespace Ui {
class lernplanUI;
}

class lernplanUI : public QDialog
{
    Q_OBJECT

public:
    explicit lernplanUI(QWidget *parent = nullptr);
    ~lernplanUI();

private slots:
    void on_buttonBox_accepted();

    void on_Loeschen_clicked();

private:
    Ui::lernplanUI *ui;
};

#endif // LERNPLANUI_H
