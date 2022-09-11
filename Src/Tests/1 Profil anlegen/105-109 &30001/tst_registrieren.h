#ifndef TST_REGISTRIEREN_H
#define TST_REGISTRIEREN_H


#include <QtTest>

/*
 * Author: Elena Schmidmeier
 *
 */

class tst_registrieren : public QObject
{
    Q_OBJECT
public:
    tst_registrieren();
    ~tst_registrieren();
    QString msg;


private slots:
    void test_Registrieren_gueltige_EMail();
    void test_Registrieren_keine_Daten();
    void TimeOut();
    void test_Registrieren_Passwort_ungleich();
    void test_Registrieren_ungueltige_EMail();
    void test_Registrieren_exit();
    void test_Registrieren_login_zurueck();
};


#endif // TST_REGISTRIEREN_H


