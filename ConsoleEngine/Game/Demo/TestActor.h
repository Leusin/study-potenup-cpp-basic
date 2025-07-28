#pragma once

#include<iostream>
#include "Actor/Actor.h"

class TestActor: public Actor
{
	RTTI_DECLARATIONS(TestActor, Actor)

public:
	TestActor();

	virtual void Tick(float deltaTime) override;
};

