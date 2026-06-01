//-------------------------------------------------------------
// 2026년 1학기 STL 월56 화78          6월 1일        (12주 1일)
//--------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27
// 프로젝트 설정 - C++ 언어 표준 - /std:c++latest
//				   C/C++ 언어 - SDL 검사 - 아니요(/sdl-)
//--------------------------------------------------------------
// STL Associative Container
// - set/multiset
// - map/multimap
//--------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include <ranges>
#include <vector>
#include "ZString.h"
#include "save.h"


using namespace std;

extern bool 관찰;

template<class 반복자, class 출력반복자>
void my_copy(반복자 b, 반복자 e, 출력반복자 o) {
    while (b not_eq e) {
        *o = *b;
        ++b;
        ++o;
    }
}

//----------
int main()
//----------
{
	ZString zs{ "sphinx of black quartz 3 judge my 6 vow" };

	my_copy(zs.begin(), zs.end(), ostream_iterator<char>{cout, " "});
}