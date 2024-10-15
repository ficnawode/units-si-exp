#pragma once

#include "units/Quantity.hpp"

namespace units
{

    using Time = Quantity<si_dimensions::s>;

    namespace literals
    {
        constexpr auto operator"" _s(long double value)
        {
            return Time(value);
        }
    }
}