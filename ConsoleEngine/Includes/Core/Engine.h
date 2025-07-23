#pragma once

#include<Windows.h>
#include "Core.h"

/** 
 * ToDo: 2025/07/23
 * [x] 키입력 관리(KeyStat 배열)
 * [x] 입력 확인 함수 (GetKey, GetKeyDown, GetKeyUp)
 * [x] Entity 추가(Actor)
 * [x] 이벤트 함수 추가(BeginPlaye, Tick, Render)
 * [x] Level 추가(가상 공간에 배치된 물체(Actor) 관리 객체)
 * 
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
