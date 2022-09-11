#ifndef USERNAME_H
#define USERNAME_H

#include <QDialog>

namespace Ui {
class Username;
}

class Username : public QDialog
{
    Q_OBJECT

public:
    explicit Username(QWidget *parent = nullptr);
    ~Username();

private slots:
    void on_ForgotPassword_clicked();

    void on_ButtonCheck_clicked();

private:
    Ui::Username *ui;
};

#endif // USERNAME_H
