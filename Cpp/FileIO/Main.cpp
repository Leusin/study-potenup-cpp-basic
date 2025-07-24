#include <iostream>

int main()
{
	FILE* file = nullptr;
	//fopen_s(&file, "Test?.txt", "r");
	fopen_s(&file, "Test.txt", "r");

	if (file == nullptr)
	{
		std::cout << "Can't open the file.\n";
		std::cin.get();
		return 0;
	}

	char buffer[256];

	while (true)
	{
		if (fgets(buffer, 256, file) == nullptr)
		{
			break;
		}

		std::cout << buffer;
	}

	std::cin.get();

	return 0;
}