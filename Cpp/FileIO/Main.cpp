#include <iostream>

int main()
{
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

		fclose(file);
	}
	{
		const char* message = "number=10 name=ronniej testnumber=3.14\n";

		FILE* file = nullptr;
		fopen_s(&file, "Test.txt", "wt");
		if (file != nullptr)
		{
			fputs(message, file);
			fclose(file);
		}

		// 파일의 임의 접근
		/*
		### fseek 함수

		- 첫 번째 파라미터는 대상 스트림이며, 두 번째 파라미터 offset은 FP를 어디로 옮길 지를 지정한다. 세 번째 파라미터 origin은 어느 위치를 기준으로 FP를 옮길 것인지를 지정한다.
		- origin에 사용할 수 있는 값은 3가지가 있다.
			1. SEEK_SET: 스트림 처음 위치 기준
			2. SEEK_CUR: 현재 위치 기준
			3. SEEK_END: 스트림의 끝 위치 기준 // 파일 전체 읽을 때 응용
		- SEEK_END일 경우 offset은 음수여야 하며, SEEK_CUR는 방향에 따라 양수, 음수 모두 가능하다.
		*/
		{
			FILE* file = nullptr;
			fopen_s(&file, "Test.txt", "rt");
			if (file != nullptr)
			{
				char buffer[256];

				fseek(file, 24, SEEK_SET); // 처음 위치 기준 24 바이트를 이동한 다음, 파일의 끝까지 읽어 출력
				while (!feof(file))
				{
					fgets(buffer, 256, file);
					std::cout << buffer;
				}


				// ftell 현재의 위치를 반환한다.
				// 다음 같은 경우 파일 크기를 알 수 있다?
				fseek(file, 0, SEEK_END);
				std::cout << "파일 크기: " << ftell(file) << "\n";

				// FP를 다시 처음으로 되돌릴 때 사용한다
				rewind(file);
				//  fseek(file, 0, SEEK_SET) 와 동일

				fclose(file);
			}
		}
	}


	//fprintf(newFile, "number=%d name=%s testnumber=%f", 10000, 1.2345f, "testname");

	//int number = 0;
	//char name[50] = {};
	//int testnumber = 0.f;
	//size_t result = fscanf_s(file, "number=%d name=%s testnumber=%f", &number, name, 50, &testnumber);
	


	//size_t writeSize = fwrite(buffer, 1, readSize, newFile);

	//while (true)
	//{
	//	if (feof(file)) // eof: end of file
	//	{
	//		break;
	//	}

	//	if (fgets(buffer, 256, file) == nullptr)
	//	{
	//		break;
	//	}

	//	std::cout << buffer;
	//}

	std::cin.get();

	return 0;
}