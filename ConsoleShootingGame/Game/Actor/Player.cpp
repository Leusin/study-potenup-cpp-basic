#include "Player.h"

#include <Windows.h> // VK 때문에 사용
#include "Input.h"
#include "Utils/Utils.h"
#include "Level/Level.h"
#include "Core/Engine.h"

Player::Player()
	: Actor("<<A>>", Color::Red)
{
	// 시작 위치 설정
	int xPosition = Engine::Get().Width() / 2 - Width() / 2;
	int yPosition = Engine::Get().Height() - 2;

	//TEST
	//int xPosition = 10;
	//int yPosition = 10;
	SetPosition({ xPosition, yPosition });
}

void Player::Tick(float deltaTime)
{
	if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		QuitGame();
		return;
	}

	//
	// 미사일 발사
	//

	if (Input::Get().GetKey(VK_SPACE))
	{
		Fire();
	}

	//
	// 방향키 입력
	//

	if (Input::Get().GetKey(VK_LEFT)) // 좌
	{
		Vector2 position = Position();
		position.x -= 1;
		SetPosition(position);
	}
	if (Input::Get().GetKey(VK_RIGHT)) // 우
	{
		Vector2 position = Position();
		position.x += 1;
		SetPosition(position);
	}
}

void Player::Fire()
{
	// TODO: 플레이어 탄약 객체 생성
}

void Player::FireInterval(float deltaTime)
{
}
