#pragma once

#include "Quantity.hpp"

namespace units
{
    // 1V=1kg*m^2/(A*s^3)
    using Voltage = Quantity<Dimension<2, 0, -1, -3, 0, 1, 0>>;

    namespace literals
    {
        constexpr auto operator"" _uV(long double value)
        {
            auto scale = 1e-6;
            return Voltage(scale * value);
        }
        constexpr auto operator"" _mV(long double value)
        {
            auto scale = 1e-3;
            return Voltage(scale * value);
        }
        constexpr auto operator"" _V(long double value)
        {
            return Voltage(value);
        }
        constexpr auto operator"" _kV(long double value)
        {
            auto scale = 1e3;
            return Voltage(scale * value);
        }
    }
}