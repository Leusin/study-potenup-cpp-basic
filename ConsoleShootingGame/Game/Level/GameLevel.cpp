#include "GameLevel.h"

#include "Actor/Player.h"
#include "Actor/Enemy.h"


GameLevel::GameLevel()
{
	AddActor(new Player()); // 플레이어 추가
	
	AddActor(new Enemy());
}

GameLevel::~GameLevel()
{
}

void GameLevel::BeginPlay()
{
	super::BeginPlay();
}

void GameLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);
}

void GameLevel::Render()
{
	super::Render();
}
