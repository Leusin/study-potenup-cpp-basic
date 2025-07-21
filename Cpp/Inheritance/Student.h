#pragma once

#include "Person.h"

class Student : public Person
{
public:
	Student(int age, const char* name, const char* major)
		: Person(age, name)
	{
		size_t len = strlen(major) + 1;
		this->major = new char[len];
		strcpy_s(this->major, len, major);
	}

	Student(const Student& other)
		: Person(other.age, other.name)
	{
		size_t len = strlen(other.major) + 1;
		this->major = new char[len];
		strcpy_s(this->major, len, other.major);
	}

	~Student()
	{
		delete[] major;
	}

	void ShowData()
	{
		std::cout << "이름: " << name << "\n";
		std::cout << "나이: " << age << "\n";
		std::cout << "전공: " << major << "\n";
	}

private:
	char* major;
};
