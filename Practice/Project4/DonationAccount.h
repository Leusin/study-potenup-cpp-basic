#pragma once
#include "Account.h"

class DonationAccount : public Account
{
public:
	DonationAccount(int id, const char* name, int balance = 0);
	virtual ~DonationAccount();

	virtual void Deposit(int val) override;
	virtual void Print() const override;

private:
	int donated = 0;
};