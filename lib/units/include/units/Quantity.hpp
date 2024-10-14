#pragma once

#include "Dimension.hpp"
#include "fwd.hpp"

template <typename Dimension, typename T = SI_DEFAULT_VALUE_TYPE> class Quantity
{
public:
    constexpr explicit Quantity(T v) : value(v)
    {
        static_assert(std::is_floating_point_v<T>);
    }

    template <typename OtherDimension>
    constexpr auto operator=(const Quantity<OtherDimension, T>& other) const
    {
        static_assert(std::is_same_v<Dimension, OtherDimension>);
        value = other.value;
    }

    template <typename OtherDimension>
    constexpr auto operator*(const Quantity<OtherDimension, T>& other) const
    {
        using ResultDimension =
            typename MultiplyDimension<Dimension, OtherDimension>::type;
        return Quantity<ResultDimension, T>(value * other.value);
    }

    constexpr auto operator*(const T scale) const
    {
        return Quantity<Dimension, T>(value * scale);
    }

    template <typename OtherDimension>
    constexpr auto operator/(const Quantity<OtherDimension, T>& other) const
    {
        using ResultDimension = typename DivideDimension<Dimension, OtherDimension>::type;
        return Quantity<ResultDimension, T>(value / other.value);
    }

    constexpr auto operator/(const T scale) const
    {
        return Quantity<Dimension, T>(value / scale);
    }

    template <typename OtherDimension>
    constexpr auto operator+(const Quantity<OtherDimension, T>& other) const
    {
        static_assert(std::is_same_v<Dimension, OtherDimension>);
        return Quantity<Dimension, T>(value + other.value);
    }

    constexpr auto operator+(const T other) const
    {
        static_assert(std::is_same_v<Dimension, si::one>);
        return Quantity<Dimension, T>(value + other);
    }

    template <typename OtherDimension>
    constexpr auto operator-(const Quantity<OtherDimension, T>& other) const
    {
        static_assert(std::is_same_v<Dimension, OtherDimension>);
        return Quantity<Dimension, T>(value - other.value);
    }

    constexpr auto operator-(const T other) const
    {
        static_assert(std::is_same_v<Dimension, si::one>);
        return Quantity<Dimension, T>(value - other);
    }

    template <typename OtherDimension>
    constexpr auto operator<=>(const Quantity<OtherDimension, T>& other) const
    {
        static_assert(std::is_same_v<Dimension, OtherDimension>);
        return value <=> other.value;
    }

    template <typename OtherDimension>
    constexpr auto operator==(const Quantity<OtherDimension, T>& other) const
    {
        static_assert(std::is_same_v<Dimension, OtherDimension>);
        return value == other.value;
    }

    T raw_value() const
    {
        return value;
    }

private:
    T value;
};