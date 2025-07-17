#include <iostream>
#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

// 숙제
size_t GetString(const char* targetString)
{
	size_t ret = 0;
	while (*targetString != '\0')
	{
		targetString++;
		ret++;
	}
	return ret;
}

char ToUpperCase(char lowercase)
{
	char ret = lowercase;
	if ('A' <= ret && ret <= 'Z')
	{
		return ret;
	}
	else if('a' <= ret && ret <= 'z')
	{
		ret -= 'a' - 'A';
	}

	return ret;
}

char ToLowerCase(char lowercase)
{
	char ret = lowercase;
	if ('a' <= ret && ret <= 'z')
	{
		return ret;
	}
	else if ('A' <= ret && ret <= 'Z')
	{
		ret += 'a' - 'A';
	}

	return ret;
}

class Player
{
public:
	Player(const char* name) 
	{
		size_t len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name); // 값복사
	};

	~Player() 
	{
		if (name != nullptr)
		{
			delete[] name;
		}
	};

	void PrintName()
	{
		std::cout << "Name :" << name << "\n";
	}

private:
	char* name = nullptr;
};

int main()
{
	// char
	char test = 'a';


	/* const char* */
	auto str1 = "Rrrrrrrrrrrrrrrrrrrrrrrr"; // const char* 로 인식함
	std::cout << "Ron\0nieJ" << "\n";

	/* 크기 */
	std::cout << sizeof(str1) << "\n"; // 이러면 포인터 크기(1byt, 8bit) 나옴
	std::cout << strlen(str1) << "\n"; // 리턴 타입 size_t

	/* 숙제 */
	std::cout << GetString(str1) << "\n";
	std::cout << ToUpperCase('b') << "\n";
	std::cout << ToLowerCase('B') << "\n";

	/* char 배열 */
	char arr1[7] = { 'R', 'r', 'r', 'r', 'r', 'r', 'a' }; // Rrrrrra�������������������������Rrrrrr
	char arr2[7] = {'R', 'r', 'r', 'r', 'r', 'r', '\0'};
	std::cout << arr1 << "\n";
	std::cout << arr2 << "\n";

	/* const wchar_t* */ // 언리얼에서는 이게 기본값
	const auto* wc1 = L"Raaaaaaaaaaaaaaaaaaa";
	const auto* wc2 = TEXT("Waaaaaaaaaaaaa");  

	//
	// 클래스
	//
	{
		Player p = Player("MyName");
		p.PrintName();
	}
	 
	_CrtDumpMemoryLeaks();

	return 0;
}