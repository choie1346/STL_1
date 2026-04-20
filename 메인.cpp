//----------------------------------------------
// 2026 1학기 STL 월56 화 78
// 중간고사 4월 21일(화)
//----------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - Dynamic (size) Array - free-store에 data관리
//----------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "ZString.h"
using namespace std;

extern bool 관찰;     //  관찰하려면 true로


//--------
int main()
//--------
{
    vector<int> v{ 1,2,3,4,5 }; // free-store

    cout << sizeof(v) << endl;          // 24byte
    cout << addressof(v) << endl;       // STACK
    cout << typeid(v).name() << endl;   // class std::vector<int,class std::allocator<int> >

    cout << "v가 저장할 수 있는 최대 int 개수 - " << v.max_size() << endl; // 4,611,686,018,427,387,903 줜나많이 담아짐.

    

    save("메인.cpp");
}