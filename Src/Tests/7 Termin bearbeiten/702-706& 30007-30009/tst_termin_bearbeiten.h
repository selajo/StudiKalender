#ifndef TST_STUDIENFACH_BEARBEITEN_H
#define TST_STUDIENFACH_BEARBEITEN_H



#include <QtTest>

/*
 * Author: Elena Schmidmeier
 *
 */

class termin_bearbeiten : public QObject
{
    Q_OBJECT
public:
    termin_bearbeiten();
    ~termin_bearbeiten();
    QString msg;


private slots:

    void TimeOut();
    void test_Termin_kein_Name();
    void test_Termin_Name_eingegeben();
    void test_Termin_abbrechen();
    void test_Termin_loeschen();


};




#endif // TST_STUDIENFACH_BEARBEITEN_H
