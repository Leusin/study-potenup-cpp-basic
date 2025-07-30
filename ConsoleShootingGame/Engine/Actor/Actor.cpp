#include "Actor.h"

#include <iostream>
#include "Engine.h"
#include "Utils/Utils.h"
#include "Level/Level.h"

Actor::Actor(const char* image, Color color, const Vector2& position)
	: color(color), position(position)
{
	// iamge 초기화
	width = (int)strlen(image); // 문자열 길이
	this->image = new char[width + 1]; // 문자열 메모리 할당
	strcpy_s(this->image, width + 1, image); // 문자열 복사
}

Actor::~Actor()
{
	SafeDeleteArray(image); // 문자열 메모리 해제
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
	//static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 출력 제어 핸들 얻어오기

	// 커서 이동.
	Utils::SetConsolePosition(position);

	// 색상 설정
	Utils::SetConsoleTextColor(color);

	printf("%s", image); // 그리기
}

void Actor::Destroy()
{
	isExpired = true;
}

void Actor::QuitGame()
{
	Engine::Get().Quit();
}

void Actor::SetPosition(const Vector2& newPosition)
{
	if (position == newPosition)
	{
		return;
	}

	Vector2 direction = newPosition - position; // 지울 위치 확인

	position.x = (direction.x >= 0) ? position.x : position.x + width - 1;
	
	Utils::SetConsolePosition(position); // 커서 이동.

	printf(" "); // 지우기

	position = newPosition;
}

Vector2 Actor::Position() const
{
	return position;
}

void Actor::SetSortingOrder(unsigned int sortingOrder)
{
	this->sortingOrder = sortingOrder;
}

Level* Actor::GetOwner() const
{
	return owner;
}

int Actor::Width() const
{
	return width;
}
