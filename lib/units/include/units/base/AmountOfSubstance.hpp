#pragma once

#include "units/Quantity.hpp"

namespace units
{
    using AmountOfSubstance = Quantity<si_dimensions::mol>;

    namespace literals
    {
        constexpr auto operator"" _mol(long double value)
        {
            return AmountOfSubstance(value);
        }
    }
}