#include "GameLevel.h"

#include "Utils/Utils.h"
#include "Actor/Player.h"
#include "Actor/Enemy.h"


// 적 생성할 때 사용할 글자 값.
const char* GameLevel::enemyType[] =
{
	";:^:;",
	"zZwZz",
	"oO@Oo",
	"<-=->",
	")qOp(",
};

GameLevel::GameLevel()
{
	AddActor(new Player()); // 플레이어 추가

	enemySpawnTimer.SetTargetTime(Utils::RandomFloat(2.0f, 3.0f));
}

GameLevel::~GameLevel()
{
}

void GameLevel::BeginPlay()
{
	super::BeginPlay();
}

void GameLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	enemySpawnTimer.Tick(deltaTime);

	if (!enemySpawnTimer.IsTimeout()) // 타이머 확인
	{
		return;
	}

	// 적 생성 로직
	{
		// 배열 길이 구하기
		static int enemyTypeCount = sizeof(enemyType) / sizeof(enemyType[0]);
		// 적 종류
		int index = Utils::Random(0, enemyTypeCount - 1);
		// y 위치 랜덤으로
		int yPosition = Utils::Random(1, 10);
		// 적생성 
		AddActor(new Enemy(enemyType[index], yPosition));
	}

	// 타이머 정리
	enemySpawnTimer.Reset();
	enemySpawnTimer.SetTargetTime(Utils::RandomFloat(2.0f, 3.0f));
}

void GameLevel::Render()
{
	super::Render();
}
