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
	SaveDatas();

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
				CreateCreditAccount(id, name);
			}
			if (kide == 2)
			{
				CreateDonationAccount(id, name);
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

	// 파일 크기 확인
	fseek(file, 0, SEEK_END);
	size_t filesize = ftell(file);
	fseek(file, 0, SEEK_SET);

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != nullptr) //한 줄씩 읽는다.
	{
		int lineLength = (int)strlen(buffer);
		// 파싱
		//for (int i = 0; i < lineLength; ++i)
		{
			// 무식하게
			/*
			* 종류 번호 이름 잔액
			* 1 kim 0
			* 2 lee 0
			* 2 pack 0
			*/

			// 종류
			char kind[2];
			strncpy_s(kind, 2, buffer, 1);
			std::cout << kind << "\n"; // TEST

			// 이름
			int start = 2;
			int count = 0;
			while (buffer[start + count] != ' ')
			{
				count++;
			}
			int len = count + 1;
			char* name = new char[len];
			strncpy_s(name, len, buffer + start, count);
			std::cout << name << "\n"; // TEST

			// 잔액 
			start += count + 1;
			count = 0;
			while (buffer[start + count] != ' ')
			{
				count++;
			}
			len = count + 1;
			char* moneyStr = new char[len];
			strncpy_s(moneyStr, len, buffer + start, count);
			std::cout << moneyStr << "\n"; // TEST

			// 계좌 생성 
			static int id = 0;
			int moneyNum = 0;
			sscanf_s(moneyStr, "%d", &moneyNum);
			if (kind[0] == '1')
			{
				CreateCreditAccount(id, name, moneyNum);
				
			}
			else if (kind[0] == '2')
			{
				CreateDonationAccount(id, name, moneyNum);
			}
			id++;
			
			// 메모리 정리
			delete[] moneyStr;
			delete[] name;
		}
	}
	std::cout << "\n"; // TEST


	// 파일 닫기
	fclose(file);
}

void Bank::CreateCreditAccount(int id, const char* name, int mony)
{
	accounts[count] = new CreditAccount(id, name, mony);
	count++;
}

void Bank::CreateDonationAccount(int id, const char* name, int mony)
{
	accounts[count] = new DonationAccount(id, name, mony);
	count++;
}

void Bank::SaveDatas()
{
	// 파일 열기
	FILE* file = nullptr;
	fopen_s(&file, "BankData.txt", "wt"); // 텍스트 파일을 읽기 전용으로 읽는다.

	if (file == nullptr)
	{
		std::cout << "파일을 열 수 없습니다. \n";
		return;
	}

	// 한 줄씩 쓰기 
	/*
	* 종류 번호 이름 잔액
	* 1 kim 0
	* 2 lee 0
	* 2 pack 0
	*/
	for (int i = 0; i < count; i++)
	{
		if (dynamic_cast<CreditAccount*>(accounts[i]) != nullptr)
		{
			fprintf(file, "%d %s %d\n", 1, accounts[i]->GetName(), accounts[i]->GetBalance());
		}
		else if (dynamic_cast<DonationAccount*>(accounts[i]) != nullptr)
		{
			fprintf(file, "%d %s %d\n", 2, accounts[i]->GetName(), accounts[i]->GetBalance());
		}
	}

	// 파일 닫기
	fclose(file);
}
