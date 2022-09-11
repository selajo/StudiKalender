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
    void test_EndDatum_default();

    void test_Loeschen_kein_Lernplan();
    void test_Loeschen_Lernplan();

    void test_Studienfach_fehlt();
    void test_Datum_klein();
    void test_Datum_ok();
    void test_Datum_gleich();

    void TimeOut();
};

#endif // TST_TST_H
