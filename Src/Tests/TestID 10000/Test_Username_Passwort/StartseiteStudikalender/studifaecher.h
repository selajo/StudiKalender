#ifndef STUDIFAECHER_H
#define STUDIFAECHER_H

#include <QDialog>

/*
 * Author: Elena Schmidmeier
 *
 */

namespace Ui {
class studifaecher;
}

class studifaecher : public QDialog
{
    Q_OBJECT

public:
    explicit studifaecher(QWidget *parent = nullptr);
    ~studifaecher();

private slots:
    void on_speichern_clicked();
    void on_abbrechen_clicked();
    void on_faecher_doubleClicked(const QModelIndex &index);

private:
    Ui::studifaecher *ui;
};

#endif // STUDIFAECHER_H
