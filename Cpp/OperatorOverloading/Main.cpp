#include <iostream>

class Point
{
public:
	Point(int x = 0, int y = 0)
		:x(x), y(y)
	{

	}

	// 맴버 함수 연산자 오버로딩
	friend std::ostream& operator <<(std::ostream& os, const Point& p)
	{
		return os << "(" << p.x << ", " << p.y << ")";
	}

private:
	int x = 0;
	int y = 0;
};


// 비맴버 함수 연산자 오버로딩
//std::ostream& operator <<(std::ostream& os, const Point& p)
//{
//	return os << "(" << p.x << ", " << p.y << ")";
//}

int main()
{
	Point point(20, 30);
	std::cout << point << "\n";

	return 0;
}