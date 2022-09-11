#ifndef TST_PREPARETERMINE_H
#define TST_PREPARETERMINE_H

#include <tst_tst_checkenddatum.h>

//Author: Josef Lanzl

using namespace testing;

//PrepareTermine

TEST(test_20212, test)
{
    //setup
    Lernplan l;
    Termin t;
    QTime Beginn, Ende;
    Beginn.setHMS(7, 33, 0);
    Ende.setHMS(17, 50, 0);
    t.Beginn = Beginn;
    t.Ende = Ende;
    l.Termine.push_back(t);

    l.prepareTermine();

    Beginn.setHMS(8, 0, 0);
    Ende.setHMS(17, 50, 0);
    ASSERT_THAT(l.Termine[0].Beginn, Beginn);
    ASSERT_THAT(l.Termine[0].Ende, Ende);
}

TEST(test_20213, test)
{
    //setup
    Lernplan l;
    Termin t;
    QTime Beginn, Ende;
    Beginn.setHMS(14, 33, 0);
    Ende.setHMS(23, 50, 0);
    t.Beginn = Beginn;
    t.Ende = Ende;
    l.Termine.push_back(t);

    l.prepareTermine();

    Beginn.setHMS(14, 33, 0);
    Ende.setHMS(22, 0, 0);
    ASSERT_THAT(l.Termine[0].Beginn, Beginn);
    ASSERT_THAT(l.Termine[0].Ende, Ende);
}


TEST(test_20214, test)
{
    //setup
    Lernplan l;
    Termin t;
    QTime Beginn, Ende;
    Beginn.setHMS(14, 33, 0);
    Ende.setHMS(21, 50, 0);
    t.Beginn = Beginn;
    t.Ende = Ende;
    l.Termine.push_back(t);
    l.Termine.push_back(t);

    l.prepareTermine();

    Beginn.setHMS(14, 33, 0);
    Ende.setHMS(21, 50, 0);
    ASSERT_THAT(l.Termine[0].Beginn, Beginn);
    ASSERT_THAT(l.Termine[0].Ende, Ende);
    ASSERT_THAT(l.Termine[1].Beginn, Ende);
    ASSERT_THAT(l.Termine[1].Ende, Ende);
}

TEST(test_20215, test)
{
    //setup
    Lernplan l;
    Termin t;
    QTime Beginn, Ende, Ende2;
    Beginn.setHMS(14, 33, 0);
    Ende.setHMS(21, 50, 0);
    t.Beginn = Beginn;
    t.Ende = Ende;
    l.Termine.push_back(t);

    Beginn.setHMS(18, 33, 0);
    Ende.setHMS(21, 55, 0);
    t.Beginn = Beginn;
    t.Ende = Ende;
    l.Termine.push_back(t);

    l.prepareTermine();

    Beginn.setHMS(14, 33, 0);
    Ende.setHMS(21, 50, 0);
    Ende2.setHMS(21, 55, 0);
    ASSERT_THAT(l.Termine[0].Beginn, Beginn);
    ASSERT_THAT(l.Termine[0].Ende, Ende);
    ASSERT_THAT(l.Termine[1].Beginn, Ende);
    ASSERT_THAT(l.Termine[1].Ende, Ende2);
}



#endif // TST_PREPARETERMINE_H
