#include "gtest/gtest.h"
#include "units/Length.hpp"
#include "units/Quantity.hpp"

namespace
{
    using namespace units::literals;
    TEST(length_tests, nano)
    {
        auto nm = 1.0_nm;
        auto um = 1.0_um;
        auto mm = 1.0_mm;
        auto cm = 1.0_cm;
        auto m = 1.0_m;
        auto km = 1.0_km;

        EXPECT_FLOAT_EQ(nm.raw_value(), 1.0e-9);
        EXPECT_FLOAT_EQ(um.raw_value(), 1.0e-6);
        EXPECT_FLOAT_EQ(mm.raw_value(), 1.0e-3);
        EXPECT_FLOAT_EQ(cm.raw_value(), 1.0e-2);
        EXPECT_FLOAT_EQ(m.raw_value(), 1.0);
        EXPECT_FLOAT_EQ(km.raw_value(), 1.0e3);
    }
}