#pragma once

class Printer
{
public:
	void SetString(const char * str);
	void ShowString();

private:
	char* cstring = nullptr;
};