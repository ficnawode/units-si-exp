#pragma once

#define SI_DEFAULT_VALUE_TYPE float

namespace units
{
    template <int L, int T, int I, int t, int l, int m, int mol> struct Dimension;
    template <typename Dimension, typename T> class Quantity;

}
