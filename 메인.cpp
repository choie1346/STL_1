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
#include <algorithm>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    // [문제] 키보드에서 입력한 모든 단어를 저장하라.
    // 입력의 끝은 OS마다 따로 지정되어 있다. (ctrl + z)
    // 오름차순 정렬하고 출력하라.

    vector<string> v;

    string s;
    while (cin >> s) {
        v.push_back(s);
    }
   
    // 오름차순(ascending order) 정렬
    sort(v.begin(), v.end());

    for (const string& s : v)
        cout << s << endl;

    save("메인.cpp");
}