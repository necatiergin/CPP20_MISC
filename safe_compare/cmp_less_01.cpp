#include <type_traits>
#include <iostream>

template <typename T, typename U>
constexpr bool cmp_less(T t, U u) noexcept
{
    using UT = std::make_unsigned_t<T>;
    using UU = std::make_unsigned_t<U>;

    if constexpr (std::is_signed_v<T> == std::is_signed_v<U>)
        return t < u;
    else if constexpr (std::is_signed_v<T>)
        return t < 0 ? true : UT(t) < u;
    else
        return u < 0 ? false : t < UU(u);
}

int main() 
{
    int x = -5;
    unsigned y = 12;

    boolalpha(std::cout);

    std::cout << cmp_less(x, y) << '\n';
}
