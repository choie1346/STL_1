//----------------------------------------------
// 2026 1학기 STL 월56 화 78
// 중간고사 4월 21일(화)
//----------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - Dynamic (size) Array - free-store에 data관리
//             - 캐시 히트율이 높아 고속 데이터 처리에 유리
// - list<T> - 아무데서나 원소 추가/삭제 O(1)
//----------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>
#include <chrono>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로

//--------
int main()
//--------
{
    save("메인.cpp");

    // [문제] 파일에 있는 단어를 list<ZString>에 저장하라.
    // 단어를 사전식 오름차순으로 정렬하라.
    ifstream in{ "2026년 1학기 STL 월56 화78.txt" };
    if (not in)return 4444;

    list<ZString> words{ istream_iterator<ZString>{in}, {} };
    
    words.sort([](const ZString& a, const ZString& b) -> bool {
        return lexicographical_compare(a.data(), a.data() + a.size(), b.data(), b.data() + b.size());
        });
   
    // 정렬한 이후라면 중복 단어 제거
    // default operator== 로 판정
    words.unique();

    for (const ZString& zs : words)
        cout << zs << endl;

    cout << "중복을 제거하고 남은 단어의 수 - " << words.size();
    
    // [문제] 사용자가 입력한 단어가 리스트에 있는지 찾아본다.
    // 없으면 없다고 출력하라.
    // 있다면 리스트의 몇번째 단어인지 출력하라.

    

    // list 정렬 시간 - 1090us
    // list는 merge기반 sort
    
    // vector 정렬 시간 - 849us
    // vector는 quick sort
    // 이동 연산자가 없는 vector - 5105us
}