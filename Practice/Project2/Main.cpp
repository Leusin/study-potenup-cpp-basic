#include <iostream>
#include "Acount.h"

int main()
{
	int count = 0;
	Acount* acounts[100];

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

			acounts[count] = new Acount(id, name);

			count++;

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

			std::cout << acounts[id]->GetName() << "님 입금액을 입력해 주세요:" << "\n";

			int money = 0;
			std::cin >> money;
			acounts[id]->Deposit(money);

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

			std::cout << acounts[id]->GetName() << "님 출금액을 입력해 주세요:" << "\n";

			int money = 0;
			std::cin >> money;
			acounts[id]->Withdrawal(money);
		}
		if (input == '4')
		{
			std::cout << "[ 전체 고객 잔액 조회 ]\n";

			std::cout << "--------------------\n";
			for (int i = 0; i < count; i++)
			{
				if (acounts[i] == nullptr)
				{
					std::cout << "null 예외 발생\n";
					continue;
				}

				acounts[i]->Print();
			}
			std::cout << "--------------------\n";
		}
	}

	for (int i = 0; i < count; i++)
	{
		delete acounts[i];
	}

	return 0;
}