#include <source_location>
#include <iostream>

void log(std::source_location sl = std::source_location::current())
{
	std::cout << "file name     : " << sl.file_name() << '\n';
	std::cout << "function name : " << sl.function_name() << '\n';
	std::cout << "line/col      : " << sl.line() << '/' << sl.column() << '\n';
}

int main()
{
	log();
}
