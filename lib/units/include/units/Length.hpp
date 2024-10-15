#pragma once

#include "Quantity.hpp"

namespace units
{
    using Length = Quantity<si_dimensions::m>;
    using Distance = Length;
    namespace literals
    {
        constexpr auto operator"" _nm(long double value)
        {
            auto scale = 1e-9;
            return Length(scale * value);
        }

        constexpr auto operator"" _um(long double value)
        {
            auto scale = 1e-6;
            return Length(scale * value);
        }

        constexpr auto operator"" _mm(long double value)
        {
            auto scale = 1e-3;
            return Length(scale * value);
        }

        constexpr auto operator"" _cm(long double value)
        {
            auto scale = 1e-2;
            return Length(scale * value);
        }

        constexpr auto operator"" _m(long double value)
        {
            return Length(value);
        }

        constexpr auto operator"" _km(long double value)
        {
            auto scale = 1e3;
            return Length(scale * value);
        }

    }
}