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
    //Testfall Emailformung
    void Email_wohlgeformt10001();
    void Email_wohlgeformt10002();
    void Email_nichtwohlgeformt10003();
    void Email_nichtwohlgeformt10004();
    void Email_nichtwohlgeformt10005();
    void Email_nichtwohlgeformt10006();
    void Email_nichtwohlgeformt10007();
    void Email_nichtwohlgeformt10008();

    //Testfall Felder leer
    void Felder_Leer10009();
    void Felder_Leer10010();
    void Felder_Leer10011();
    void Felder_Leer10012();
    void Felder_Leer10013();
    void Felder_Leer10014();
    void Felder_Leer10015();

    void Abbruch();

    void TimeOut();
};

#endif // TST_TST_H
