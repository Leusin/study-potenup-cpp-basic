#include <iostream>
#include "Person.h"
#include "Student.h"

class Entity
{
public:
	Entity()
		: x(0), y(0)
	{
		std::cout << "Entity()\n";
	}

	// 부모는 virtual 소멸자
	virtual ~Entity()
	{
		std::cout << "~Entity()\n";
	}

	void Move(int ax, int ay)
	{
		x += ax;
		y += ay;
	}

protected:
	int x = 0;
	int y = 0;
};

class Player : public Entity
{
public:
	Player()
	{

	}

	Player(const char* name)
		: Entity()
	{
		std::cout << "Player(const char*)\n";

		rsize_t len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	};

	Player(const Player& other)
		: Entity()
	{
		std::cout << "Player()\n";
		x = other.x;
		y = other.y;

		rsize_t len = strlen(other.name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, other.name);
	};

	~Player()
	{
		std::cout << "~Player()\n";
	}

private:
	//int x = 0;
	//int y = 0;
	char* name;
};

int main()
{
	{
		Player p("Player");
		p.Move(5, 5);
	}

	{
		// 업 캐스팅: 자식이 부모로 타입 변환
		Entity* entity = new Player("Player2");

		// 다운 캐스팅
		Player* p3 = (Player*)entity;
		// Player* p3 = new Entity() // 이건 안됨

		/* 매우 나쁜 경우 */
		//Entity* entity2 = new Entity();
		//Player* p3 = (Player*)entity2;

		delete entity;
	}

	{
		Student Jang1 = Student(20, "Jang Se Yun", "Computer Science");
		Jang1.ShowData();

		Student Jang2 = Jang1;
		Jang2.ShowData();
	}

	return 0;
}