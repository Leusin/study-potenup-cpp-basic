#include "Engine.h"

#include <iostream>
#include "Level/level.h"

Engine::Engine()
{
}

Engine::~Engine()
{
	if (mainLevel)
	{
		delete mainLevel;
		mainLevel = nullptr;
	}
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

		if (deltaTime >= oneFrameTime) // 고정 프레임
		{
			// ========== EVENT ==========
			BeginPlaye();
			Tick(deltaTime);
			Render(); 

			previousTime = currentTime;

			for (int keyCode = 0; keyCode < 255; ++keyCode)
			{
				keyStates[keyCode].previouseKeyDown = GetAsyncKeyState(keyCode) & 0x80000;
			}
		}

	}
}

void Engine::Quit()
{
	isQuit = true;
}

bool Engine::GetKey(int KeyCode)
{
	return keyStates[KeyCode].isKeyDown;
}

bool Engine::GetKeyDown(int KeyCode)
{
	return !keyStates[KeyCode].previouseKeyDown && keyStates[KeyCode].isKeyDown;
}

bool Engine::GetKeyUp(int KeyCode)
{
	return keyStates[KeyCode].previouseKeyDown && !keyStates[KeyCode].isKeyDown;
}

void Engine::AddLevel(Level* newLevel)
{
	if (mainLevel)
	{
		delete mainLevel;
	}

	mainLevel = newLevel;
}

void Engine::ProcessInput()
{
	// 키입력 확인
	for (int keyCode = 0; keyCode < 255; ++keyCode)
	{
		keyStates[keyCode].isKeyDown = GetAsyncKeyState(keyCode) & 0x80000;
	}

	//if (GetAsyncKeyState(VK_ESCAPE) & 0x80000) // ESC 로 종료 처리
	//{
	//	Quit(); 
	//}
}

void Engine::BeginPlaye()
{
	// LEVEL
	if (mainLevel)
	{
		mainLevel->BeginPlay();
	}
}

void Engine::Tick(float deltaTime)
{
	//std::cout << "DELTA TIME : " << deltaTime << ", ";
	//std::cout << " FPS : " << 1.0f / deltaTime << "\n"; // 순간치 계산

	//if (GetKey('A'))
	//{
	//	std::cout << "GetKey" << "\n";
	//}
	//if (GetKeyUp('A'))
	//{
	//	std::cout << "GetKeyUp" << "\n";
	//}
	//if (GetKeyDown('A'))
	//{
	//	std::cout << "GetKeyDown" << "\n";
	//}

	// LEVEL
	if (mainLevel)
	{
		mainLevel->Thick(deltaTime);
	}

	if (GetKeyDown(VK_ESCAPE))
	{
		Quit();
	}
}

void Engine::Render()
{
	// LEVEL
	if (mainLevel)
	{
		mainLevel->Render();
	}
}
