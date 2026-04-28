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
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    vector<ZString> v{ "1", "22", "333"};

    // [문제] v에서 "22"를 제거하라
    관찰 = true;
    remove(v.begin(), v.end(), "22");
    관찰 = false;

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;

     save("메인.cpp");
}