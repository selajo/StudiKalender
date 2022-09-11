#include "tst_tst.h"
#include "tst_Konstruktor.h"
#include "tst_ProcilChangeEmail.h"
#include "tst_ProfilCheckEmail.h"
#include "tst_ProfilCheckPasswort.h"
#include "tst_ProfilCheckVorhanden.h"
#include "tst_ProfilInsert.h"
#include "tst_ProfilLaden.h"
#include "tst_ProfilLoeschen.h"
#include "tst_ProfilNutzernameVergessen.h"
#include "tst_ProfilPasswortVergessen.h"
#include "tst_ProfilUpdatePasswort.h"
#include "tst_ProfilUploadProfil.h"
#include "tst_ProfilGetImage.h"

#include <QGuiApplication>
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
