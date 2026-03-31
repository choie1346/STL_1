//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.30(월)
//----------------------------------------------
// collable types -> 실습 -> STL
// 호출가능 타입 - collable types
// 1. 함수
//  - 함수 포인터도 호출 가능하다
// 2. lambda
// 3. () 연산자를 구현한 클래스 - 객체를 functor(함수객체)라 함.
// 4. 멤버함수와 멤버함수 포인터
// 
// --> functinon 클래스로 일관된 사용가능
//----------------------------------------------
#include <iostream>
#include "save.h"
using namespace std;



//--------
int main()
//--------
{
    class Sakura {
    public:
        void operator()() {
            cout << "안녕 난 람다야" << endl;
        };
    };
    // 람다의 타입
    // class `int __cdecl main(void)'::`2'::<lambda_1>

    Sakura a;
    a();

    cout << typeid(a).name() << endl;
    // class를 지역에 정의했을 때 a의 타입
    // class `int __cdecl main(void)'::`2'::Sakura


    // class를 전역에 정의했을 때 a의 타입
    // class Sakura

    // save("메인.cpp");
}