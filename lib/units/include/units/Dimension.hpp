#pragma once

#include <iostream>
#include <ratio>
#include <type_traits>
#include "fwd.hpp"

template <typename D1, typename D2> struct MultiplyDimension;
template <typename D1, typename D2> struct DivideDimension;

template <int m = 0, int K = 0, int A = 0, int s = 0, int Cd = 0, int kg = 0, int mol = 0> struct Dimension
{
private:
    static constexpr auto _m = m;
    static constexpr auto _K = K;
    static constexpr auto _A = A;
    static constexpr auto _s = s;
    static constexpr auto _Cd = Cd;
    static constexpr auto _kg = kg;
    static constexpr auto _mol = mol;

    friend struct MultiplyDimension<Dimension, Dimension>;
    friend struct DivideDimension<Dimension, Dimension>;
};

template <typename D1, typename D2> struct MultiplyDimension
{
public:
    using type = Dimension<
        D1::_m + D2::_m, //
        D1::_K + D2::_K,
        D1::_A + D2::_A,
        D1::_s + D2::_s,
        D1::_Cd + D2::_Cd,
        D1::_kg + D2::_kg,
        D1::_mol + D2::_mol>;
};

template <typename D1, typename D2> struct DivideDimension
{
public:
    using type = Dimension<
        D1::_m - D2::_m, //
        D1::_K - D2::_K,
        D1::_A - D2::_A,
        D1::_s - D2::_s,
        D1::_Cd - D2::_Cd,
        D1::_kg - D2::_kg,
        D1::_mol - D2::_mol>;
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
