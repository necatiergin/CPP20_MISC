//C++ 20 öncesi work-around

#include <utility>
#include <tuple>

template <class... Args>
auto delay_invoke_foo(Args... args) {
    return[tup = std::make_tuple(std::move(args)...)]() -> decltype(auto) {
        return std::apply([](auto const&... args) -> decltype(auto) {
            return foo(args...);
            }, tup);
    };
}
