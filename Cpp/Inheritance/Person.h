#pragma once
#include <iostream>

class Person
{
public:
	Person(int age, const char* name)
		: age(age)
	{
		size_t len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}

	//Person(const Person& other)
	//	: age(other.age)
	//{
	//	size_t len = strlen(other.name) + 1;
	//	this->name = new char[len];
	//	strcpy_s(this->name, len, other.name);
	//}

	virtual ~Person()
	{
		delete[] name;
	}

protected:
	int age = 0;;
	char* name = nullptr;
};

