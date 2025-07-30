#include "DemoLevel.h"

#include <iostream>
#include "TestActor.h"

DemoLevel::DemoLevel()
{
	AddActor(new TestActor());

	// 테스토로 맵 파일 읽기
	FILE* file = nullptr;
	fopen_s(&file, "../Assets/Map.txt", "rb");;

	// 예외 처리
	if (file == nullptr)
	{
		std::cout << "Failed to open Map.txt file.\n";
		__debugbreak();
		return;
	}

	// 파일 크기 확인
	fseek(file, 0, SEEK_END); // 파일 위치(File Position) 커서를 제일 끝으로 이동
	size_t fileSize = ftell(file); // 이동할 지점의 위치 반환
	fseek(file, 0, SEEK_SET); // rewind(file); 과 같다 // 파일 위치 커서 되돌리기

	// 데이터 저장을 위한 버퍼 할당
	//char* buff = new char[fileSize + 1]; 
	char buffer[256] = {};

	while (!feof(file))
	{
		fgets(buffer, 256, file); // 한 줄씩 읽기
		int lineLength = (int)strlen(buffer); // 한 줄 문자열 길이값 구하기

		// 파싱
		for (int i = 0; i < lineLength; ++i)
		{
			char mapChar = buffer[i];

			switch (mapChar)
			{
			case '#':
			{
				printf("#");
			}
			break;

			case '.':
			{
				printf("#");
			}
			break;

			case 'p':
			{
				printf("p");
			}
			break;

			case 'b':
			{
				printf("b");
			}
			break;

			case 't':
			{
				printf("t");
			}
			break;
			default:
			{

			}
			break;
			}
		}

		// 개행
		printf("\n");
	}

	fclose(file); // 파일 닫기
}

void DemoLevel::BeginPlay()
{

}
