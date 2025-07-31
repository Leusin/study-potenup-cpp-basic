#pragma once

#include "Actor/Actor.h"

/// <summary>
/// 적이 발사하는 탄약
/// 위에서 아래 방향으로 이동
/// 이동 빠르기를 가지며, 플레이어와 충돌하거나 화면을 벗어나면 제거됨
/// </summary>
class EnemyBullet :public Actor
{
	RTTI_DECLARATIONS(EnemyBullet, Actor)

public:
	EnemyBullet(const Vector2& position, float moveSpeed);

	virtual void Tick(float deltaTime) override;

private:
	float moveSpeed = 0.0f;
	float yPosition = 0.0f;
};