#include <iostream>
#include "Vector2.h"

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

void Increment()
{
	static int count = 0;
	++count;
	std::cout << count << "\n";
}

int main()
{
	Point point(20, 30);
	std::cout << point << "\n";

	Vector2 position(10, 20);
	Vector2 speed(2, 2);
	Vector2 power(3, 4);
	Vector2 result = position.Add(speed.Multiply(power));

	std::cout << result << "\n";

	std::cout << (Vector2(1, 2) - Vector2(3, 4)) << "\n";	// (-2 , -2)
	std::cout << (Vector2(1, 2) == Vector2(3, 4)) << "\n";	// 0
	std::cout << (Vector2(1, 1) == Vector2(1, 1)) << "\n";	// 1
	std::cout << (Vector2(1, 2) != Vector2(3, 4)) << "\n";	// 1

	Vector2 vec(1, 2);
	vec += Vector2(3, 4);
	std::cout << vec << "\n"; // (4 , 5)

	Increment();
	Increment();
	Increment();

	return 0;
}