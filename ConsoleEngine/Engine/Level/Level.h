#pragma once

#include <vector>
#include "Core.h"

class Actor;

/// <summary>
/// - 액터들을 관리한다.
/// </summary>
class Engine_API Level
{
public:
	Level();
	virtual ~Level();

	void AddActor(Actor* newActor);

	virtual void BeginPlay();
	virtual void Thick(float deltaTime);
	virtual void Render();

private:
	std::vector<Actor*> actors; // 레벨에 배치된 모든 액터 관리
};
