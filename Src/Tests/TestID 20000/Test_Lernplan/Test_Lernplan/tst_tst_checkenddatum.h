#ifndef TST_CHECKENDDATUM_H
#define TST_CHECKENDDATUM_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../../../../Code/StartseiteStudikalender/Lernplan.h>
#include <../../../../Code/StartseiteStudikalender/Lernplan.cpp>
#include <../../../../Code/StartseiteStudikalender/Termin_Klasse.h>
#include <../../../../Code/StartseiteStudikalender/Termin_Klasse.cpp>
#include <../../../../Code/StartseiteStudikalender/Studienfach_Klasse.h>
#include <../../../../Code/StartseiteStudikalender/Studienfach_Klasse.cpp>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.h>
#include <../../../../Code/StartseiteStudikalender/Nutzerprofil.cpp>
#include <../../../../Code/StartseiteStudikalender/Kalender.h>
#include <../../../../Code/StartseiteStudikalender/Kalender.cpp>

//Author: Josef Lanzl

using namespace testing;

//CheckEndDatum

TEST(test_20218, test)
{
    //setup
    Lernplan l;
    l.EndDatum = QDate::currentDate().addDays(7);

    bool ergebnis = l.checkEndDatum();
    ASSERT_THAT(ergebnis, true);

}

TEST(test_20219, test)
{
    //setup
    Lernplan l;
    l.EndDatum = QDate::currentDate();
    l.EndDatum = l.EndDatum.addDays(5);

    bool ergebnis = l.checkEndDatum();
    ASSERT_THAT(ergebnis, false);

}

TEST(test_20220, test)
{
    //setup
    Lernplan l;
    l.EndDatum = QDate::currentDate();
    l.EndDatum = l.EndDatum.addDays(6);

    bool ergebnis = l.checkEndDatum();
    ASSERT_THAT(ergebnis, true);

}

#endif // TST_CHECKENDDATUM_H
