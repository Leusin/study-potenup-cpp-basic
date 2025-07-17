#include "Player.h"

namespace Game
{
    void Person::Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }

}