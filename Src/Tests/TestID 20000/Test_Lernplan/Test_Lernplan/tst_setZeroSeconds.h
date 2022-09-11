#ifndef TST_SETZEROSECONDS_H
#define TST_SETZEROSECONDS_H

#include <tst_tst_checkenddatum.h>

//Author: Josef Lanzl

using namespace testing;

//SetZeroSeconds

TEST(test_20217, test)
{
    //setup
    Lernplan l;
    Termin t;
    QTime Beginn, Ende;
    Beginn.setHMS(17, 33, 25);
    Ende.setHMS(17, 50, 44);
    t.Beginn = Beginn;
    t.Ende = Ende;
    l.Termine.push_back(t);

    l.SetZeroSeconds();

    Beginn.setHMS(17, 33, 0);
    Ende.setHMS(17, 50, 0);
    ASSERT_THAT(l.Termine[0].Beginn, Beginn);
    ASSERT_THAT(l.Termine[0].Ende, Ende);
}

#endif // TST_SETZEROSECONDS_H
