#include "SocobanLevel.h"

#include <iostream>
#include "Math/Vector2.h"
#include "Utils/Utils.h"
#include "Actor/Player.h"
#include "Actor/Wall.h"
#include "Actor/Box.h"
#include "Actor/Ground.h"
#include "Actor/Target.h"


SocobanLevel::SocobanLevel()
{
	ReadMapFile("Map.txt");
	//ReadMapFile("Stage1.txt");
}

SocobanLevel::~SocobanLevel()
{
}

bool SocobanLevel::CheckPlayerMove(const Vector2& playerPos, const Vector2& newPos)
{
	if (isGameClear)
	{
		return false;
	}

	// 박스 처리.
	std::vector<Box*> boxActors;
	for (Actor* const actor : actors)
	{
		Box* box = actor->As<Box>();
		if (box)
		{
			boxActors.emplace_back(box);
		}
	}

	// 이동하려는 위치에 박스가 있는지 확인.
	Box* searchedBox = nullptr;
	for (Box* const boxActor : boxActors)
	{
		// 플레이어가 이동하려는 위치와 박스의 위치가 같은지 비교.
		if (boxActor->Position() == newPos)
		{
			// 같은 위치에 있는 박스 저장 후 루프 종료.
			searchedBox = boxActor;
			break;
		}
	}

	// 이동하려는 위치에 박스가 있는 경우 처리.
	if (searchedBox)
	{
		// #1: 박스를 이동시키려는 위치에 다른 박스가 또 있는지 확인.
		Vector2 direction = newPos - playerPos;
		Vector2 nextPos = searchedBox->Position() + direction;

		for (Box* const otherBox : boxActors)
		{
			if (otherBox == searchedBox)
			{
				continue;
			}

			if (otherBox->Position() == nextPos)
			{
				return false;
			}
		}

		for (Actor* const actor : actors)
		{
			if (actor->Position() == nextPos)
			{
				// #2: 박스는 없지만, 벽이 있지 않은지 확인.
				if (actor->As<Wall>())
				{
					return false;
				}

				// #3: 이동 가능한 경우(땅, 타겟) 박스 이동 처리.
				if (actor->As<Ground>() || actor->As<Target>())
				{
					searchedBox->SetPosition(nextPos);

					isGameClear = CheckGameClear();
					return true;
				}
			}
		}
	}

	// 플레이어가 이동하려는 위치에 박스가 없는 경우.
	for (Actor* const actor : actors)
	{
		if (actor->Position() == newPos)
		{
			// 벽이면 이동 불가
			if (actor->As<Wall>())
			{
				return false;
			}

			// 땅 or 타겟
			return true;
		}
	}

	// ???
	return false;
}

void SocobanLevel::Render()
{
	super::Render();

	if (isGameClear)
	{
		Utils::SetConsolePosition({ 30, 0 });
		Utils::SetConsoleTextColor((WORD)Color::White);
		std::cout << "Game Clear!";
	}
}

void SocobanLevel::ReadMapFile(const char* filename)
{
	// 최종 에셋 경로 
	char filePath[256] = { };
	sprintf_s(filePath, 256, "../Assets/%s", filename);

	// 파일 열기
	FILE* file = nullptr;
	fopen_s(&file, filePath, "rt"); // 열기 모드 t 접두사를 쓰면 \n\r -> \n

	// 예외 처리
	if (file == nullptr)
	{
		printf("맵 파일 읽기 실패: %s.\n", filePath);
		__debugbreak();

		return;
	}

	// 파싱
	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);

	// 확인할 파일 크기 활용해 버퍼 할당
	char* buffer = new char[fileSize + 1];
	//b[fsize] = '\0';
	memset(buffer, 9, fileSize + 1);
	size_t readSize = fread(buffer, sizeof(char), fileSize, file);

	/*if (fileSize != readSize)
	{
		printf("fileSize != readSize\n");
	}*/

	int index = 0; // 배열 순회를 위한 인덱스
	int size = (int)readSize; // 문자열 길이 값
	Vector2 position; // 좌표

	// answk qoduf tnsghl
	while (index < size)
	{
		char mapCharacter = buffer[index++]; // 맵 문자 확인;

		// 개행 문자 처리
		if (mapCharacter == '\n')
		{
			++position.y;
			position.x = 0;

			//@TODO: 테스트용 
			printf("\n");

			continue;
		}

		switch (mapCharacter) // 각 문자 별 처리
		{
		case '#':
		case '1':
		{
			AddActor(new Wall(position));
		}
		break;
		case '.':
		{
			AddActor(new Ground(position));
		}
		break;
		case 'p':
		{
			AddActor(new Ground(position));
			AddActor(new Player(position));
		}
		break;
		case 'b':
		{
			AddActor(new Ground(position));
			AddActor(new Box(position));
		}
		break;
		case 't':
		{
			AddActor(new Target(position));
			++targetScore; // 목표 점수 == t 개수
		}
		break;
		default:
			break;
		}

		// 좌표 증가
		++position.x;
	}

	delete[] buffer;

	// 파일 닫기
	fclose(file);
}

bool SocobanLevel::CheckGameClear()
{
	// 박스가 타깃 위치에 모두 옮겨졌는지 확인.
	int currentScore = 0;

	// 검사할 액터 벡터에 저장
	std::vector<Actor*> targetActors;
	std::vector<Actor*> boxActors;
	for (Actor* const actor : actors)
	{
		if (actor->As<Target>())
		{
			targetActors.emplace_back(actor);
			continue;
		}

		if (actor->As<Box>())
		{
			boxActors.emplace_back(actor);
		}
	}

	// 박스와 타겟 엑터 위치 비교
	for (Actor* const targetActor : targetActors)
	{
		for (Actor* const boxActor : boxActors)
		{
			// 두 액터의 위치가 같으면 점수 증가 처리.
			if (targetActor->Position() == boxActor->Position())
			{
				++currentScore; // 점수 증가
			}
		}
	}

	isGameClear = targetScore == currentScore;
	return isGameClear;
}
