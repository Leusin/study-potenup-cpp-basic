#pragma once

#include "Engine.h"

class Game : public Engine
{
public:
	Game();
	~Game();

	// 메뉴 전환
	void ToggleMeneu(); 
	static Game& Get();

private:
	virtual void CleanUp() override;

private:
	class Level* menuLevel = nullptr; // 메뉴 레벨
	class Level* backgroundLevel = nullptr; // 화면에는 안 보이는 레벨

	bool showMenu = false;
	
	static Game* instance;
};
