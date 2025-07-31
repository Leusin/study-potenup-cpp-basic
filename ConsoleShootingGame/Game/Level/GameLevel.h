/*
* TODO: GameLevel 구현할 것
* [] npc 생성: 랜덤성을 가미해서 시간마다 적 생성
* [] 충돌 처리: AABB
* [] 점수 처리: 적 없애면 1점득
* [] 게임 판정: 플레이어 사망
* [] 게임 목표: ???
*/

#pragma once

#include "Level/Level.h"

#include "Utils/Timer.h"

/// <summary>
/// 슈팅 게임 메인 레벨
/// </summary>
class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();
	~GameLevel();

	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;

private:
	Timer enemySpawnTimer;

	// 적 생성할 때 사용할 글자 값
	static const char* enemyType[];
};
