#include "gtest/gtest.h"
#include "units/Quantity.hpp"

namespace
{
    // NOLINTBEGIN
    TEST(unit_mismatch_tests, add_allow)
    {
        Quantity<si::m> length1(1.0);
        Quantity<Dimension<1>> length2(2.0);
        static_assert(std::is_same_v<si::m, Dimension<1>>);
        auto length3 = length1 + length2;
        ASSERT_EQ(length3.raw_value(), 3.0);
    }

    TEST(unit_mismatch_tests, subtract_allow)
    {
        Quantity<si::m, double> length1(1.0);
        Quantity<Dimension<1>, double> length2(2.0);
        auto length3 = length1 - length2;
        Quantity<Dimension<1>, double> length4(-1.0);
        ASSERT_EQ(length3, length4);
    }

    TEST(unit_mismatch_tests, multiply_allow)
    {
        Quantity<si::m, double> length1(2.0);
        Quantity<Dimension<1>, double> length2(3.0);
        auto length3 = length1 * length2;
        auto length4 = Quantity<Dimension<2>, double>(6.0);
        ASSERT_EQ(length3, length4);
    }

    TEST(unit_mismatch_tests, divide_allow)
    {
        Quantity<si::m, double> length1(6.0);
        Quantity<Dimension<1>, double> length2(3.0);
        auto length3 = length1 / length2;
        auto length4 = Quantity<si::one, double>(2.0);
        ASSERT_EQ(length3, length4);
    }

    TEST(unit_mismatch_tests, add_dimensionless)
    {
        Quantity<si::one, double> d1(2.0);
        auto d2 = d1 + 3.0;
        auto d3 = Quantity<si::one, double>(5.0);
        ASSERT_EQ(d2, d3);
    }

    TEST(unit_mismatch_tests, subtract_dimensionless)
    {
        Quantity<si::one, double> d1(2.0);
        auto d2 = d1 - 3.0;
        auto d3 = Quantity<si::one, double>(-1.0);
        ASSERT_EQ(d2, d3);
    }
    // NOLINTEND
}