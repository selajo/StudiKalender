#ifndef TST_STUDIENFACH_BEARBEITEN_H
#define TST_STUDIENFACH_BEARBEITEN_H



#include <QtTest>

/*
 * Author: Elena Schmidmeier
 *
 */

class termin_erstellen : public QObject
{
    Q_OBJECT
public:
    termin_erstellen();
    ~termin_erstellen();
    QString msg;


private slots:

    void TimeOut();
    void test_Termin_kein_Name();
    void test_Termin_Name_eingegeben();
    void test_Termin_abbrechen();


};




#endif // TST_STUDIENFACH_BEARBEITEN_H
