//----------------------------------------------
// 2026 1학기 STL 월56 화 78
//----------------------------------------------
// STL 컨테이너 - std::string과 유사한 ZString을 만들어서 컨테이너의 본질에 접근
//----------------------------------------------
#include <iostream>
#include <string>
#include <memory>
#include "save.h"
using namespace std;

class ZString {
public:
    ZString() {
        cout << "생성(default) 글자수: " << len << " 객체주소: " << this << " 글자주소: " << (void*)p.get() << endl;
    }
    ZString(const char* s) {
        len = strlen(s);
        p = make_unique<char[]>(len);   // len만큼 저장공간 확보
        memcpy(p.get(), s, len);    // p에 s를 len만큼 copy
        // p.get() -> p의 주소

        cout << "생성(char*) 글자수: " << len << " 객체주소: " << this << " 글자주소: " << (void*)p.get() << endl;
        // this -> stack에 저장
        // p.get() -> free-store에 저장
    }

    friend ostream& operator<<(ostream& os, const ZString& zs) {
        for (int i = 0; i < zs.len; ++i)
            os << *(zs.p.get() + i);    // zs.p.get() + i -> 글자가 들어있는 주소
        return os;
    }
    
private:
    size_t len{};
    unique_ptr<char[]> p{}; // 문자열을 저장하는 스마트 포인터 

};

//--------
int main()
//--------
{
    ZString{};  // free-store 주소는 0으로 나옴

    ZString s{ "2026" };
    cout << s << endl;

    

    // save("메인.cpp");
}