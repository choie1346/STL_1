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
#include <string>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    vector<ZString> v;
    
    // [문제] "메인.cpp"에 있는 모든 문자를 v에 저장하라.
    // vector로 파일 읽어오기 시험문제!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ifstream in{ "메인.cpp" };
    if (not in) return 0;
    
    ZString zs;
    while (in >> zs)
        v.push_back(zs);

    sort(v.begin(), v.end(), [](const ZString& a, const ZString& b) {
            return a.size() < b.size();
        });

    for (const ZString& zs : v)
        cout << zs << endl;

    save("메인.cpp");
}