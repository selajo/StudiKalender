#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>

/*
 * Author: Irma Krieger
 *
 */


namespace Ui {
class Password;
}

class Password : public QDialog
{
    Q_OBJECT
    friend class tst;

public:
    explicit Password(QWidget *parent = nullptr);
    ~Password();

private slots:
    void on_ButtonCheck_clicked();

    void on_ButtonCheck_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Password *ui;
};

#endif // PASSWORD_H
