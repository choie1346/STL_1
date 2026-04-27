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
#include <array>
#include <fstream>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    // [문제] "메인.cpp"에 알파벳 소문자가 몇 개나 있는지 다음과 같이 출력하라.
    // a - 10
    // b - 5
    // 중간 생략
    // z - 1

    // size_t alpha[26];
    array<int, 26> alpha{};

    ifstream in{ "메인.cpp" };
    if (not in) return 2;

    char c;
    while (in >> c) {
        if (islower(c))
            ++alpha[c - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        cout << static_cast<char>('a' + i) << " - " << alpha[i] << endl;
    }

     save("메인.cpp");
}