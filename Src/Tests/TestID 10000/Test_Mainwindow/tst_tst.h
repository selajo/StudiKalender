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
    void Felder_Leer10067();
    void Felder_Leer10068();
    void Felder_Leer10069();
    void Felder_Leer10070();
    void Felder_Leer10071();
    void Felder_Leer10072();
    void Felder_ausgefuellt10066();


    void TimeOut();
};

#endif // TST_TST_H
