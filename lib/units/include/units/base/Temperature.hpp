#pragma once

#include "units/Quantity.hpp"

namespace units
{
    using Temperature = Quantity<si_dimensions::K>;

    namespace literals
    {
        constexpr auto operator"" _mK(long double value)
        {
            auto scale = 1e-3;
            return Temperature(scale * value);
        }
        constexpr auto operator"" _K(long double value)
        {
            return Temperature(value);
        }
    }
}