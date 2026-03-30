//----------------------------------------------
// 2026 1학기 STL 월56 화 78      2026.03.30(월)
//----------------------------------------------
// COLLABLE TYPES -> 실습 -> STL
//----------------------------------------------
#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"
USING NAMESPACE STD;

// [문제] "메인.CPP"의 소문자를 모두 대문자로 바꾼 "메인대문자.CPP"를 만들어라.
// TRANSFORM(메인.CPP, 메인대문자.CPP, 소문자를 대문자로);
// TRANSFORM(뭐를, 뭘로, 어떻게);

//--------
INT MAIN()
//--------
{
    IFSTREAM IN{ "메인.CPP" };
    IF (NOT IN) RETURN 1;

    OFSTREAM OUT{ "메인대문자.CPP" };

    TRANSFORM(ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, OSTREAMBUF_ITERATOR<CHAR>{OUT},
        [](CHAR C) {RETURN C = TOUPPER(C); });


    // SAVE("메인.CPP");
}