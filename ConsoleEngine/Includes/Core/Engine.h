#pragma once

#include<Windows.h>
#include "Core.h"

/** 
 * ToDo: 2025/07/24
 * [] RTTI 적용.
 * [] Engine 싱글톤 구현. 
 * 
 */

class Level;

class Engine_API Engine
{
	/// <summary>
	/// 키입력 확인을 위한
	/// </summary>
	struct KeyState
	{
		bool isKeyDown = false; // 현재 프레임에 키가 눌렸는지
		bool previouseKeyDown = false; // 이전 프레임에 키가 눌렸는지 여부
	};

public:
	Engine();
	~Engine();

	void Run();
	void Quit();

	// 키 처리
	bool GetKey(int KeyCode);
	bool GetKeyDown(int KeyCode);
	bool GetKeyUp(int KeyCode);

	void AddLevel(Level* newLevel);

private:
	void ProcessInput();
	void BeginPlaye();
	void Tick(float deltaTime = 0.0f);
	void Render();

private:
	
	bool isQuit = false;
	KeyState keyStates[255] = { };
	Level* mainLevel = nullptr;
};
