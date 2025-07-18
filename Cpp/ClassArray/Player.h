#pragma once

class Player
{
public:
	Player()
	{

	}

	Player(int x, int y)
		: x(x), y(y)
	{

	}

	~Player()
	{

	}

	void ShowPosition() const;

	int GetX() const { return x; }
	void SetX(int x) { this->x = x; }

	int GetY() const { return y; }
	void SetY(int y) { this->y = y; }

	friend void SetPosition(Player& player, int x, int y);

private:
	int x = 0;
	int y = 0;
};

void SetPosition(Player& player, int x, int y);