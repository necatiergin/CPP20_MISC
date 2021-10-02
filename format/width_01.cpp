#include <format>
#include <iostream>

int main()
{
	int x = 13;

	std::cout << std::format("x = {}", x) << '\n';
	std::cout << std::format("|{:16}|", x) << '\n';
	std::cout << std::format("|{:>16}|", x) << '\n';
	std::cout << std::format("|{:<16}|", x) << '\n';
	std::cout << std::format("|{:^16}|", x) << '\n';
	std::cout << std::format("|{:_>16}|", x) << '\n';
	std::cout << std::format("|{:_<16}|", x) << '\n';
	std::cout << std::format("|{:_^16}|", x) << '\n';
}
