#pragma once

namespace Game
{
    class Person
    {
    public:
        Person()
            : x(0)
            , y(0)
            , speed(0)
        {
        }

        ~Person()
        {
        }

        // 접근함수
        int GetX() const
        {
            return x;
        }
        // 설정함수
        void SetX(int newX)
        {
            x = newX;
        }

        void Move(int, int);

    private:
        int x = 0;
        int y = 0;
        int speed = 0;
    };
}