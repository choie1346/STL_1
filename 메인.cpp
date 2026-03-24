//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.10(화)
//----------------------------------------------
// 
//----------------------------------------------
#include <iostream>
#include <print>
#include <string>
#include <array>
#include <fstream>
#include "save.h"
using namespace std;

class Dog {

private:
    string name;        // [10, 30] 사의의 소문자로 구성된 이름
    size_t id;          // [0, 9999]



    friend ostream& operator<<(ostream& os, const Dog& dog) {
        print(os, "[{:4}] - {}", dog.id, dog.name);
        return os;
    }

    friend istream& operator>>(istream& is, Dog& dog) {
        is.read((char*)&dog, sizeof(Dog));
        return is;
    }
};


// SSO(Small String Optimization) - 성능 최적화를 위해 짧은 문자열을 free-store가 아닌 stack에 저장하는 것


// [문제] 파일 "Dog천마리"에는 class Dog객체 1000개가 저장되어 있다.
// 파일은 binary mode이고 각 객체는 메모리 크기 그대로 stream의 write함수로 기록하였다.
// 모든 객체를 한번의 write함수를 사용하여 기록하였다.
// Dog의 멤버는 위의 코드와 같다.
// 메모리에 모두 읽어오시오.
// 메모리에 읽은 Dog를 화면에 모두 출력하라.

//--------
int main()
//--------
{
    ifstream in{ "Dog천마리", ios::binary };
    if (not in) {
        cout << "파일을 열 수 없습니다." << endl;
        return 4444;
    }

    array<Dog, 1000> dogs;

    in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

    for (const Dog& dog : dogs)
        cout << dog << endl;
    // 이렇게 하면 SSO때문에 복사가 제대로 안 됨.


    
    // text mode와 binary mode는 교차가 가능
    // (text mode로 쓰기 후 binary mode로 읽기가 가능)
    // save("메인.cpp");
}