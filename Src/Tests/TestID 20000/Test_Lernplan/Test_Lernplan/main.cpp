#include "tst_tst_checkenddatum.h"
#include "tst_Konstruktor.h"
#include "tst_LernplanErstellenStart.h"
#include "tst_LernplanErstellenTag.h"
#include "tst_LernplanErstellenWoche.h"
#include "tst_LernplanLoeschen.h"
#include "tst_RechneStunden.h"
#include "tst_checkStunden.h"
#include "tst_prepareTermine.h"
#include "tst_setZeroSeconds.h"


#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
