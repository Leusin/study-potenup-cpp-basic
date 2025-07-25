#include "Actor.h"

#include <Windows.h>
#include <iostream>

Actor::Actor(const char image, Color color)
	: image(image), color(color)
{
}

Actor::~Actor()
{
}


void Actor::BeginPlay()
{
	hasBegonPlay = true;
}

void Actor::Tick(float deltaTime)
{
}

void Actor::Render()
{
	// Win32 API.
	// 커서위치 이동.
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 출력 제어 핸들 얻어오기

	COORD coord; // 커서 위치값 생성
	coord.X = (short)position.x;
	coord.Y = (short)position.y;

	SetConsoleCursorPosition(handle, coord); // 커서 이동.

	SetConsoleTextAttribute(handle, (WORD)color);

	printf("%c", image); // 그리기
}

void Actor::SetPosition(const Vector2& newPosition)
{
	// TODO: 야매로 지나간 흔적 지우기
	{
		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 출력 제어 핸들 얻어오기

		COORD coord; // 커서 위치값 생성
		coord.X = (short)position.x;
		coord.Y = (short)position.y;

		SetConsoleCursorPosition(handle, coord); // 커서 이동.

		printf(" "); // 지우기
	}

	position = newPosition;
}

Vector2 Actor::Position() const
{
	return position;
}
