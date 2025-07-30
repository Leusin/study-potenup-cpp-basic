#pragma once

#include "Level/Level.h"
#include "Interface/ICanPlayerMove.h"

class SocobanLevel : public Level, public ICanPlayerMove
{
	RTTI_DECLARATIONS(SocobanLevel, Level)

public:
	SocobanLevel();
	~SocobanLevel();
	
	virtual bool CheckPlayerMove(const Vector2& playerPos, const Vector2& newPos) override;
	virtual void Render() override;

private:
	void ReadMapFile(const char* filename); // 맵 파일(텍스트 파일) 읽어서 레벨 로드
	bool CheckGameClear(); // 게임 클리어 확인

private: 
	int targetScore = 0; // 게임 클리어 점수
	bool isGameClear = false; // 게임 클리어 여부 확인
};
