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
// - deque<T> - vector와 list의 장점을 갖는 컨테이너
// - forward_list<T> - 니가 아무리 잘 코딩해도 나보다 효율적인 코드 못 만든다.
//                  lt is intended that forward_list have zero space or
//                  time overhead relative to a hand-written C-style singly
//                  linked list
//----------------------------------------------
#include <iostream>
#include <algorithm>
#include <ranges>
#include <span>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로

//--------
int main()
//--------
{
    ZString zs{ "The quick brown fox jumps over the lazy dog" };

    for (char c : zs)
        cout << c << endl;

    save("메인.cpp");
}