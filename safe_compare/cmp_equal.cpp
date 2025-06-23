template<class T, class U>
constexpr bool cmp_equal(T t, U u) noexcept 
{
    if constexpr (std::is_signed_v<T> == std::is_signed_v<U>)
        return t == u;
    else if constexpr (std::is_signed_v<T>)
        return t >= 0 && static_cast<std::make_unsigned_t<T>>(t) == u;
    else
        return u >= 0 && t == static_cast<std::make_unsigned_t<U>>(u);
}
