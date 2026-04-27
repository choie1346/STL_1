//----------------------------------------------
// 2026 1학기 STL 월56 화 78
// 중간고사 4월 21일(화)
//----------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - Dynamic (size) Array - free-store에 data관리
//----------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    vector<ZString> v{ "1", "22", "333" };
    v.reserve(10);  // 10개의 공간을 마련

    관찰 = true;
    v.push_back("4444");
    v.push_back("55555");
    v.push_back("666666");
    관찰 = false;


    cout << endl;
    cout << "v의 원소에 접근" << endl;


    for (ZString& zs : v)
        cout << zs << endl;

    save("메인.cpp");
}