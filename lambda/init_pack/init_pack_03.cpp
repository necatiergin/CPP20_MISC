//bu kod gecersiz
#include <functional>
#include <utility>

template<class F, class... Args>
auto delay_invoke(F f, Args... args) {
    return[f = std::move(f), _args = std::move(args)...]() -> decltype(auto) {
        return std::invoke(f, _args...);
    };
}
