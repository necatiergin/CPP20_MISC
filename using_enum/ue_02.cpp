namespace nec {
	class Erg {
	public:
		enum class Color { white, yellow, blue, red};
	};
	using enum Erg::Color; 
}

int main()
{
	auto x = nec::yellow;
	nec::color nc; //invalid
}
