#include <iostream>
#include "Player.h"
#include "NameCard.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	NameCard* name_cards[3];
	for (int i = 0; i < 3; i++)
	{
		std::cout << "-----" << i + 1 << " 번 입력 -----\n";

		char name[255] = "";
		std::cout << "이름 입력 ";
		std::cin >> name;

		char phone[255] = "";
		std::cout << "전번 입력 ";
		std::cin >> phone;

		char mail[255] = "";
		std::cout << "메일 입력 ";
		std::cin >> mail;

		char job[255] = "";
		std::cout << "직업 입력 ";
		std::cin >> job;

		name_cards[i]  = new NameCard(name, phone, mail, job);
	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << "-----" << i + 1 << " 번 출력 -----\n";
		name_cards[i]->ShowData();
		delete name_cards[i];
	}

	Player* players[5];

	/*
	for (int i = 0; i < 5; i++)
	{
		players[i].SetX(i * 2);
		players[i].SetY(i * 3);
	}

	for (const Player& player: players)
	{
		player.ShowPosition();
	}
	*/

	for (int i = 0; i < 5; i++)
	{
		players[i] = new Player(i * 2, i * 3);
	}

	SetPosition(*players[0], 10, 20);

	for (const Player* player : players)
	{
		// (*player).ShowPosition();
		player->ShowPosition();
	}

	

	for (int i = 0; i < 5; i++)
	{
		delete players[i];
		players[i] = nullptr;
	}

	/** 안하면 이렇게 됨
	etected memory leaks!
	Dumping objects ->
	{156} normal block at 0x000001CF7F7D44D0, 8 bytes long.
	 Data: <        > 08 00 00 00 0C 00 00 00
	{155} normal block at 0x000001CF7F7D42A0, 8 bytes long.
	 Data: <        > 06 00 00 00 09 00 00 00
	{154} normal block at 0x000001CF7F7D5060, 8 bytes long.
	 Data: <        > 04 00 00 00 06 00 00 00
	{153} normal block at 0x000001CF7F7D4480, 8 bytes long.
	 Data: <        > 02 00 00 00 03 00 00 00
	{152} normal block at 0x000001CF7F7D4250, 8 bytes long.
	 Data: <        > 00 00 00 00 00 00 00 00
	Object dump complete.
	*/

	Player* player2 = new Player[5];
	delete[] player2;
	// delete player2; // 이렇게 하면 안됨.
	/*
	* 중단점 명령(__debugbreak() 문 또는 유사한 호출)이 ClassArray.exe에서 실행되었습니다
	*/

	// 이렇게 쓸 일이 있을까
	Player** player3 = nullptr;
	player3 = new Player*();
	*player3 = new Player();
	delete* player3;
	delete player3;

	//std::cin.get();
}