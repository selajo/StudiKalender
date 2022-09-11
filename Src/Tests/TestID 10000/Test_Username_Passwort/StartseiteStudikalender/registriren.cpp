#include "registriren.h"
#include "ui_registriren.h"
#include <QMessageBox>


Registriren::Registriren(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registriren)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Public/StudiKalender/Logo1.png");

}



Registriren::~Registriren()
{

    delete ui;
}

