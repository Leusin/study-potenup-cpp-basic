#pragma once

class Acount
{
public:
	Acount(int id, const char* name, int balance = 0);
	~Acount();

	void Deposit(int val);
	void Withdrawal(int val);
	void Print();
	char* GetName() const;

private:
	int id;
	char* name;
	int balance;
};