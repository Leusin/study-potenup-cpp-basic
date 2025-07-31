#include "GameLevel.h"

#include <iostream>
#include "Engine.h"
#include "Utils/Utils.h"
#include "Actor/Enemy.h"
#include "Actor/Player.h"
#include "Actor/EnemyBullet.h"
#include "Actor/PlayerBullet.h"

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

	if (enemySpawnTimer.IsTimeout()) // 타이머 확인
	{
		SpwnEnemy(); // 적 생성 로직

		// 타이머 정리
		enemySpawnTimer.Reset();
		enemySpawnTimer.SetTargetTime(Utils::RandomFloat(2.0f, 3.0f));
	}

	// 충돌 처리
	ProcessCollisionPlayerBulletAndEnemy();
	ProcessCollisionPlayerAndEnemyBullet();
}

void GameLevel::Render()
{
	super::Render();

	if (isPlayerDead)
	{
		Utils::SetConsolePosition(Vector2(playerDeadPosition.x, playerDeadPosition.y - 1));
		std::cout << "   .   ";

		Utils::SetConsolePosition(Vector2(playerDeadPosition.x, playerDeadPosition.y));
		std::cout << " .  .  .";

		Utils::SetConsolePosition(Vector2(playerDeadPosition.x, playerDeadPosition.y + 1));
		std::cout << "..:V:..";

		Utils::SetConsolePosition(Vector2(playerDeadPosition.x, playerDeadPosition.y + 2));
		std::cout << "Game Over!";

		Sleep(3000);
		Engine::Get().Quit();
	}

	char buffer[20] = {};
	sprintf_s(buffer, 20, "Score: %d", score);
	
	// 출력.
	Utils::SetConsolePosition(Vector2(1, Engine::Get().Height() + 2));
	Utils::SetConsoleTextColor(Color::White);
	std::cout << buffer;

}

void GameLevel::SpwnEnemy()
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

void GameLevel::ProcessCollisionPlayerBulletAndEnemy()
{
	std::vector<PlayerBullet*> bullets; // 플레이어 탄약 액터 배열
	std::vector<Enemy*> enemies; // 적 액터 배열

	for (Actor* const actor : actors)
	{
		PlayerBullet* bullet = actor->As<PlayerBullet>();
		if (bullet)
		{
			bullets.emplace_back(bullet);
			continue;
		}

		Enemy* enemy = actor->As<Enemy>();
		if (enemy)
		{
			enemies.emplace_back(enemy);
			continue;
		}
	}

	// 예외처리
	if (bullets.size() == 0 || enemies.size() == 0)
	{
		return;
	}

	for (auto* bullet : bullets)
	{
		for (auto* enemy : enemies)
		{
			if (bullet->TestIntersect(enemy))
			{
				bullet->Destroy();
				enemy->Destroy();

				score++;// 점수 증가처리

				continue;;
			}
		}
	}
}

void GameLevel::ProcessCollisionPlayerAndEnemyBullet()
{
	Player* player = nullptr;
	std::vector<EnemyBullet*> bullets;

	for (Actor* const actor : actors)
	{
		EnemyBullet* bullet = actor->As<EnemyBullet>();
		if (bullet)
		{
			bullets.emplace_back(bullet);
			continue;
		}

		if (!player) // 플레이어 확인
		{
			player = actor->As<Player>();
		}
	}

	if (bullets.size() == 0 || !player)
	{
		return;
	}
	
	for (auto* bullet : bullets)
	{
		if (player->TestIntersect(bullet))
		{
			isPlayerDead = true;

			playerDeadPosition = player->Position();

			player->Destroy();
		}
	}
}
