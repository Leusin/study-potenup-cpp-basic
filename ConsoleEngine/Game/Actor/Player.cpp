#include "Player.h"

Player::Player(const Vector2& position)
	: Actor('@', Color::Red, position)
{
}

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	//TODO: 입력처리
}
