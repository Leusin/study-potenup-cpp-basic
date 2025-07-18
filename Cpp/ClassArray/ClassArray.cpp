#pragma once

class NameCard
{
public:
	NameCard() {};
	NameCard(const char*, const char*, const char*, const char*);
	~NameCard();

	void ShowData();

private:
	char* CreateStr(const char*);

	char* name = nullptr;
	char* phone = nullptr;
	char* email = nullptr;
	char* job = nullptr;
};