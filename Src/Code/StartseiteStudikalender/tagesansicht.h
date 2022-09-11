#ifndef TAGESANSICHT_H
#define TAGESANSICHT_H

#include <QDialog>

/*
 * Author: Elena Schmidmeier
 *
 */

namespace Ui {
class Tagesansicht;
}

class Tagesansicht : public QDialog
{
    Q_OBJECT

public:
    explicit Tagesansicht(QWidget *parent = nullptr);
    ~Tagesansicht();

private:

    QDate selectedDate() const;
    void setDate(const QDate &d);
    void ansicht();

public:
    //Timer
    QTimer *timer;

   public slots:

    void MyTimerSlot();

private slots:

    void on_neuer_Termin_clicked();

    void on_tag_zurueck_clicked();

    void on_tag_vor_clicked();

    void on_faecher_clicked();

    void on_profil_clicked();

    void on_ansicht_currentTextChanged();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_Lernplan_clicked();


    void on_exit_clicked();

    void on_abmelden_clicked();

private:
    Ui::Tagesansicht *ui; 
};

#endif // TAGESANSICHT_H
