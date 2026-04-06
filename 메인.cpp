//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.10(화)
//----------------------------------------------
// C++에서 template의 역할은 무엇인가? - Generic Programming 구현하는 핵심키워드
// C++언어의 paradigm
// 
// 다음 주 - 많은 수의 자료를 다루기
//----------------------------------------------
#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <print>
#include <array>
#include <ranges>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid(0, 999'999);
uniform_int_distribution uidNameLen(1, 150);
uniform_int_distribution<> uidChar('!', '~');   // printable characters


class Dog {
public:
    Dog() {
		id = uid(dre);

		int Len = uidNameLen(dre);
        for (int i = 0; i < Len; ++i)
            name += uidChar(dre);
    }

    int getID() {
        return id;
    }

    string getName() const {
        return name;
    }

    string& getName() {
        return name;
    }

private:
    string name;    // [1, 150]
    int id;         // [0, 999'999]

    friend ostream& operator<<(ostream& os, const Dog& dog) {
        print(os, "[{:7}] - {}", dog.id, dog.name);
        return os;
	}
};


// [문제] Dog객체 10만개를 메모리에 저장하라.
// name 기준 오름차순으로 sort를 사용하여 정렬하라.
// 필요하다면 Dog에 interface 멤버를 추가하라.
// 앞에서부터 1000개의 내용을 cout으로 출력하라.

array<Dog, 10'0000> dogs;

//--------
int main()
//--------
{
    for (Dog& dog : dogs) {
        string& name = dog.getName();
        sort(name.begin(), name.end());
    }

    for (auto dog : dogs | views::take(1000))
        cout << dog << endl;
    

    // save("메인.cpp");
}