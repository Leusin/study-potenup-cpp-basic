#include <iostream>
#include "Engine.h"
#include "Math/Vector2.h"

int main()
{
	Engine engine;
	//engine.Run();

	Vector2 a(10, 20);
	Vector2 b(30, 40);
	std::cout << (a + b).ToString() << "\n";

	return 0;
}