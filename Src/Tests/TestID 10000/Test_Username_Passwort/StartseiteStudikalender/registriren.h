#ifndef REGISTRIREN_H
#define REGISTRIREN_H

#include <QDialog>

namespace Ui {
class Registriren;
}

class Registriren : public QDialog
{
    Q_OBJECT

public:
    explicit Registriren(QWidget *parent = nullptr);
    ~Registriren();

private:
    Ui::Registriren *ui;
};

#endif // REGISTRIREN_H
