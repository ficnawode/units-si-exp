#pragma once

#include "units/Quantity.hpp"

namespace units
{

    // 1T = 1kg/(A*s^2)
    using MagneticFluxDensity = Quantity<Dimension<0, 0, -1, -2, 0, 1, 0>>;
    namespace literals
    {
        constexpr auto operator"" _mT(long double value)
        {
            auto scale = 1e-3;
            return MagneticFluxDensity(scale * value);
        }

        constexpr auto operator"" _T(long double value)
        {
            return MagneticFluxDensity(value);
        }

    }
}