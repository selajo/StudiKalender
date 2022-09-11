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
    //Username Testfälle
    void Abbruch();

    void Feldausgefuellt_10018();
    void Feldausgefuellt_10019();
    void Feldausgefuellt_10020();
    void Feldausgefuellt_10021();
    void Feldausgefuellt_10022();
    void Feldausgefuellt_10023();
    void Feldausgefuellt_10024();


    //Passwort Testfälle
    void Feldausgefuellt_10025();
    void Feldausgefuellt_10026();
    void Feldausgefuellt_10027();
    void Feldausgefuellt_10028();
    void Feldausgefuellt_10029();
    void Feldausgefuellt_10030();
    void Feldausgefuellt_10031();
    void Feldausgefuellt_10032();
    void Feldausgefuellt_10033();
    void Feldausgefuellt_10034();
    void Feldausgefuellt_10035();
    void Feldausgefuellt_10036();
    void Feldausgefuellt_10037();
    void Feldausgefuellt_10038();
    void Feldausgefuellt_10039();
    void Feldausgefuellt_10040();
    void Feldausgefuellt_10041();
    void Feldausgefuellt_10042();
    void Feldausgefuellt_10043();
    void Feldausgefuellt_10044();
    void Feldausgefuellt_10045();
    void Feldausgefuellt_10046();
    void Feldausgefuellt_10047();
    void Feldausgefuellt_10048();
    void Feldausgefuellt_10049();
    void Feldausgefuellt_10050();
    void Feldausgefuellt_10051();
    void Feldausgefuellt_10052();
    void Feldausgefuellt_10053();
    void Feldausgefuellt_10054();
    void Feldausgefuellt_10055();
    void Feldausgefuellt_10056();
    void Feldausgefuellt_10057();
    void Abbruch2();



    void TimeOut();
};

#endif // TST_TST_H
