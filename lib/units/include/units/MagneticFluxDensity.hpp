#include "Quantity.hpp"

namespace units
{

    // 1T = 1kg/(A*s^2)
    using Tesla = Quantity<Dimension<0, 0, -1, -2, 0, 1, 0>, double>;
    namespace literals
    {
        constexpr auto operator"" _mT(unsigned long long value)
        {
            auto scale = 1e-3;
            return Tesla(scale * value);
        }

        constexpr auto operator"" _T(long double value)
        {
            return Tesla(value);
        }

    }
}