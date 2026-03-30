//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.30(월)
//----------------------------------------------
// collable types -> 실습 -> STL
//----------------------------------------------
#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.h"
using namespace std;

// [문제] "메인.cpp"의 소문자를 모두 대문자로 바꾼 "메인대문자.cpp"를 만들어라.
// transform(메인.cpp, 메인대문자.cpp, 소문자를 대문자로);
// transform(뭐를, 뭘로, 어떻게);

//--------
int main()
//--------
{
    ifstream in{ "메인.cpp" };
    if (not in) return 1;

    ofstream out{ "메인대문자.cpp" };

    transform(istreambuf_iterator<char>{in}, {}, ostreambuf_iterator<char>{out},
        [](char c) {return c = toupper(c); });


    // save("메인.cpp");
}