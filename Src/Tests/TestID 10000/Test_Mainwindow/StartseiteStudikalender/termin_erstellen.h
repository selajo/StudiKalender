#ifndef TERMIN_ERSTELLEN_H
#define TERMIN_ERSTELLEN_H
#include "Termin_Klasse.h"
#include <QDialog>

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
