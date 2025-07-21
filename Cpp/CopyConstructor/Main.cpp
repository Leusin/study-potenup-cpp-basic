#include <iostream>
#include "NameCard.h"

class Player
{
public:
	Player()
		:x(0), y(0)
	{
		const char* difName = "Player()";
		size_t len = strlen(difName) + 1;
		name = new char[len];
		strcpy_s(name, len, difName);

		std::cout << "Player() \n"; 
	}

	Player(int x, int y)
		:x(x), y(y)
	{
		const char* difName = "Player(int, int)";
		size_t len = strlen(difName) + 1;
		name = new char[len];
		strcpy_s(name, len, difName);

		std::cout << "Player(int, int) \n";
	}

	/* 복사 생성자 */
	// L-Val / R-Val / L-Val Ref(&) / R-Val Ref(&&) <--- since C++11
	Player(const Player& other) 
		: x(other.x), y(other.y)//, name(other.name) <- 동적 할당하는 객체는 이런 짓 하면 안된다.
		// 주소의 복사가 읽어난다(64x 라면 8바이트)
		// 기본 생성자처럼 선언하지 않아도 기본적으로 있다. "기본 복사 생성자"라고 한다.
		// 변수의 값을 그대로 대입한다

	{
		std::cout << "Player(const Player&) \n";

		/* 깊은 복사 */
		size_t len = strlen(other.name) + 1;
		name = new char[len];
		strcpy_s(name, len, other.name);
	}

	~Player()
	{
		if (name != nullptr)
		{
			delete[] name;
			name = nullptr;
		}
	}

	void Print()
	{
		std::cout <<"(" << x << ", " << y << ") \n";
	}

private:
	int x = 0;
	int y = 0;
	char* name = nullptr;
};

int main()
{
	Player p1; // "Player()"
	Player p2(10, 20); // "Player(int, int)"
	Player p3(p2); // 복사 생성자 "Player(const Player&), 작성을 하지 않아도 잘 작동한다." 

	p2.Print();
	p3.Print();

	NameCard nc1;
	NameCard nc2(nc1);

	return 0;
}