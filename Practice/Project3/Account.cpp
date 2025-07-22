#include "Account.h"
#include <iostream>

Account::Account(int id, const char* name, int balance)
	: id(id), balance(balance)
{
	size_t len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

Account::~Account()
{
	if (name != nullptr)
	{
		delete[] name;
	}
}

void Account::Deposit(int val)
{
	balance += val;
}

void Account::Withdrawal(int val)
{
	balance -= val;
}

void Account::Print()
{
	std::cout << "계좌번호: " << id << " / 고객 이름: " << name << " / 고객의 잔액: " << balance << "\n";
}

char* Account::GetName() const
{
	return name;
}
