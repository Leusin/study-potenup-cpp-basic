#include "practice.h"

void Problem_1()
{
	std::cout << "사용자로부터 총 10개의 정수를 입력 받아서 그 합을 출력하는 프로그램을 작성해보자.\n";

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << "번째 입력:";
		int number = 0;
		std::cin >> number;
		sum += number;
	}

	std::cout << "입력 받은 숫자들의 합은 " << sum << "\n";
}

void Problem_2()
{
	std::cout << "사용자로부터 이름과 전화번호를 입력 받아서 배열에 저장한 다음, 그대로 출력해주는 프로그램을 작성해보자.\n";

	std::cout << "이름, 전화번호 입력:";

	char name[255];
	char phoneNumber[255];

	std::cin >> name >> phoneNumber;

	std::cout << "출력: " << name << " " << phoneNumber << "\n";
}

void Problem_3()
{
	std::cout << "숫자 하나를 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해보자. 예를 들어 9를 입력하면 구구단의 9단을 출력해야 한다.\n";

	int num = 0;

	std::cout << "숫자 입력:";

	std::cin >> num;

	for (int i = 1; i < 10; i++)
	{
		std::cout << num << " x " << i << " = " << i * num << "\n";
	}
}

void Problem_4()
{
	std::cout << "영업사원의 급여 계산 프로그램을 작성해보자.\n회사는 모든 영업사원에게 매달 300만원의 기본 급여와 물품 판매 가격의 15 % 에 해당하는 돈을 지급해야 한다.\n예를 들어서 세윤이라는 직원의 이번 달 물품 판매 금액이 100만원이라면 300 + 100 * 0.15 = 315만원을 급여로\n";
	
	int input = 0;

	while (true)
	{
		std::cout << "판매 금액을 만원 단위로 입력(종료는 -1):";

		std::cin >> input;

		if (input == -1)
		{
			break;
		}

		std::cout << "이번 달 급여:" << 300 + input * 0.15<< "\n";
	}

}