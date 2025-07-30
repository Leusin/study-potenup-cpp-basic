#include "MenuLevel.h"

#include <iostream>
#include "Game/Game.h"
#include "Core/Core.h"
#include "Utils/Utils.h"

MenuItem::MenuItem(const char* text, OnSelected onSelected)
	: onSelected(onSelected)
{
	size_t len = (int)strlen(text) + 1;
	menuText = new char[len];
	strcpy_s(menuText, len, text);
}

MenuItem::~MenuItem()
{
	SafeDeleteArray(menuText);
}

MenuLevel::MenuLevel()
{
	// 메뉴 아이템 추가
    items.emplace_back(new MenuItem("Resum Game", []() {Game::Get().ToggleMeneu(); }));
	items.emplace_back(new MenuItem("Quit Game", []() { Game::Get().Quit(); }));

	length = static_cast<int>(items.size()); // 아이템 수 미리 저장
}

MenuLevel::~MenuLevel()
{
	for (MenuItem* item : items)
	{
		SafeDelete(item);
	}

	items.clear();
}

void MenuLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);
    if (Input::Get().GetKeyDown(VK_UP))
    {
        currentIndex = (currentIndex - 1 + length) % length;
    }
    if (Input::Get().GetKeyDown(VK_DOWN))
    {
        currentIndex = (currentIndex + 1 + length) % length;
    }
    if (Input::Get().GetKeyDown(VK_RETURN))
    {
        items[currentIndex]->onSelected();
    }
    if (Input::Get().GetKeyDown(VK_ESCAPE))
    {
        Game::Get().ToggleMeneu();

        currentIndex = 0;
    }
}

void MenuLevel::Render()
{
    super::Render();

    // 색상 & 좌표 정리.
    Utils::SetConsolePosition({ 0, 0 });
    Utils::SetConsoleTextColor(static_cast<WORD>(unselectedColor));

    std::cout << "SokobanGame\n\n";

    // 메뉴 아이템 렌더링.
    for (int ix = 0; ix < length; ++ix)
    {
        Color textColor = (ix == currentIndex) ? selectedColor : unselectedColor; // 아이템 색상 확인.

        Utils::SetConsoleTextColor(static_cast<WORD>(textColor)); // 색상 설정.

        std::cout << items[ix]->menuText << "\n"; // 메뉴 텍스트 출력.
    }
}