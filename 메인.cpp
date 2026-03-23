//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.10(화)
//----------------------------------------------
// C++에서 template의 역할은 무엇인가? - Generic Programming 구현하는 핵심키워드
// C++언어의 paradigm
// 
// 다음 주 - 많은 수의 자료를 다루기 - FILE I/O - binary I/O
//----------------------------------------------
#include <iostream>
#include <fstream>
#include <filesystem> 
#include <array>
#include "save.h"
using namespace std;

array<int, 1000'0000> arr;  // contiguous memory **STL 핵심단어** -> 공간상의 연속
                            // continuous -> 시간상의 연속

//--------
int main()
//--------
{
    // [문제] 파일 "int천만개"에는 int값 천만개가 저장되어 있다.
    // 파일은 binary 모드로 열었고 int값은 stream의 write 함수를 사용하여 저장하였다.
    // 저장된 int값을 모두 메모리에 저장하라.
    // 저장된 값 중에서 가장 작은 값과 큰 값을 화면에 출력하라.

    // cout << filesystem::file_size("int천만개") / sizeof(int);
    ifstream in{ "int천만개", ios::binary };

    if (not in) {
        cout << "파일을 열 수 없습니다." << endl;
        return 4444;
    }

    in.read((char*)(&arr[0]), arr.size() * sizeof(int));    

    cout << "큰 값 - " << *max_element(arr.begin(), arr.end()) << endl;
    cout << "작은 값 - " << *min_element(arr.begin(), arr.end()) << endl;


    // save("메인.cpp");
}