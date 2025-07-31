#pragma once

#include "Actor/Actor.h"

#include "Utils/Timer.h"

/// <summary>
/// 이동 패턴
/// - 왼쪽에서 생성되면 왼쪽 이동
/// - 오른쪽에서 생성되면 오른쪽 이동
/// </summary>
class Enemy :public Actor
{
	enum class MoveDirection
	{
		None = -1,
		Left,
		Right,
		Length
	};

	RTTI_DECLARATIONS(Enemy, Actor)

public:
	Enemy(const char* image  = "<-=->", int yPosition = 5);

	virtual void Tick(float deltaTime) override;

private:
	MoveDirection direction = MoveDirection::None; // 이동 방향

	float xPosition = 0.f; // 속력을 고려한 위치 계산

	float moveSpeed = 5.f; // 이속

	Timer timer;
};
