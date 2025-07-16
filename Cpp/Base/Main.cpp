#include <iostream>
#include "practice.h"

void Log(const char* message);

// Entry Point.
int main()
{
	Problem_4();

	Log("Hello World");

	// cout - console out 이라는 뜻
	// << shift 연산자를 오버라이딩한 것
	printf("Hello World %d %s\n", 10, "string test\n"); // C style
	std::cout << "Hello  W " << 10 << " " << "string test\n"; // C++ style
	
	int val1 = 0;
	int val2 = 0;

	// 입출력
	std::cin >> val1;
	std::cout << val1;

	std::cin.get(); // 출력 후 종료되지 않도록 함

	return 0;
}

