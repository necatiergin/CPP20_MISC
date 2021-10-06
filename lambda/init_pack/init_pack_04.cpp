//workaround before C++20

#include <tuple>

template<class F, class... Args>
auto delay_invoke(F f, Args... args) {
    return[f = std::move(f), tup = std::make_tuple(std::move(args)...)]() -> decltype(auto) {
        return std::apply(f, tup);
    };
}
