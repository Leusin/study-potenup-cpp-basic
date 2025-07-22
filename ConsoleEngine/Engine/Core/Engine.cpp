#include "Engine.h"
#include <iostream>

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
	//float currentTime = timeGetTime();
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter(&currentTime);
	LARGE_INTEGER previousTime = currentTime;

	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	float targetFrameRate = 60.f;

	float oneFrameTime = 1.f / targetFrameRate;

	while (true)
	{
		if (isQuit)
		{
			return;
		}

		QueryPerformanceCounter(&currentTime);
		float deltaTime = (currentTime.QuadPart - previousTime.QuadPart) / (float)frequency.QuadPart;

		ProcessInput();

		if (deltaTime >= oneFrameTime)
		{
			Update(deltaTime);
			Render();

			previousTime = currentTime;
		}

	}
}

void Engine::Quit()
{
	isQuit = true;
}

void Engine::ProcessInput()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x80000)
	{
		Quit(); 
	}
}


void Engine::Update(float deltaTime)
{
	std::cout << "DELTA TIME : " << deltaTime << ", ";
	// 순간치 계산
	std::cout << " FPS : " << 1.0f / deltaTime  << "\n";
}

void Engine::Render()
{
}
