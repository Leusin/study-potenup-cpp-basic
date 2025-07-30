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
	// TODO: 중복 여부 확인 예외처리 하면 좋음

	actors.emplace_back(newActor);

	// 오너 설정.
	newActor->owner = this;
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

void Level::Tick(float deltaTime)
{
	for (Actor* const actor : actors)
	{
		actor->Tick(deltaTime);
	}
}

void Level::Render()
{
	SortActorsBySortingOrder(); // 그리기 전에 정렬

	for (Actor* const actor : actors) // Render Pass
	{
		// 같은 위치에 더 높은 우선순위 액터가 있는지 확인
		Actor* searchActor = nullptr;
		for (Actor* const otherActor : actors)
		{
			if (actor == otherActor) // 
			{
				continue;
			}

			if (actor->position == otherActor->position)
			{
				if (actor->sortingOrder < otherActor->sortingOrder)
				{
					searchActor = otherActor;
					break;
				}
			}
		}

		if (searchActor) // 우선순서가 더 높은 액터가 없음
		{
			continue;
		}


		actor->Render(); // Draw Call
	}
}

void Level::SortActorsBySortingOrder()
{
	// TODO: 16개 이하는 삽입 정렬, 퀵정렬, 퀵정렬 떄 패널이 logN 넘으면 힙정렬

	// 거품 정렬
	for (int i = 0; i < (int)actors.size() - 1; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (actors[j]->sortingOrder > actors[j + 1]->sortingOrder)
			{
				std::swap(actors[j], actors[j + 1]);
			}
		}
	}
}
