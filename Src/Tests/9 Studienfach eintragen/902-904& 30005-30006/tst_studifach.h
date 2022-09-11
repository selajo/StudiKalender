#ifndef TST_STUDIFACH_H
#define TST_STUDIFACH_H

#include <QtTest>


/*
 * Author: Elena Schmidmeier
 *
 */


class studifach : public QObject
{
    Q_OBJECT
public:
    studifach();
    ~studifach();
    QString msg;


private slots:

    void TimeOut();
    void test_Studifach_kein_Name();
    void test_Studifach_Name_eingegeben();
    void test_Studifach_abbrechen();


};


#endif // TST_STUDIFACH_H
