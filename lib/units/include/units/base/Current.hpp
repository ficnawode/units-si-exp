#pragma once

#include "units/Quantity.hpp"

namespace units
{
    using Current = Quantity<si_dimensions::A>;

    namespace literals
    {
        constexpr auto operator"" _uA(long double value)
        {
            auto scale = 1e-6;
            return Current(scale * value);
        }
        constexpr auto operator"" _mA(long double value)
        {
            auto scale = 1e-3;
            return Current(scale * value);
        }
        constexpr auto operator"" _A(long double value)
        {
            return Current(value);
        }
        constexpr auto operator"" _kA(long double value)
        {
            auto scale = 1e3;
            return Current(scale * value);
        }
    }
}