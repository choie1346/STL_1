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
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    save("메인.cpp");

    // [문제] v에서 길이가 2인 ZString을 삭제하라.
    vector<ZString> v{ "1", "22", "333", "44", "4444", "33", "55", "55555" };

    // 조건식은 predicate을 사용하여 판단한다.
    //predicate - bool 값을 리턴하는 callable-type
    erase_if(v, [](const ZString& zs) {
        if (zs.size() == 2) return true;
        return false;
        });

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
}