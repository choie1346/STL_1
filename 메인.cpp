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
    string zs{ "The quick brown fox jumps over the lazy dog" };

    // span - C 스타일 배열 등 연속된 메모리 공간을 가진 컨테이너의 요소들을 가볍게 참조(View)할 수 있는 안전한 래퍼(Wrapper) 클래스
    // 포인터와 크기를 하나로 묶어 관리하며, 디버그 모드에서 경계 검사(Bounds Checking)를 지원하여 안전
    // 데이터 복사 비용이 전혀 없는 오버헤드 제로(Zero-overhead) 구조
    sort(zs.data(), zs.data() + zs.size());

    span<char> s{ zs.data(), zs.size() };
 
    // [문제] 거꾸로 출력하세요.
    for (char c : s | views::reverse)
        cout << c << '-';
    cout << endl;

    save("메인.cpp");
}