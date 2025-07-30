#pragma once

#include "Math/Vector2.h"

/// <summary>
/// 플레이어가 이동 할 수 있는지 확인할 떄 사용할 인터페이스
/// </summary>
class ICanPlayerMove
{
public:
	virtual bool CheckPlayerMove(const Vector2& playerPos, const Vector2& newPos) abstract;

};
