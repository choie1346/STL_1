//----------------------------------------------------
// 한 학기 강의를 저장하는 함수
//----------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "save.h"

// fname 부터 -> naming convention 
void save(const std::string& fname)
{
    std::ifstream in{ fname };                // RAII 공부할것  -> in.close(); 코드 사용할 필요 X
    if (not in) {
        std::cout << fname << " - 열 수 없습니다" << '\n';
        exit(20260309);
    }

    std::cout << "\"" << fname << "\"" << "를 저장합니다." << '\n';

    std::ofstream out{ "2026년 1학기 STL 월56 화78.txt", std::ios::app };
    // if (not out) ->  쓸 필요 없음 -> out이 생성되지 않으면 바로 파일을 생성해줌


    // std::chrono::system_clock::time_point 
    auto now = std::chrono::system_clock::now();     // time_epoch로부터 1초마다 증가한 tick 수

    using namespace std::chrono_literals;   // 9h library

    out << '\n' << '\n';
    out << "==================================================" << '\n';
    out << "저장한 시간 - " << now + 9h << '\n';
    out << "==================================================" << '\n';
    out << '\n';


    // std::copy(어디에서, 어디까지를, 어디로);
    std::copy(std::istreambuf_iterator<char>{in}, {},
        std::ostream_iterator<char>{out});
	
}