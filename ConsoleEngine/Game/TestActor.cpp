#include "TestActor.h"

void TestActor::Tick(float deltaTime)
{
	super::Tick(deltaTime); //Actor::Tick(deltaTime);
	std::cout << "TEST ACTOR TICK" << "\n";
}
