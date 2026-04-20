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

    array<int, 5> a{ 1, 2, 3, 4, 5};
    
    
    // element access - at, operator[], front, back, data
    
    // at() - 경계를 검사하고 싶으면 이 함수를 사용하면 된다.
    // C++은 속도를 최우선으로 하는 언어이다.
    // 시간 걸리는 at()을 다른 함수로 제공하는 이유이다.
    // at()은 예외를 던진다.
    while (true) {
        cout << "찾을 원소는? : ";
        int num;
        cin >> num;
        
        try {
            cout << a.at(num) << endl;
        }
        catch (exception& e) {
            cout << e.what() << endl;       // 표준예외를 출력한다.
        }
    }
    
    save("메인.cpp");
}