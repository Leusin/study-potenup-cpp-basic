#pragma once
class Rectangle
{
public:
	Rectangle(int width, int hight)
	{
		this->width = width;
		this->hight = hight;
	}

	int GetArea()
	{
		return width * hight;
	}

	int GetGirth()
	{
		return 2 * (width + hight);
	}

private:
	int width = 0;
	int hight = 0;
};

