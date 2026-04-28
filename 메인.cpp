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
    vector<int> v{ 1,2,3,4,5 };

    // [문제] v에서 3을 제거하라.
    // v.size == 4, v.capacity == 5
    // v.erase(remove(v.begin(), v.end(), 3), v.end());
    erase(v, 3);

    for (int num : v)
        cout << num << endl;

     save("메인.cpp");
}