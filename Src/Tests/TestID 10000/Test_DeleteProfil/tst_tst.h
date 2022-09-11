#ifndef TST_TST_H
#define TST_TST_H

#include <QtTest>


class tst : public QObject
{
    Q_OBJECT
public:
    tst();
    ~tst();
    QString msg;


private slots:

    //Testfall Felder leer
    void Felder_Leer10059();
    void Felder_Leer10060();
    void Felder_Leer10061();
    void Felder_Leer10062();
    void Felder_Leer10063();
    void Felder_Leer10064();
    void Felder_Leer10065();

    void Abbruch();

    void TimeOut();
};

#endif // TST_TST_H
