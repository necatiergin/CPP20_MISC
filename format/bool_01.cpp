//iostream'den farklı olarak boolean değerler varsayılan biçimde true ve false olarak yazdırılıyor

#include <format>
#include <iostream>

int main()
{
	std::cout << std::format("{} {}", 10 > 5, 5 > 10) << '\n';
	std::cout << std::format("{:d} {:d}", 10 > 5, 5 > 10) << '\n';
}
