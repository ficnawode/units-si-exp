#include "units/Quantity.hpp"

#include "units/base/Length.hpp"
#include "units/base/Time.hpp"

#include "units/compound/MagneticFluxDensity.hpp"
#include "units/compound/Voltage.hpp"

#include <iostream>
#include <gtest/gtest.h>

namespace
{
    using namespace units;
    using namespace units::literals;

    TEST(physics_tests, voltage_literals)
    {
        auto v = 1.0_V;
        auto uV = 1.0_uV;
        auto mV = 1.0_mV;
        auto kV = 1.0_kV;

        EXPECT_FLOAT_EQ(v.raw_value(), 1.0);
        EXPECT_FLOAT_EQ(uV.raw_value(), 1.0e-6);
        EXPECT_FLOAT_EQ(mV.raw_value(), 1.0e-3);
        EXPECT_FLOAT_EQ(kV.raw_value(), 1.0e3);
    }

    TEST(physics_tests, calculate_voltage_induced)
    {
        auto length_a = 1.0_cm;
        auto length_b = 2.0_cm;

        auto cos_theta = 1.0;

        auto B = 1.0_T;
        auto Area = length_a * length_b;

        auto flux = B * Area * cos_theta;
        const float N = 1.0;
        auto voltage = flux / 1.0_s * N;

        std::cout << voltage.to_string() << std::endl;

        auto res_unit = 1.0_V;

        auto v1 = voltage / voltage.raw_value();
        auto v2 = res_unit / res_unit.raw_value();

        EXPECT_TRUE(v1 == v2);
    }

}