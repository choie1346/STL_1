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
    // at
    while (true) {
        cout << "찾을 원소는? : ";
        int num;
        cin >> num;
        if (num < 0 || num >= a.size())
            cout << "다시 입력하시오." << endl;
        else {
            cout << num << "번 - " << a[num] << endl;
            // a[num] -> *(a.data() + sizeof(int) * num)과 같다.
        }
    }
    
    save("메인.cpp");
}