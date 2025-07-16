#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(195);

	// 배열 (Array)
	int example[5];

	int* ptr = example;
	example[2] = 10;

	// example[3] = 100;
	*(ptr + 3) = 100;

	// 크기 구하기
	int length = sizeof(example) / sizeof(example[0]);
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << example[ix] << "\n";
	}

	// 동적 할당
	int* arr = new int[5];
	for (int ix = 0; ix < 5; ++ix)
	{
		arr[ix] = 10;
	}

	//delete[] arr;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}