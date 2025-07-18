#pragma once

class Circle
{
public:
	Circle(int radius)
	{
		this->radius = radius;
	}

	int GetArea()
	{
		return pi * radius * radius;
	}

	int GetGirth()
	{
		return 2 * pi * radius;
	}

private:
	const float pi = 3.14;
	int radius = 0;
};
