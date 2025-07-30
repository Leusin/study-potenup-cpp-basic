#include <iostream>
#include "Game/Game.h"
#include "Demo/DemoLevel.h"
#include "Level/SocobanLevel.h"
#include "Level/MenuLevel.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game socoban;
	//engine.AddLevel(new DemoLevel());
	//socoban.AddLevel(new SocobanLevel());
	//socoban.AddLevel(new MenuLevel());
	socoban.Run();

	return 0;
}