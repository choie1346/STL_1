//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.30(월)
//----------------------------------------------
// collable types -> 실습 -> STL
// 호출가능 타입 - collable types
// 1. 함수
//  - 함수 포인터도 호출 가능하다
// 2. lambda
//----------------------------------------------
#include <iostream>
#include "save.h"
using namespace std;

void f()
{
    cout << "난 호출 가능해요" << endl;
}

//--------
int main()
//--------
{
    void (*a)() = f;    // a는 함수 f를 가리키는 포인터

    a();

    // a는 STACK, f는 CODE segment에 존재함.
    // 

    // save("메인.cpp");
}