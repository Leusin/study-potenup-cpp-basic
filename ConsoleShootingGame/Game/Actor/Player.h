#pragma once

#include "Actor/Actor.h"


/*
* TODO: Player 구현할 것
* [] 좌우 이동 - 키입력 기반
* [] 탄약 발사 - 키입력 기반, 액터 생성
*	[] 단발: Fire()
*	[] 연사: FireInterval(float deltaTime)
*/

class Player : public Actor
{
	RTTI_DECLARATIONS(Player, Actor)

public:
	Player();

	virtual void Tick(float deltaTime) override;

private:
	void Fire();
	void FireInterval(float deltaTime);

private:
	float fireInterval = 0.15f;
};
