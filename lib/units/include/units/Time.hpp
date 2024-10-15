#pragma once

#include "Quantity.hpp"

namespace units
{

    using Time = Quantity<si::s>;

    namespace literals
    {
        constexpr auto operator"" _s(long double value)
        {
            return Time(value);
        }
    }
}