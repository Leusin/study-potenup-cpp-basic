#include "DonationAccount.h"

#include <iostream>

DonationAccount::DonationAccount(int id, const char* name, int balance)
	: Account(id, name, balance)
{
}

DonationAccount::~DonationAccount()
{
}

void DonationAccount::Deposit(int val)
{
	int donate = static_cast<int>(val * 0.01f);
	donated += donate;
	balance += val - donate;

	std::cout << name << "님, 지금까지 " << donated << " 기부하셨습니다.\n";
}

void DonationAccount::Print() const
{
	std::cout << "기부 ";
	Account::Print(); // std::cout << "계좌번호: " << id << " / 고객 이름: " << name << " / 고객의 잔액: " << balance << "\n";
}
