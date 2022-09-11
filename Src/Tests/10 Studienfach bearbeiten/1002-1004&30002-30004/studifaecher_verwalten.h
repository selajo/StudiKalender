#ifndef STUDIFAECHER_VERWALTEN_H
#define STUDIFAECHER_VERWALTEN_H

#include <QDialog>
#include "tst_studienfach_bearbeiten.h"

namespace Ui {
class Studifaecher_verwalten;
}

class Studifaecher_verwalten : public QDialog
{
    Q_OBJECT
friend class studienfach_bearbeiten;

public:
    explicit Studifaecher_verwalten(QWidget *parent = nullptr);
    ~Studifaecher_verwalten();
    void setData_fach(const QString &labelText);

private slots:
    void on_abbrechen_clicked();

    void on_loeschen_clicked();

    void on_speichern_clicked();

    //void on_OK_clicked();

private:
    Ui::Studifaecher_verwalten *ui;
};

#endif // STUDIFAECHER_VERWALTEN_H
