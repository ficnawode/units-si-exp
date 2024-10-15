#include "gtest/gtest.h"
#include "units/Length.hpp"
#include "units/Quantity.hpp"

namespace
{
    using namespace units::literals;
    TEST(length_tests, nano)
    {
        auto length = 1.0_nm;
        ASSERT_FLOAT_EQ(length.raw_value(), 1e-9);
    }

    TEST(length_tests, micro)
    {
        auto length = 1.0_um;
        ASSERT_FLOAT_EQ(length.raw_value(), 1e-6);
    }

    TEST(length_tests, milli)
    {
        auto length = 1.0_mm;
        ASSERT_FLOAT_EQ(length.raw_value(), 1e-3);
    }

    TEST(length_tests, centi)
    {
        auto length = 1.0_cm;
        ASSERT_FLOAT_EQ(length.raw_value(), 1e-2);
    }

    TEST(length_tests, meter)
    {
        auto length = 1.0_m;
        ASSERT_FLOAT_EQ(length.raw_value(), 1.0);
    }

    TEST(length_tests, kilo)
    {
        auto length = 1.0_km;
        ASSERT_FLOAT_EQ(length.raw_value(), 1e3);
    }
}