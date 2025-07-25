#include <iostream>

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//
// 함수 포인터
//

// typedef bool (*Compare)(int, int); // 보통 이걸 더 많이 쓰는듯?
using Compare = bool (*)(int, int); // 일반적으로 권장하는 방법

bool Greater(int a, int b) { return a > b; }
bool Less(int a, int b) { return a < b; }

//
// 함수 객체
//

class CompareGreater
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

class CompareLess
{
public:
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

// 버블 정렬 함수.
void BubbleSort(int array[], int length, Compare compare = Greater /*bool (*Compare)(int, int) = Greater*/)
{
    // 정렬.
    for (int ix = 0; ix < length; ++ix)
    {
        for (int jx = 0; jx < length - 1; ++jx)
        {
            // 두개씩 비교.
            // if (array[jx] > array[jx + 1])
            if (compare(array[jx], array[jx + 1]))
            {
                // 조건에 만족하면 두 값을 교환.
                Swap<int>(array[jx], array[jx + 1]);
            }
        }
    }
}

int main()
{
    int array[] = {1, 5, 2, 3, 4};
    int len = 5;

    BubbleSort(array, len);

    for (int i = 0; i < len; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    [](int a, int b)
    {
        std::cout << (a + b) << "\n";
    }
    (10, 20);

    auto function = [](int a, int b)
    {
        std::cout << (a + b) << "\n";
    };

    function(3, 4); // 출력: 7

    return 0;
}