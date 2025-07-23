#pragma once

#include "Core.h"
#include "Math/Vector2.h"

/// <summary>
/// "물체가 뭘해야할까?" 를 정의한다
/// - 위치 점령
/// - 콘솔 창에 그리기(어떻케)
/// - 엔진의 이벤트 함수 호출: BeginPlay / Tick / Draw
/// </summary>
class Engine_API Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void BeginPlay(); // 단 한번만 호출. (초기화가 필요한 작업)
	virtual void Tick(float deltaTime); // 매 프레임 호출. (반복성 작업/지속성이 필요한 작업)
	virtual void Render(); // 그리기

	inline bool HasBegonPlay() const { return hasBegonPlay; }

private:
	Vector2 position; // 개체의 위치

	char imge = ' ';

	bool hasBegonPlay = false; // 호출이 되었는지 확인
};
