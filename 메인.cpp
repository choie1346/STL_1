//-------------------------------------------------------------
// 2026년 1학기 STL 월56 화78          6월 2일        (13주 1일)
// 6/22 시험(초 어려운 문제)
//--------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27
// 프로젝트 설정 - C++ 언어 표준 - /std:c++latest
//				   C/C++ 언어 - SDL 검사 - 아니요(/sdl-)
//--------------------------------------------------------------
// 컨테이너 찾기 성능 비교
// 1. 벡터
// 2. 멀티셋
// 3. 언오더드 멀티셋
// 
// 1000만개에서 10만개 찾기
//--------------------------------------------------------------
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <random>
#include <algorithm>
#include <chrono>
#include "ZString.h"
#include "save.h"

using namespace std;

extern bool 관찰;

const size_t NUM{ 10'000'000 };
const size_t FNUM{ 10'000 };

array<int, NUM> num;
array<int, FNUM> fnum;

default_random_engine dre;
uniform_int_distribution uid{ 1, 20'000'000 };

//----------
int main()
//----------
{
    save("메인.cpp");

    for (int& num : num)
        num = uid(dre);

    for (int& num : fnum)
        num = uid(dre);

    {   // 벡터에서 찾기
		vector<int> v{ num.begin(), num.end() };

        cout << "벡터에서 찾는 중";
        size_t cnt{};

        auto start = chrono::high_resolution_clock::now();
        for (int num : fnum) {
            if (find(v.begin(), v.end(), num) != v.end())
                ++cnt;
        }
        auto stop = chrono::high_resolution_clock::now();
        cout << endl;
        cout << FNUM << "중에서 " << cnt << "개 찾음" << endl;
        cout << "걸린 시간 - " << chrono::duration_cast<chrono::microseconds>(stop - start) << endl;

        // 10000중에서 3957개 찾음
        // 걸린 시간 - 16493986us
    }

    {   // 셋에서 찾기
        set<int> s{ num.begin(), num.end() };

        cout << "셋에서 찾는 중";
        size_t cnt{};

        auto start = chrono::high_resolution_clock::now();
        for (int num : fnum) {
            if (s.contains(num))
                ++cnt;
        }
        auto stop = chrono::high_resolution_clock::now();
        cout << endl;
        cout << FNUM << "중에서 " << cnt << "개 찾음" << endl;
        cout << "걸린 시간 - " << chrono::duration_cast<chrono::microseconds>(stop - start) << endl;

        // 10000중에서 3957개 찾음
        // 걸린 시간 - 14660us
    }
    
}