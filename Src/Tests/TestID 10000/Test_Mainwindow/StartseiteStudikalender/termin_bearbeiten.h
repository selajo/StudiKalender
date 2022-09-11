#ifndef TERMIN_BEARBEITEN_H
#define TERMIN_BEARBEITEN_H

#include <QDialog>
/*
 * Author: Elena Schmidmeier
 *
 */

namespace Ui {
class Termin_bearbeiten;
}

class Termin_bearbeiten : public QDialog
{
    Q_OBJECT

public:
    explicit Termin_bearbeiten(QWidget *parent = nullptr);
    ~Termin_bearbeiten();
    void setData(const QString &labelText);

private slots:
    void on_abbrechen_clicked();

    void on_Termin_loeschen_clicked();

    void on_speichern_clicked();



private:
    Ui::Termin_bearbeiten *ui;

};

#endif // TERMIN_BEARBEITEN_H
