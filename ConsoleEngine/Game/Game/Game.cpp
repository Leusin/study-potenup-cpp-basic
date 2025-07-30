#include "Game.h"

#include "Core/Core.h"
#include "Level/Level.h"
#include "Level/SocobanLevel.h"
#include "Level/MenuLevel.h"

Game* Game::instance = nullptr;

Game::Game()
{
	instance = this;

	// 메인 레벨 추가
	AddLevel(new SocobanLevel()); 
	//AddLevel(new MenuLevel());

	// 메뉴 레벨 생성
	menuLevel = new MenuLevel();
}

Game::~Game()
{
	CleanUp();
}

void Game::ToggleMeneu()
{
	// 화면 정리
	system("cls"); // clear screen 명령어 실행

	showMenu = !showMenu; // 토글 처리

	if (showMenu)
	{
		// 게임 레벨 뒤로 밀기
		backgroundLevel = mainLevel;
		// 매뉴 레벨을 메인 레벨로
		mainLevel = menuLevel;
}
	else
	{
		mainLevel = backgroundLevel;
	}

}

Game& Game::Get()
{
	return *instance;
}

void Game::CleanUp()
{
	if (showMenu)
	{
		//게임 레벨 재거
		SafeDelete(backgroundLevel);
		mainLevel = nullptr;
	}
	else
	{
		backgroundLevel = nullptr;
	}

	SafeDelete(menuLevel);

	Engine::CleanUp();
}
