#ifndef TST_TEST_H
#define TST_TEST_H

#include "tst_tst_checkenddatum.h"

//Author: Josef Lanzl

using namespace testing;

//Lerplan Konstruktor

TEST(test_20204, test)
{
    Lernplan l;
    ASSERT_THAT(QDate::currentDate(), l.EndDatum);
}


#endif // TST_TEST_H
