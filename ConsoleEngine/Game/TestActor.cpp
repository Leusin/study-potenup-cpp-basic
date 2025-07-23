#include "TestActor.h"

void TestActor::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);
	std::cout << "TEST ACTOR TICK" << "\n";
}
