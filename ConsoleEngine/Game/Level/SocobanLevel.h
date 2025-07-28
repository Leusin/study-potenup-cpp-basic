#pragma once

#include"Level/Level.h"

class SocobanLevel : public Level
{
	RTTI_DECLARATIONS(SocobanLevel, Level)

public:
	SocobanLevel();
	~SocobanLevel();

private:
	void ReadMapFile(const char* filename);
};
