//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.30(월)
//----------------------------------------------
// 스마트 포인터 -> 콜러블 타입 -> 실습 -> STL
//----------------------------------------------
#include <iostream>
#include <memory>
#include "save.h"
using namespace std;

// C++의 보증사항
// 프로그램이 정상 종료 시(return문, exit과는 다름) 
// STACK에 만들어진 지역 객체가 반드시 소멸됨을 보증한다. 
// stack-unwinding


class Dog {
public:
    Dog() { cout << "생성" << endl; }
    ~Dog() { cout << "소멸" << endl; }
};

class 스마트포인터 {
public:
    스마트포인터(Dog* p) : p{ p } {}
    ~스마트포인터() { delete p; }
private:
    Dog* p;
};


//--------
int main()
//--------
{
    // T* 는 raw-pointer이다. 앞으로 쓰지 말자.

    // unique_ptr<Dog> p{ new Dog };  // RAII
    스마트포인터 p{ new Dog };

    return 0;

    cout << "이 문장은 출력되지 않음" << endl;


    // save("메인.cpp");
}