#include "NameCard.h"
#include <iostream>

NameCard::NameCard()
{
	name = CreateStr("other.name");
	phone = CreateStr("other.phone");
	email = CreateStr("other.email");
	job = CreateStr("other.job");
}

NameCard::NameCard(const char* n, const  char* p, const char* e, const  char* j)
	: name(CreateStr(n))
	, phone(CreateStr(p))
	, email(CreateStr(e))
	, job(CreateStr(j))
{
}

NameCard::NameCard(const NameCard& other)
	: name(CreateStr(other.name))
	, phone(CreateStr(other.phone))
	, email(CreateStr(other.email))
	, job(CreateStr(other.job))
{
	/*int len = strlen(other.name) + 1;
	name = new char[len];
	strcpy_s(name, len, other.name);*/
	name = nullptr;
	phone = nullptr;
	email = nullptr;
	job = nullptr;

	name = CreateStr(other.name);
	phone = CreateStr(other.phone);
	email = CreateStr(other.email);
	job = CreateStr(other.job);
}

NameCard::~NameCard()
{
	if (name != nullptr) delete[] name; name = nullptr;
	if (phone != nullptr) delete[] phone; phone = nullptr;
	if (email != nullptr) delete[] email; email = nullptr;
	if (job != nullptr) delete[] job; job = nullptr;
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
