#pragma once

/*
* TODO: 프로그램이 종료되어도 데이터가 유지되는 시스템
*	[] 프로그램을 시작할 때 저장된 파일이 있는지 확인하고, 있으면 파일의 내용을 불러와 초기화 한다.
*	[] 사용자가 입금/출금 등 데이터를 변경했을 때마다 기록
*	[] 프로그램 종료 시 전체 데이터를 한번에 기록
*/

class Bank
{
public:
	Bank();
	~Bank();

	void Run();

private:
	// 프로그램을 시작할 때 저장된 파일이 있는지 확인하고, 있으면 파일의 내용을 불러와 초기화 한다.
	void LoadDatas();

private:
	int count = 0;
	class Account* accounts[100];
};
