#include "Enemy.h"

#include "Engine.h"
#include "Level/Level.h"
#include "Utils/Utils.h"
#include "Actor/EnemyBullet.h"

Enemy::Enemy(const char* image, int yPosition)
	: Actor(image)
{
	// 이동 방향을 정하기 위한 난수
	int random = Utils::Random(1, 10);

	// 짝수인 경우
	if (random % 2 == 0)
	{
		// 화면 오른쪽 끝에서 생성되도록 위치 / 이동 방향 설정
		direction = MoveDirection::Left;
		xPosition = static_cast<float>(Engine::Get().Width() - Width());
	}
	// 홀수인 경우
	else // (random % 2 != 0)
	{
		// 회면 왼쪽 끝에서 생성되도록 위치 / 이동 방향 설정
		direction = MoveDirection::Right;
		xPosition = 0.0f;
	}

	SetPosition({ static_cast<int>(xPosition) , yPosition }); // 위치 설정

	// 발사 간격 시간 설정.
	timer.SetTargetTime(Utils::RandomFloat(1.0f, 3.0f));
}

void Enemy::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 이동 방향 설정
	float dir = (direction == MoveDirection::Left) ? -1.f : 1.f;

	xPosition += moveSpeed * dir * deltaTime;
	// 화면 밖에 벗어났는지 확인.
	if (xPosition < 0.0f || (int)xPosition > Engine::Get().Width() - Width())
	{
		// 화면에서 벗어나면 액터 제거.
		Destroy();
		return;
	}

	SetPosition({ static_cast<int>(xPosition), Position().y });

	timer.Tick(deltaTime); // 시간 축적

	// 시간이 경과하면 탄약 발사
	{
		if (!timer.IsTimeout())
		{
			return;
		}

		// 발사
		Vector2 firePosition{ Position().x + Width() / 2, Position().y + 1 };
		float bulletSpeed = Utils::RandomFloat(10.f, 20.f);
		GetOwner()->AddActor(new EnemyBullet(firePosition, bulletSpeed));

		timer.Reset(); // 타이머 초기화
		timer.SetTargetTime(Utils::RandomFloat(1.f, 3.f));
	}
}
