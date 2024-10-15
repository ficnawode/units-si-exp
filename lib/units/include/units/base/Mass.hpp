#pragma once

#include "units/Quantity.hpp"

namespace units
{
    using Mass = Quantity<si_dimensions::kg>;

    namespace literals
    {
        constexpr auto operator"" _mg(long double value)
        {
            auto scale = 1e-6;
            return Mass(scale * value);
        }
        constexpr auto operator"" _g(long double value)
        {
            auto scale = 1e-3;
            return Mass(scale * value);
        }
        constexpr auto operator"" _kg(long double value)
        {
            return Mass(value);
        }
    }
}