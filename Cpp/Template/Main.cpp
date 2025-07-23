#include <iostream>

template <typename T>
void Swap(T& num1, T& num2)
{
	T temp = num1;
	num1 = num2;
	num2 = temp;

	std::cout << typeid(temp).name() << "\n";
}

int main()
{
	int number1 = 10;
	int number2 = 20;
	Swap<int>(number1, number2);

	float number3 = 3.14f;
	float number4 = 5.12f;
	Swap<float>(number3, number4);

	std::cout << "number1: " << number1 << ", number2: " << number2 << "\n";
	std::cout << "number3: " << number3 << ", number4: " << number4 << "\n";
	std::cout << "number1: " << number1 << ", number4: " << number4 << "\n";

	return 0;
}