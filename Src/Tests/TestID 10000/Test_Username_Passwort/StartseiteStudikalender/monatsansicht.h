#ifndef MONATSANSICHT_H
#define MONATSANSICHT_H

#include <QDialog>

namespace Ui {
class Monatsansicht;
}

class Monatsansicht : public QDialog
{
    Q_OBJECT

public:
    explicit Monatsansicht(QWidget *parent = nullptr);
    ~Monatsansicht();

private:
 QDate selectedDate() const;
 void setDate(const QDate &d);



private slots:
    void on_termin_erstellen_clicked();


    void on_faecher_clicked();

    void on_profil_clicked();

    void on_ansicht_currentTextChanged(const QString &arg1);
    void on_monat_vor_clicked();
    void on_monat_zurueck_clicked();


    void on_calendarWidget_selectionChanged();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_lernplan_clicked();

    void on_tableView_2_doubleClicked(const QModelIndex &index);

private:
    Ui::Monatsansicht *ui;
};

#endif // MONATSANSICHT_H
