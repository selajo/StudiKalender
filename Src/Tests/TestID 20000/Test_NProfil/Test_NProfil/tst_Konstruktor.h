#ifndef TST_PROFIL_H
#define TST_PROFIL_H


#include <tst_tst.h>

//Author: Josef Lanzl

using namespace testing;

//NProfil Konstruktor testen

TEST(test_20001, test)
{

    NProfil p;

    ASSERT_THAT(p.idNutzer, -1);
    ASSERT_THAT(p.Email, "");
    ASSERT_THAT(p.Passwort, "");
    ASSERT_THAT(p.Nutzername, "");
}

#endif // TST_PROFIL_H
