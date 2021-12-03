//C++20'den önce

struct Point {
	int x, y;
};

bool operator==(const Point& lhs, const Point& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const Point& lhs, const Point& rhs)
{
	return !(lhs == rhs);
}

//C++20'den sonra

struct Point_ {
	int x, y;
	bool operator==(const Point_ &)const = default;
};


