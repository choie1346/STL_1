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
#include <list>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    list<ZString> v{ "1", "22", "4444", "55555"};

    // [문제] "22"다음에 "333"을 추가하라
    관찰 = true;
    auto i = v.begin();
    advance(i, 2);
    v.emplace(i, "333");
    관찰 = false;

    for (const ZString& zs : v)
        cout << zs << endl;

     save("메인.cpp");
}