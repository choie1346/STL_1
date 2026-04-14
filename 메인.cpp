//----------------------------------------------
// 2026 1학기 STL 월56 화 78
// 중간고사 4월 21일(화)
//----------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Containers - 자료구조
// object - 메모리를 차지하는 객체(instancing)
//----------------------------------------------
#include <iostream>
#include <array>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{

    array<ZString, 5> a{ "1", "22", "333", "4444", "55555"};
    관찰 = true;
    a.fill("2026년 4월 14일");
    // 임시 객체를 하나 생성해 복사할당함.
    관찰 = false;

    for (const ZString& s : a)
        cout << s << endl;

    cout << "원소 수 - " << a.size() << endl;;
    cout << "비었니 - " << boolalpha << a.empty() << endl;
    cout << "최대 수 - " << a.max_size() << endl;

    


    // save("메인.cpp");
}