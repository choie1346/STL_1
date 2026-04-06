//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.10(화)
//----------------------------------------------
// C++에서 template의 역할은 무엇인가? - Generic Programming 구현하는 핵심키워드
// C++언어의 paradigm
// 
// 다음 주 - 많은 수의 자료를 다루기
//----------------------------------------------
#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include "save.h"
using namespace std;

bool 정렬기준(int a, int b)
{
    cout << "함수 ";      // 10 * (3~4) = 30~40회 호출됨
    return a < b; // 오름차순
    // return a > b; // 내림차순
}

class Dog {
public:
    bool operator()(int a, int b) {
        cout << "도그 ";
        return a < b;
    }
};

//--------
int main()
//--------
{
    array<int, 10> a{ 8,4,2,0,1,9,7,5,6,3 };

    // 
    function<bool(int, int)> f;

    f = 정렬기준;
    f = [](int a, int b) {
        cout << "람다 ";
        return a < b;
		};
    f = Dog{};

	sort(a.begin(), a.end(), f);

    //sort(a.begin(), a.end(), [](int a, int b) /*-> bool (리턴값)*/ {
    //   cout << "람다 ";
    //   return a < b;
    //   });

    //sort(a.begin(), a.end(), 정렬기준);
    //sort(a.begin(), a.end(), Dog{});

    for (int num : a)
        cout << num << ' ';

    save("메인.cpp");
}