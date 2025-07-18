#pragma once
class Calculator
{
public:
	int Add(int a, int b)
	{
		this->a++;
		return a + b;
	}

	int Divide(int a, int b)
	{
		if (b == 0)
		{
			return a;
		}

		this->d++;
		return a / b;
	}

	int Substract(int a, int b)
	{
		this->s++;
		return a - b;
	}

	int Multiply(int a, int b)
	{
		this->m++;
		return a * b;
	}

	void ShowOperationCount();

private:
	int a = 0;
	int d = 0;
	int s = 0;
	int m = 0;
};