#include "Player.h"

#include <iostream>
//#include "Engine.h"
#include "Input.h"
#include "Game/Game.h"
#include "Level/Level.h"
#include "Interface/ICanPlayerMove.h"

Player::Player(const Vector2& position)
	: Actor('@', Color::Red, position)
{
	SetSortingOrder(3);
}

void Player::BeginPlay()
{
	super::BeginPlay();

	// 인터페이스 얻어오기
	Level* owner = GetOwner();
	if (owner)
	{
		canPlayerMoveInterface = dynamic_cast<ICanPlayerMove*>(owner);

		if (!canPlayerMoveInterface)
		{
			std::cout << "Can't cast Level* to ICanPlayerMove*\n";
		}
	}

}

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 종료
	if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleMeneu();
		return;
	}

	// 입력처리
	// 이동하기 전에 이동할 수 있는지 판단 후 이동
	if (Input::Get().GetKeyDown(VK_RIGHT))
	{
		Vector2 position = Position();
		position.x += 1;
		if (canPlayerMoveInterface->CheckPlayerMove(Position(), position))
		{
			SetPosition(position);
		}
	}
	if (Input::Get().GetKeyDown(VK_LEFT))
	{
		Vector2 position = Position();
		position.x -= 1;
		if (canPlayerMoveInterface->CheckPlayerMove(Position(), position))
		{
			SetPosition(position);
		}
	}
	if (Input::Get().GetKeyDown(VK_UP))
	{
		Vector2 position = Position();
		position.y -= 1;
		if (canPlayerMoveInterface->CheckPlayerMove(Position(), position))
		{
			SetPosition(position);
		}
	}
	if (Input::Get().GetKeyDown(VK_DOWN))
	{
		Vector2 position = Position();
		position.y += 1;
		if (canPlayerMoveInterface->CheckPlayerMove(Position(), position))
		{
			SetPosition(position);
		}
	}

}
