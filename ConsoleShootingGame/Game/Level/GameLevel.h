#pragma once

#include "Level/Level.h"

#include "Utils/Timer.h"
#include "Math/Vector2.h"


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
	void SpwnEnemy();
	void ProcessCollisionPlayerBulletAndEnemy();
	void ProcessCollisionPlayerAndEnemyBullet();

private:
	Timer enemySpawnTimer;

	static const char* enemyType[];

	int score = 0;
	bool isPlayerDead = false;
	Vector2 playerDeadPosition;
};
