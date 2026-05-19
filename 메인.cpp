//-------------------------------------------------------------
// 2026년 1학기 STL 월56 화78          5월 18일        (11주 1일)
//--------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27
// 프로젝트 설정 - C++ 언어 표준 - /std:c++latest
//				   C/C++ 언어 - SDL 검사 - 아니요(/sdl-)
//--------------------------------------------------------------
// STL 반복자 - Iterators are a generalization of pointers that allow 
// a C++ program to work with different data structures in a uniform manner.
//--------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include <ranges>
#include "ZString.h"
#include "save.h"


using namespace std;

extern bool 관찰;

// 반복자란 무엇인가? 
// 이걸 사용하는 이유는?
// 반복자의 종류를 구분한 이유
// ZString이 표준 반복자를 제공하려면?

template<class 반복자>
void f(반복자 iter)
{
	cout << typeid(iterator_traits<반복자>::iterator_category).name() << endl;
}



//----------
int main()
//----------
{
	ZString zs{ "phinx of black quartz judge my vow" };

	sort(zs.begin(), zs.end());

	// [문제] zs를 거꾸로 출력하라.
	for (auto i = zs.rbegin(); i != zs.rend(); --i)
		cout << *(i - 1) << ' ';
	cout << endl;

	cout << endl;

	save("메인.cpp");
}