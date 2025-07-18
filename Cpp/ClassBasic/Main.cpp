
#include "Player.h"
#include "Calculator.h"
#include "Printer.h"

#include "Rectangle.h"
#include "Circle.h"

#include "NameCard.h"

int main()
{
	NameCard jang("Jane Se Yun", "010-000-0000", "abd@def.com", "Lecturer");
	jang.ShowData();

	Rectangle rect = Rectangle(3, 4);    // Rectangle(가로길이, 세로길이)
	std::cout << "면적: " << rect.GetArea() << "\n";
	std::cout << "둘레: " << rect.GetGirth() << "\n";

	Circle circle = Circle(5);    // Circle(원의 반지름)
	std::cout << "면적: " << circle.GetArea() << "\n";
	std::cout << "둘레: " << circle.GetGirth() << "\n";

	Printer printer;
	printer.ShowString();

	printer.SetString("Hello C++");
	printer.ShowString();

	printer.SetString("I Want to be a Good Developer");
	printer.ShowString();

	Calculator calculator;

	std::cout << "3+5=" << calculator.Add(3, 5) << "\n";
	std::cout << "3/5=" << calculator.Divide(3, 5) << "\n";
	std::cout << "12-7=" << calculator.Substract(12, 7) << "\n";
	std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";

	calculator.ShowOperationCount();
}