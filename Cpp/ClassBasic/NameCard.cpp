#include "NameCard.h"
#include <iostream>

NameCard::NameCard(const char* n, const  char* p, const char* e, const  char* j)
	: name(CreateStr(n))
	, phone(CreateStr(p))
	, email(CreateStr(e))
	, job(CreateStr(j))
{
}

NameCard::~NameCard()
{
	if (name != nullptr) delete[] name;
	if (phone != nullptr) delete[] phone;
	if (email != nullptr) delete[] email;
	if (job != nullptr) delete[] job;
}


void NameCard::ShowData()
{
	std::cout << "이름: " << name << "\n";
	std::cout << "전화번호: " << phone << "\n";
	std::cout << "이메일: " << email << "\n";
	std::cout << "직업: " << job << "\n";
}

char* NameCard::CreateStr(const char* val)
{
	size_t len = strlen(val) + 1;
	char* buffer = new char[len];
	strcpy_s(buffer, len, val);

	return buffer;
}
