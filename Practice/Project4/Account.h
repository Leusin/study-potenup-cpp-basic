#pragma once

class Account
{
public:
	Account(int id, const char* name, int balance = 0);
	virtual ~Account();


	// TODO: 투두테스트 
	virtual void Deposit(int val);
	void Withdrawal(int val);
	void Print() const;
	char* GetName() const;

protected:
	int id;
	char* name;
	int balance;
};