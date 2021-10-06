#include <tuple>
#include <utility>

void g(int, int) {}

// C++17
template<class F, class... Args>
auto delay_apply(F&& f, Args&&... args) 
{
    return[f = std::forward<F>(f), tup = std::make_tuple(std::forward<Args>(args)...)]()
        -> decltype(auto) {
        return std::apply(f, tup);
    };
}

// C++20
template<typename F, typename... Args>
auto delay_call(F&& f, Args&&... args) 
{
    return[f = std::forward<F>(f), ...f_args = std::forward<Args>(args)]()
        -> decltype(auto) {
        return f(f_args...);
    };
}

void f() 
{
    delay_call(g, 1, 2)();
}
