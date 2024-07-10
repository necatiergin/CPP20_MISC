#include <source_location>
#include <iostream>
	
auto foo()
{
	auto sl = std::source_location::current();

	//...
	return sl;
}

int main()
{
	auto sl = foo();

	std::cout << "file name     : " << sl.file_name() << '\n';
	std::cout << "function name : " << sl.function_name() << '\n';
	std::cout << "line/col      : " << sl.line() << '/' << sl.column() << '\n';
}
