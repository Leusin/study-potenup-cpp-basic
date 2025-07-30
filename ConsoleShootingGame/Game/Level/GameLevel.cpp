#include "GameLevel.h"

#include "Actor\Player.h"


GameLevel::GameLevel()
{
	AddActor(new Player()); // 플레이어 추가
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
