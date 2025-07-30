#pragma once

#include "Actor/Actor.h"

/// <summary>
/// 화면 위로 이동
/// </summary>
class PlayerBullet : public Actor
{
	RTTI_DECLARATIONS(PlayerBullet, Actor)

public:
	PlayerBullet(const Vector2& position);

	virtual void Tick(float deltaTime) override;

private:
	float moveSpeed = 20.f;
	float yPosition = 0.f;
};
