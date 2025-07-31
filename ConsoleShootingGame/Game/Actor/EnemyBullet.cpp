#include "EnemyBullet.h"

#include "Core/Engine.h"

EnemyBullet::EnemyBullet(const Vector2& position, float moveSpeed)
	: Actor("O", Color::Blue, position)
	, yPosition(static_cast<float>(position.y))
	, moveSpeed(moveSpeed)
{
}

void EnemyBullet::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 아래로 이동 처리
	yPosition += moveSpeed * deltaTime; 

	// 화면 벗어났는지
	if (yPosition >= Engine::Get().Height())
	{
		Destroy();
		return;
	}

	// 벗어나지 않으면 위치 설정
	SetPosition({ Position().x , static_cast<int>(yPosition) });
}
