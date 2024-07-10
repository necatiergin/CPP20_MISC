#include <source_location>
#include <iostream>
#include <vector>

std::vector<std::source_location> slvec;

void foo()
{
	slvec.push_back(std::source_location::current());
	//...
}

void bar()
{
	slvec.push_back(std::source_location::current());
	//...
}

void baz()
{
	slvec.push_back(std::source_location::current());
	//...
}

int main()
{
	foo();
	bar();
	baz();

	for (const auto& sl : slvec) {
		std::cout << sl.function_name() << ' ' << sl.line() << '/' << sl.column() << '\n';
	}
}
