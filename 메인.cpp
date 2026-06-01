//-------------------------------------------------------------
// 2026년 1학기 STL 월56 화78          6월 1일        (12주 1일)
//--------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27
// 프로젝트 설정 - C++ 언어 표준 - /std:c++latest
//				   C/C++ 언어 - SDL 검사 - 아니요(/sdl-)
//--------------------------------------------------------------
// STL Associative Container
// - set/multiset - key-value, key == value
// - map/multimap - key-value, key값을 정렬기준으로 하여 O(LogN) value를 찾는다.
//--------------------------------------------------------------

#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include <vector>
#include "ZString.h"
#include "save.h"
using namespace std;

extern bool 관찰;


//----------
int main()
//----------
{
	// "이상한 나라의 앨리스.txt"의 단어를 set<ZString>에 저장하라.
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in) return 4444;

	multiset<ZString> s{ istream_iterator<ZString>{in}, {} };

	for (const ZString& zs : s)
		cout << zs << "  ";
	cout << endl;

	cout << "단어 개수 - " << s.size() << endl;

	save("메인.cpp");

	// [문제] 단어를 입력받아 있다면 몇 개인지
	// 없다면 없다고 출력하라.

	while (true) {
		cout << "찾을 단어?: ";
		ZString word;
		cin >> word;

		auto [하한, 상한] = s.equal_range(word);	// 하한과 상한을 pair로 리턴함.
		if (하한 == 상한) cout << "없는 단어입니다." << endl;
		else 
			cout << distance(하한, 상한) << "개 있습니다." << endl;
		
	}
}