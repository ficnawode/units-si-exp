#pragma once

#include "units/Quantity.hpp"

namespace units
{
    using Luminescence = Quantity<si_dimensions::Cd>;
    namespace literals
    {
        constexpr auto operator"" _Cd(long double value)
        {
            return Luminescence(value);
        }
    }
}