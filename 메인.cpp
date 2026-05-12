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
//----------------------------------------------
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로

class Test {
    char c[1024 * 1024];
};

//--------
int main()
//--------
{
    save("메인.cpp");

    {
        vector<Test> v;

        size_t cnt{};
        while (true) {
            try {
                v.emplace_back();
            }
            catch (...) {       // ... -> 타원들(ellipses)
                cout << endl;
                cout << "벡터 - " << v.size() << endl;
                break;
            }
            if (not(++cnt % 1'000))
                cout << ".";
        }
    }

    {
        deque<Test> v;

        size_t cnt{};
        while (true) {
            try {
                v.emplace_back();
            }
            catch (...) {       // ... -> 타원들(ellipses)
                cout << endl;
                cout << "덱 - " << v.size() << endl;
                break;
            }
            if (not(++cnt % 1'000))
                cout << ".";
        }
    }

    {
        list<Test> v;

        size_t cnt{};
        while (true) {
            try {
                v.emplace_back();
            }
            catch (...) {       // ... -> 타원들(ellipses)
                cout << endl;
                cout << "리스트 - " << v.size() << endl;
                break;
            }
            if (not(++cnt % 1'000))
                cout << ".";
        }
    }
}