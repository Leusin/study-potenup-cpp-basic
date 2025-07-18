#include "Printer.h"
#include <iostream>

void Printer::SetString(const char* str)
{
	if (cstring != nullptr)
	{
		delete[] cstring;
	}

	size_t len = strlen(str) + 1;
	cstring = new char[len];
	strcpy_s(cstring, len, str);
}

void Printer::ShowString()
{
	if (cstring == nullptr)
	{
		return;
	}

	std::cout << cstring << "\n";
}
