#include "Acount.h"
#include <iostream>

Acount::Acount(int id, const char* name, int balance)
	: id(id), balance(balance)
{
	size_t len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

Acount::~Acount()
{
	if (name != nullptr)
	{
		delete[] name;
	}
}

void Acount::Deposit(int val)
{
	balance += val;
}

void Acount::Withdrawal(int val)
{
	balance -= val;
}

void Acount::Print()
{
	std::cout << "계좌번호: " << id << "/ 고객 이름: " << name << "/ 고객의 잔액: " << balance << "\n";
}

char* Acount::GetName() const
{
	return name;
}
