#ifndef WOCHENANSICHT_H
#define WOCHENANSICHT_H


#include <QDialog>

namespace Ui {
class Wochenansicht;
}

class Wochenansicht : public QDialog
{
    Q_OBJECT

public:
    explicit Wochenansicht(QWidget *parent = nullptr);
    ~Wochenansicht();
    QVector<QDate> Wochentag;

private:
    QDate getdate();
    QDate selectedDate() const;
    void setDate(const QDate &d);
    Ui::Wochenansicht *ui;
    QDate currentDate() const;
    void setCurrentDate(const QDate &d);
    void weekday(int y, int m, int d);

private slots:


    void on_ansicht_currentTextChanged(const QString &arg1);

    void on_dayFrontButton_clicked();
    void on_dayBackButton_clicked();
    void on_profil_clicked();
    void on_neuer_Termin_clicked();

    void on_faecher_clicked();

    void on_Mo_clicked();
    void on_Di_clicked();
    void on_Mi_clicked();
    void on_Do_clicked();
    void on_Fr_clicked();
    void on_Sa_clicked();
    void on_So_clicked();
};

#endif // WOCHENANSICHT_H
