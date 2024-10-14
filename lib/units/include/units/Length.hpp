#pragma once
#include "Quantity.hpp"
#include "fwd.hpp"

namespace units
{
    using Length = si::m;

    namespace literals
    {

        constexpr auto operator"" _nm(long double value)
        {
            auto scale = 1e-9;
            return Quantity<si::m>(scale * value);
        }

        constexpr auto operator"" _um(long double value)
        {
            auto scale = 1e-6;
            return Quantity<si::m>(scale * value);
        }

        constexpr auto operator"" _mm(long double value)
        {
            auto scale = 1e-3;
            return Quantity<si::m>(scale * value);
        }

        constexpr auto operator"" _cm(long double value)
        {
            auto scale = 1e-2;
            return Quantity<si::m>(scale * value);
        }

        constexpr auto operator"" _m(long double value)
        {
            return Quantity<si::m>(value);
        }

        constexpr auto operator"" _km(long double value)
        {
            auto scale = 1e3;
            return Quantity<si::m>(scale * value);
        }

    }
}