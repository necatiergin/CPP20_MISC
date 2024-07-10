#include <iostream>
#include <bitset>

int main()
{
	int x = -1;
	x <<= 1;		// C++17 UB. C++20 Valid 

	std::cout << "x = " << x << '\n';
	std::cout << std::bitset<32>(static_cast<unsigned>(x)) << '\n';
}
