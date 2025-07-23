#include "DemoLevel.h"

#include "TestActor.h"

DemoLevel::DemoLevel()
{
	AddActor(new TestActor());
}

void DemoLevel::BeginPlay()
{
	
}
