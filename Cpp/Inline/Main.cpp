#include <iostream>

# define SquareMec(x) ((x) * (x))
inline int SquareInline(int x)
{
	return x * x;
}

int main()
{
	std::cout << SquareMec(10) << "\n";
	
	// 위 코드는 전처리과정을 거치면 다음과 같이 변한다.
	// std::cout << (10) ((10) * (10)) << "\n";

	std::cout << SquareInline(10) << "\n";

	return 0;
}