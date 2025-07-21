# include <iostream>
#include <typeinfo>

class Entity
{
public:
	virtual const char* GetName() const
	{
		return "Entity";
	}
};

class Player : public Entity
{
public:
	Player(const char* name)
	{
		size_t len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}

	~Player()
	{
		delete[] name;
	}

	virtual const char* GetName() const override
	{
		return name;
	}

private:
	char* name = nullptr;
};

int main()
{
	Entity* entity = new Entity();
	std::cout << entity->GetName() << "\n";
	std::cout << typeid(*entity).name() << "\n";
	delete entity;

	Entity* player = new Player("Player");
	std::cout << player->GetName() << "\n";
	std::cout << typeid(*player).name() << "\n";
	delete player;

	return 0;
}