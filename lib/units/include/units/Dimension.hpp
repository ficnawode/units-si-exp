#pragma once

#include <iostream>
#include <ratio>
#include <type_traits>

template <int L = 0, int T = 0, int I = 0, int t = 0, int l = 0, int m = 0, int mol = 0> struct Dimension
{
    static constexpr auto length = L;
    static constexpr auto temperature = T;
    static constexpr auto current = I;
    static constexpr auto time = t;
    static constexpr auto luminous_intensity = l;
    static constexpr auto mass = m;
    static constexpr auto amount_of_substance = mol;
};

template <typename D1, typename D2> struct MultiplyDimension
{
    using type = Dimension<
        D1::length + D2::length,
        D1::temperature + D2::temperature,
        D1::current + D2::current,
        D1::time + D2::time,
        D1::luminous_intensity + D2::luminous_intensity,
        D1::mass + D2::mass,
        D1::amount_of_substance + D2::amount_of_substance>;
};

template <typename D1, typename D2> struct DivideDimension
{
    using type = Dimension<
        D1::length - D2::length,
        D1::temperature - D2::temperature,
        D1::current - D2::current,
        D1::time - D2::time,
        D1::luminous_intensity - D2::luminous_intensity,
        D1::mass - D2::mass,
        D1::amount_of_substance - D2::amount_of_substance>;
};

template <typename D1, int a> struct PowDimension
{
    using type =
        Dimension<D1::length * a, D1::temperature * a, D1::current * a, D1::time * a, D1::luminous_intensity * a, D1::mass * a, D1::amount_of_substance * a>;
};
namespace si
{
    using one = Dimension<>;
    using m = Dimension<1>;
    using K = Dimension<0, 1>;
    using A = Dimension<0, 0, 1>;
    using s = Dimension<0, 0, 0, 1>;
    using Cd = Dimension<0, 0, 0, 0, 1>;
    using kg = Dimension<0, 0, 0, 0, 0, 1>;
    using mol = Dimension<0, 0, 0, 0, 0, 0, 1>;
}
