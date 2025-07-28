#include "CreditAccount.h"

#include <iostream>

CreditAccount::CreditAccount(int id, const char* name, int balance)
	: Account(id, name, balance)
{
}

CreditAccount::~CreditAccount()
{
}

void CreditAccount::Deposit(int val)
{
	balance += static_cast<int>(balance * 0.01f);
	balance += val;
}

void CreditAccount::Print() const
{
	std::cout << "신용 ";
	Account::Print(); // std::cout << "계좌번호: " << id << " / 고객 이름: " << name << " / 고객의 잔액: " << balance << "\n";
}
