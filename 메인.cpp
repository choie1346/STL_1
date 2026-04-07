//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.10(화)
//----------------------------------------------
// STL 컨테이너 - std::String과 유사한 ZString을 만들어서 컨테이너의 본질에 접근
//----------------------------------------------
#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <print>
#include <array>
#include <ranges>
#include <fstream>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid(0, 999'999);
uniform_int_distribution uidNameLen(1, 16);
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
    string name;    // [1, 16]
    int id;         // [0, 999'999]

    friend ostream& operator<<(ostream& os, const Dog& dog) {
        print(os, "[{:7}] - {}", dog.id, dog.name);
        return os;
	}
};


// [문제] 다운받은 "Dog 십만마리"에는 class Dog 객체 십만개가 저장되어 있다.
// 바이너리 모드로 저장하여 정확하게 4MB이다.
// 메모리로 모두 읽어와라.
// 앞에서 100개 출력하여 확인하라.

array<Dog, 10'0000> dogs;

//--------
int main()
//--------
{
    //ofstream out{ "Dog 십만마리", ios::binary };
    //out.write((char*)dogs.data(), dogs.size() * sizeof(Dog));

    ifstream in{ "Dog 십만마리", ios::binary };
    if (not in) return 4444;

    in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

    for (int i = 0; i < 100; ++i)
        cout << dogs[i] << endl;

    //for (const Dog& dog : dogs)
    //    cout << dog << endl;
    // save("메인.cpp");
}