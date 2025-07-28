#include <iostream>
#include <memory>

class Test
{
public:
	Test()
	{
		std::cout << "Test()\n";
	}

	~Test()
	{
		std::cout << "~Test()\n";
	}

};

int main()
{
	std::unique_ptr<Test> testUnique = std::make_unique<Test>();
	std::shared_ptr<Test> testShared = std::make_shared<Test>();

	std::unique_ptr<Test>& testUniqueRef = testUnique;
	std::unique_ptr<Test> testUnique2 = std::move(testUnique);
	
	std::shared_ptr<Test> testShared2 =testShared;
	std::weak_ptr<Test> testWeak = testShared;

	// unique_ptr
	/*
	* 대입과 복사는 불가능하다
	* 참조는 가능하다
	*/
	Test* rawptrTest = testUnique.get(); // 가능하지만 바람직하지 않다.
	//delete rawptrTest; // 큰일난다.
	Test& refTest = *testUnique; // 참조로 받자 
	std::unique_ptr<Test>& refUniqueTest = testUnique; // 혹을 이렇게 (하지만 장황해서 귀찮았었음)

	// shared
	/*
	* 강참조
	* 대입과 복사가 가능하다
	* 그렇기 때문에 순환 참조라는 문제가 발생하기도 하다.
	*/

	// weak
	/*
	* 약참조
	* reference count 를 올리지 않기 때문에 순환 참조문제를 일으키지 않는다.
	* lock 함수로 참조중인 포인터가 유효한지 검사할 수 있다. 
	*/
	std::shared_ptr<Test> shared = testWeak.lock();

	return 0;
}