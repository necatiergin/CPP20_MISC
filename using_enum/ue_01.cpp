enum class Pos {on, off, standby, hold};

void foo()
{
	//Pos x = off; //error
}

void bar()
{
	using enum Pos;
	Pos x = off; //valid
	Pos ar[] = { on, off, standby, hold }; //valid
}

void baz()
{
	using Pos::off;
	Pos x = off; //valid
	//Pos y = on; // error
	//x = standby; //error
}
