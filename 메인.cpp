//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.30(월)
//----------------------------------------------
// collable types -> 실습 -> STL
//----------------------------------------------
#include <iostream>
#include <random>
#include <array>
#include <print>
#include <ranges>
#include "save.h"
using namespace std;

// [문제] 랜덤값을 갖는 int 1000만개를 메모리에 저장하라.
// qsort를 이용하여 오름차순 정렬하시오.
// 정렬 결과를 앞에서부터 1000개만 화면에 출력하라.

default_random_engine dre;
uniform_int_distribution uid{ 0, 999'9999 };

array<int, 1000'0000> a;

int 오름차순(const void* a, const void* b)
{
    // 바꿔야되면 1, 아니면 -1, 같으면 0
    return *(int*)a - *(int*)b;
}

//--------
int main()
//--------
{
    for (int& num : a)
        num = uid(dre);

    // 시간 측정 시작
    qsort(a.data(), a.size(), sizeof(array<int, 1000'0000>::value_type), 오름차순);
    // 시간 측정 끝

    cout << "정렬 후 출력" << endl;
    //for (int i{}; i < 1000; ++i)
    //    print("{:8}", a[i]);
    // 이렇게 하지 말어라

    for(int num : a | views::reverse        // 반대로 출력
                    | views::take(1000))    // 앞에서부터 1000개
        print("{:8}", num);


    // save("메인.cpp");
}