// 2027/7/16

#include <iostream>

using namespace std;

int main()
{
	cout << (void*)new char[8];
	cout << '\n';

	int val = 10;
	int* ptr = &val;

	// int* ptr2 = (int*)ptr; // C-style
	int* ptr2 = reinterpret_cast<int*>(ptr); // 안전한 형변환
	*ptr2 = 20;

	char* buff = new char[20];

	// 메모리 설정
	memset(buff, 0, sizeof(char) * 20);

	delete[] buff;

	// 안됨
	//int& refi = 5;
	//void& refv = nullptr;

	return 0;
}