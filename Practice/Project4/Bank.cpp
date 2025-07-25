#include "Bank.h"

#include <iostream>
#include "CreditAccount.h"
#include "DonationAccount.h"

Bank::Bank()
{
	LoadDatas();
}

Bank::~Bank()
{
	for (int i = 0; i < count; i++)
	{
		delete accounts[i];
	}
}

void Bank::Run()
{
	char input = '\0';
	while (input != 'Q' && input != 'q')
	{
		std::cout << "[ 1: 계좌 개설 / 2: 입금 / 3: 출금 / 4: 전체 고객 잔액 조회 / Q 또는 q: 종료 ]\n: ";
		std::cin >> input;

		if (input == '1')
		{
			std::cout << "[ 계좌 개설 ]\n: ";
			int id = count;
			std::cout << "이름 입력(계좌 번호 " << id << "): ";
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

			// 파일 쓰기
			// 계좌번호(= 줄번호 - 1),이름,계좌종류(1 or 2),잔액
			{

				// 파일 열기
				FILE* file = nullptr;
				fopen_s(&file, "BankData.txt", "rt"); // 텍스트 파일을 읽기 전용으로 읽는다.

				if (file == nullptr)
				{
					std::cout << "파일을 열 수 없습니다. \n";
					return;
				}

				// 파일 닫기
				fclose(file);
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
}

void Bank::LoadDatas()
{
	// 파일 열기
	FILE* file = nullptr;
	fopen_s(&file, "BankData.txt", "rt"); // 텍스트 파일을 읽기 전용으로 읽는다.

	if (file == nullptr)
	{
		std::cout << "파일을 열 수 없습니다. \n";
		return;
	}

	char b[256];
	int line = 1;
	while (fgets(b, sizeof(b), file) != nullptr) //한 줄씩 읽는다.
	{
		std::cout << line << " : " << b;
		line++;
	}


	// 파일 닫기
	fclose(file);
}
