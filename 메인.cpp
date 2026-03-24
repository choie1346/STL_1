//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.10(화)
//----------------------------------------------
// 동적 메모리 할당(Dynamic memory allocation)
// Memory Allocation
// 정적(Static) - Program 할 때 사용할 메모리를 결정할 수 있는 경우    Compile-time
// 동적(Dynamic) - 실행한 이후에 결정되는 메모리(크기, 주소가 결정됨)   Run-time
// 동적은 실행 이후에 결정되기 때문에 이름을 지어줄 수 없음.
// 이름은 곧 주소다.
//----------------------------------------------
#include <iostream>
#include <numeric>
#include "save.h"
using namespace std;

// [문제] 사용자가 입력한 수만큼 int를 저장할 메모리를 확보하라.
// 1부터 시작하는 정수로 메모리를 채워라
// 합계를 화면에 출력하시오

//--------
int main()
//--------
{
    int* p;

    while (true) {
        size_t num;
        cout << "입력 - ";
        cin >> num;
        
        try {
            p = new int[num];
        }
        catch (std::exception& e) {
            cout << "메모리가 고갈 - " << e.what() << endl;
        }
        // 메모리 관리자에서 num만큼의 크기를 요청함.
        // 메모리를 다 쓰면 -> 페이징함.
        // 최근에 가장 안 쓴 메모리를 하드디스크에 저장하고 메모리를 줌.

        iota(p, p + num, 1);    // p위치부터 p+num위치까지 1부터 채우기

        //long long sum{};
        //for (int i{}; i < num; ++i) {
        //    p[i] = i + 1;
        //    sum += p[i];
        //}

        long long sum = accumulate(p, p + num, 0LL); // static_cast<long long>(0)
        // 시작위치, 마지막 위치, 시작할 값

        cout << sum << endl;

        delete[] p;
    }

    // free - C
    
    // save("메인.cpp");
}