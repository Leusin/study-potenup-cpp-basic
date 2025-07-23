#include <iostream>
#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int main()
{
	int count = 0;
	Account* accounts[100];

	char input = '\0';
	while (input != 'Q' && input != 'q')
	{
		std::cout << "1: 계좌 개설 / 2: 입금 / 3: 출금 / 4: 전체 고객 잔액 조회\n";
		std::cin >> input;

		if (input == '1')
		{
			std::cout << "[ 계좌 개설 ]\n";
			int id = count;
			std::cout << "이름 입력(계좌 번호 "<< id <<"): ";
			char name[50];
			std::cin >> name;

			std::cout << "계설할 계좌의 종류(1. 신용 계좌, 2. 기부계좌): ";
			int kide = 0;
			std::cin >> kide;
			if (kide == 1)
			{
				accounts[count] = new CreditAccount(id, name);
				count++;
			}
			if (kide == 2)
			{
				accounts[count] = new DonationAccount(id, name);
				count++;
			}
		}
		if (input == '2')
		{
			std::cout << "[ 입금 ]\n";
			std::cout << "계좌번호 입력 :\n";
			int id = 0;
			std::cin >> id;

			if (0 > id || id >= count)
			{
				continue;
			}

			std::cout << accounts[id]->GetName() << "님 입금액을 입력해 주세요:" << "\n";

			int money = 0;
			std::cin >> money;
			accounts[id]->Deposit(money);

		}
		if (input == '3')
		{
			std::cout << "[ 출금 ]\n";
			std::cout << "계좌번호 입력 :\n";
			int id = 0;
			std::cin >> id;

			if (0 > id || id >= count)
			{
				continue;
			}

			std::cout << accounts[id]->GetName() << "님 출금액을 입력해 주세요:" << "\n";

			int money = 0;
			std::cin >> money;
			accounts[id]->Withdrawal(money);
		}
		if (input == '4')
		{
			std::cout << "[ 전체 고객 잔액 조회 ]\n";

			std::cout << "--------------------\n";
			for (int i = 0; i < count; i++)
			{
				if (accounts[i] == nullptr)
				{
					std::cout << "null 예외 발생\n";
					continue;
				}

				accounts[i]->Print();
			}
			std::cout << "--------------------\n";
		}
	}

	for (int i = 0; i < count; i++)
	{
		delete accounts[i];
	}

	_CrtDumpMemoryLeaks();

	return 0;
}