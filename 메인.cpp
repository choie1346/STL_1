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
    
    // iterator로 a를 순회
    // array<ZString, 5>::iterator i = a.begin();
    auto i = a.begin(); // 위 코드와 같은 코드


    for (auto i = a.begin(); i != a.end(); ++i)
        cout << (*i) << endl;
    
    
    // element access - at, operator[], front, back, data
    관찰 = true;
    // 4개 다 동일한 결과가 출력됨. - 첫원소에 access
    a.begin()->show();
    a[0].show();
    a.front().show();   // a의 첫원소
    a.data()->show();   // a의 시작주소의 값을 show

    // 마지막 원소에 access
    (a.end() - 1)->show();
    a[a.size()-1].show();
    a.back().show();
    (a.data() + a.size() - 1)->show();
    관찰 = false;
    
    save("메인.cpp");
}