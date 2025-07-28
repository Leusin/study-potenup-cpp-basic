#include "Level.h"

#include"Actor/Actor.h"

Level::Level()
{
}

Level::~Level()
{
	for (Actor* actor : actors)
	{
		SafeDelete(actor); // 다음 주석과 같다.
		/*if (actor)
		{
			delete actor;
			actor = nullptr;
		}*/
	}
}

void Level::AddActor(Actor* newActor)
{
	actors.emplace_back(newActor);
}

void Level::BeginPlay()
{
	for (Actor* const actor : actors)
	{
		if (actor->HasBegonPlay())
		{
			continue;
		}

		actor->BeginPlay();
	}
}

void Level::Thick(float deltaTime)
{
	for (Actor* const actor : actors)
	{
		actor->Tick(deltaTime);
	}
}

void Level::Render()
{
	for (Actor* const actor : actors)
	{
		actor->Render();
	}
}