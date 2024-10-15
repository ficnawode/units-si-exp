#pragma once

#include "Dimension.hpp"
#include "fwd.hpp"

namespace units
{
    template <typename Dimension, typename T = SI_DEFAULT_VALUE_TYPE> class Quantity
    {
    public:
        constexpr explicit Quantity(T v) : value(v)
        {
            assert_floating_point<T>();
        }

        template <typename OtherDimension>
        constexpr auto operator=(const Quantity<OtherDimension, T>& other) const
        {
            assert_same_dimension<Dimension, OtherDimension>();
            value = other.value;
        }

        template <typename OtherDimension>
        constexpr auto operator*(const Quantity<OtherDimension, T>& other) const
        {
            using ResultDimension =
                typename MultiplyDimension<Dimension, OtherDimension>::type;
            return Quantity<ResultDimension, T>(value * other.value);
        }

        template <typename FloatLike> //
        constexpr auto operator*(const FloatLike scale) const
        {
            assert_floating_point<FloatLike>();
            return Quantity<Dimension, T>(value * scale);
        }

        template <typename OtherDimension>
        constexpr auto operator/(const Quantity<OtherDimension, T>& other) const
        {
            using ResultDimension =
                typename DivideDimension<Dimension, OtherDimension>::type;
            return Quantity<ResultDimension, T>(value / other.value);
        }

        template <typename FloatLike> //
        constexpr auto operator/(const FloatLike scale) const
        {
            assert_floating_point<FloatLike>();
            return Quantity<Dimension, T>(value / scale);
        }

        template <typename OtherDimension>
        constexpr auto operator+(const Quantity<OtherDimension, T>& other) const
        {
            assert_same_dimension<Dimension, OtherDimension>();
            return Quantity<Dimension, T>(value + other.value);
        }

        template <typename FloatLike> //
        constexpr auto operator+(const FloatLike other) const
        {
            assert_floating_point<FloatLike>();
            assert_dimensionless<Dimension>();
            return Quantity<Dimension, T>(value + other);
        }

        template <typename OtherDimension>
        constexpr auto operator-(const Quantity<OtherDimension, T>& other) const
        {
            assert_same_dimension<Dimension, OtherDimension>();
            return Quantity<Dimension, T>(value - other.value);
        }

        template <typename FloatLike> //
        constexpr auto operator-(const FloatLike other) const
        {
            assert_floating_point<FloatLike>();
            assert_dimensionless<Dimension>();
            return Quantity<Dimension, T>(value - other);
        }

        template <typename OtherDimension>
        constexpr auto operator<=>(const Quantity<OtherDimension, T>& other) const
        {
            assert_same_dimension<Dimension, OtherDimension>();
            return value <=> other.value;
        }

        template <typename OtherDimension>
        constexpr auto operator==(const Quantity<OtherDimension, T>& other) const
        {
            assert_same_dimension<Dimension, OtherDimension>();
            return value == other.value;
        }

        T raw_value() const
        {
            return value;
        }

    private:
        template <typename D1, typename D2> //
        inline void assert_same_dimension() const
        {
            static_assert(std::is_same_v<D1, D2>);
        }

        template <typename D> //
        inline void assert_dimensionless() const
        {
            static_assert(std::is_same_v<D, si_dimensions::one>);
        }

        template <typename D> //
        inline void assert_floating_point() const
        {
            static_assert(std::is_floating_point_v<D>);
        }

        T value;

        template <typename D1, typename T1> friend class Quantity;
    };
}