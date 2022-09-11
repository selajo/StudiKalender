#ifndef TST_STUDIENFACH_BEARBEITEN_H
#define TST_STUDIENFACH_BEARBEITEN_H



#include <QtTest>

/*
 * Author: Elena Schmidmeier
 *
 */


class studienfach_bearbeiten : public QObject
{
    Q_OBJECT
public:
    studienfach_bearbeiten();
    ~studienfach_bearbeiten();
    QString msg;


private slots:

    void TimeOut();
    void test_Studifach_kein_Name();
    void test_Studifach_Name_eingegeben();
    void test_Studifach_abbrechen();
    void test_Studifach_loeschen();


};




#endif // TST_STUDIENFACH_BEARBEITEN_H
