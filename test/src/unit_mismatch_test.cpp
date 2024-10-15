#include "gtest/gtest.h"
#include "units/Quantity.hpp"

namespace
{
    using namespace units;
    // NOLINTBEGIN
    TEST(unit_mismatch_tests, add_allow)
    {
        Quantity<si_dimensions::m> length1(1.0);
        Quantity<Dimension<1>> length2(2.0);
        static_assert(std::is_same_v<si_dimensions::m, Dimension<1>>);
        auto length3 = length1 + length2;
        ASSERT_EQ(length3.raw_value(), 3.0);
    }

    TEST(unit_mismatch_tests, subtract_allow)
    {
        Quantity<si_dimensions::m> length1(1.0);
        Quantity<Dimension<1>> length2(2.0);
        auto length3 = length1 - length2;
        Quantity<Dimension<1>> length4(-1.0);
        ASSERT_EQ(length3, length4);
    }

    TEST(unit_mismatch_tests, multiply_allow)
    {
        Quantity<si_dimensions::m> length1(2.0);
        Quantity<Dimension<1>> length2(3.0);
        auto length3 = length1 * length2;
        auto length4 = Quantity<Dimension<2>>(6.0);
        ASSERT_EQ(length3, length4);
    }

    TEST(unit_mismatch_tests, divide_allow)
    {
        Quantity<si_dimensions::m> length1(6.0);
        Quantity<Dimension<1>> length2(3.0);
        auto length3 = length1 / length2;
        auto length4 = Quantity<si_dimensions::one>(2.0);
        ASSERT_EQ(length3, length4);
    }

    TEST(unit_mismatch_tests, add_dimensionless)
    {
        Quantity<si_dimensions::one> d1(2.0);
        auto d2 = d1 + 3.0;
        auto d3 = Quantity<si_dimensions::one>(5.0);
        ASSERT_EQ(d2, d3);
    }

    TEST(unit_mismatch_tests, subtract_dimensionless)
    {
        Quantity<si_dimensions::one> d1(2.0);
        auto d2 = d1 - 3.0;
        auto d3 = Quantity<si_dimensions::one>(-1.0);
        ASSERT_EQ(d2, d3);
    }
    // NOLINTEND
}