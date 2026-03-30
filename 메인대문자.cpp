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

CHAR 소투대(CHAR C) 
{
    RETURN C = TOUPPER(C);
}

//--------
INT MAIN()
//--------
{
    IFSTREAM IN{ "메인.CPP" };
    IF (NOT IN) RETURN 1;

    OFSTREAM OUT{ "메인대문자.CPP" };

    // TRANSFORM(뭐를, 뭘로, 어떻게);
    // TRANSFORM(메인시작, 메인끝, 메인대문자시작위치로, 함수의시작번지);
    TRANSFORM(ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, OSTREAMBUF_ITERATOR<CHAR>{OUT},
        소투대);


    // SAVE("메인.CPP");
}