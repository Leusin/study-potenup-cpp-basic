#include "CreditAccount.h"

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
