//----------------------------------------------
// 2026 1학기 STL 월56 화 78
// 중간고사 4월 21일(화)
//----------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - Dynamic (size) Array - free-store에 data관리
//----------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    vector<ZString> v{ "1", "22", "333" };
    v.reserve(5);  // 10개의 공간을 마련

    cout << "원소 추가" << endl;
    관찰 = true;
    v.emplace_back("4444");        // Creator(생성자)가 아님.
    v.emplace_back( );      // 디폴트 생성자
    // emplace_back - 남은 메모리에 직접 색칠 (임시 객체를 생성하지 않음)
    // 생성자 - 만들어진 메모리에 색칠하는 놈?
    관찰 = false;


    cout << endl;
    cout << "v의 원소에 접근" << endl;


    for (ZString& zs : v)
        cout << zs << endl;

    save("메인.cpp");
}