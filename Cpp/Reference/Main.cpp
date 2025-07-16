#include <iostream>

void Increment(int& num)
{
	num++;
}

int main()
{
	int number = 10;

	int& ref = number;

	ref = 30;

	Increment(ref);
	std::cout << ref << "\n";

	return 0;
}