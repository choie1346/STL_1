//----------------------------------------------
// 2026 1학기 STL 월56 화 78
// 중간고사 4월 21일(화)
//----------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Containers - 자료구조
// object - 메모리를 차지하는 객체(instancing)
//----------------------------------------------
#include <iostream>
#include <fstream>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    // [문제] "메인.cpp"에 있는 모든 단어를 ZString 객체로 읽어와라.
    // 이 문제에서 단어란 공백으로 분리된 문자집합이다.
    // 다음 문장이 문제없이 실행되도록 하자.

    ifstream in{ "메인.cpp" };
    if (not in) {
        cout << "파일을 열 수 없습니다." << endl;
        return 4444;
    }

    ZString s;
    while (in >> s) {
        cout << s << endl;
    }
    

    // save("메인.cpp");
}