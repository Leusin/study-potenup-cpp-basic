#include "SocobanLevel.h"

#include"Math/Vector2.h"

SocobanLevel::SocobanLevel()
{
	ReadMapFile("Map.txt");
}

SocobanLevel::~SocobanLevel()
{
}

void SocobanLevel::ReadMapFile(const char* filename)
{
	// 최종 에셋 경로 
	char filePath[256] = { };
	sprintf_s(filePath, 256, "../Assets/%s", filename);

	// 파일 열기
	FILE* file = nullptr;
	fopen_s(&file, filePath, "rb");

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

	if (fileSize == readSize)
	{
		printf("fileSize = readSize\n");
	}

	int index = 0; // 배열 순회를 위한 인덱스
	int size = (int)readSize; // 문자열 길이 값
	Vector2 position; // 좌표

	// answk qoduf tnsghl
	while (index < size)
	{
		char mapCharacter = buffer[index++]; // 맵 문자 확인;

		// 개행 문자 처리
		if(mapCharacter == '\n')
		{
			++position.x;
			position.x = 0;

			//@TODO: 테스트용 
			printf("\n");

			continue;
		}
		
		switch (mapCharacter) // 각 문자 별 처리
		{
		case '#': printf("#"); break;
		case '.': printf("."); break;
		case 'p': printf("p"); break;
		case 'b': printf("b"); break;
		case 't': printf("t"); break;
		default:
			break;
		}
	}

	delete[] buffer;

	// 파일 닫기
	fclose(file);
}
