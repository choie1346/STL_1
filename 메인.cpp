//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.10(화)
//----------------------------------------------
// C++에서 template의 역할은 무엇인가? - Generic Programming 구현하는 핵심키워드
// C++언어의 paradigm
// 
// 다음 주 - 많은 수의 자료를 다루기 - FILE I/O - binary I/O - class 객체
//----------------------------------------------
#include <iostream>
#include <random>
#include <print>
#include <string>
#include <array>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0,9999 };
uniform_int_distribution uidNameLen{ 10, 30 };
uniform_int_distribution<int> uidChar{ 'a', 'z' };

class Dog {
public:
    Dog() {
        id = uid(dre);
        int len = uidNameLen(dre);
        for (int i{}; i < len; ++i) {
            name += uidChar(dre);
        }
    }

private:
    string name;        // [10, 30] 사의의 소문자로 구성된 이름
    size_t id;          // [0, 9999]



    friend ostream& operator<<(ostream& os, const Dog& dog) {
        print(os, "[{:4}] - {}", dog.id, dog.name);
        return os;
    }
};

//--------
int main()
//--------
{
    array<Dog, 1000> dogs;
    for (Dog dog : dogs) {
        cout << dog << endl;
    }

    // text mode와 binary mode는 교차가 가능
    // (text mode로 쓰기 후 binary mode로 읽기가 가능)
    // save("메인.cpp");
}