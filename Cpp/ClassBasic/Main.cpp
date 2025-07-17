#include <iostream>

#include "Player.h"

int main()
{
    Game::Person player;
    player.SetX(10);
    player.Move(10, 10);

    /// player.cpp 를 모르는데 어떻게 Move 함수를 쓸 수 있을까?
    // 링커가 해결해준다.

    return 0;
}