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

	return 0;
}