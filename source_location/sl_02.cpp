#include <print>
#include <string_view>
#include <source_location>

using namespace std::string_view_literals;

void log_error(std::string_view err_msg, std::source_location sl = std::source_location::current())
{
	std::println("{}:{} {}", sl.file_name(), sl.line(), err_msg);
}

int main()
{
	log_error("an error msg");
	log_error("another error msg", std::source_location::current());
}
