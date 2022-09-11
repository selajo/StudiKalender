#ifndef TERMIN_ERSTELLEN_H
#define TERMIN_ERSTELLEN_H

#include <QDialog>
#include "tst_termin_erstellen.h"
/*
 * Author: Elena Schmidmeier
 *
 */

namespace Ui {
class Termin_erstellen;
}

class Termin_erstellen : public QDialog
{
    Q_OBJECT
    friend class termin_erstellen;

public:
    explicit Termin_erstellen(QWidget *parent = nullptr);
    ~Termin_erstellen();

private slots:
    void on_abbrechen_clicked();

    void on_termin_hinzufuegen_clicked();

private:
    Ui::Termin_erstellen *ui;
};

#endif // TERMIN_ERSTELLEN_H
