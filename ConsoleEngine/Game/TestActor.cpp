#include "TestActor.h"

#include <Windows.h>
#include "Engine.h"

TestActor::TestActor()
	: super('@', Color::Red)
{
}

void TestActor::Tick(float deltaTime)
{
	super::Tick(deltaTime); //Actor::Tick(deltaTime);


	if (Engine::Get().GetKey(VK_UP) && Position().y > 0)
	{
		Vector2 position = Position();
		position.y -= 1;
		SetPosition(position);
	}
	if (Engine::Get().GetKey(VK_RIGHT) && Position().x < 30)
	{
		Vector2 position = Position();
		position.x += 1;
		SetPosition(position);
	}
	if (Engine::Get().GetKey(VK_DOWN) && Position().y < 10)
	{
		Vector2 position = Position();
		position.y += 1;
		SetPosition(position);
	}
	if (Engine::Get().GetKey(VK_LEFT) && Position().x > 0)
	{
		Vector2 position = Position();
		position.x -= 1;
		SetPosition(position);
	}

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().Quit();
	}
}
