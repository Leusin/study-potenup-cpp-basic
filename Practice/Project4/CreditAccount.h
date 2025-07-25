#pragma once
#include "Account.h"

class CreditAccount : public Account
{
public:
	CreditAccount(int id, const char* name, int balance = 0);
	virtual ~CreditAccount();

	virtual void Deposit(int val) override;
};