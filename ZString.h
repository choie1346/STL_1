//--------------------------------------------------------------------------
// STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class
// 
// 2026.4.13
//--------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <string>
#include <memory>


class ZString {
public:
	ZString();
	~ZString();

	ZString(const char* s);

	// 복사
	ZString(const ZString&);
	ZString& operator=(const ZString&);

	// 이동 - C++11부터 지원되는 move semantics
	ZString(ZString&&) noexcept;		// 2026. 4. 20 - move에서 예외를 던지지 않는다.
	ZString& operator=(ZString&&) noexcept;
	// move에서 예외를 던지면 컴파일러는 move대신 copy를 사용하게 됨.
	// 원본이 망가지고 복구가 불가하기 떄문.
	// copy는 속도가 느림.
	// noexcept -> 예외를 던지면 프로그램을 종료.



	// 연산자 오버로딩
	// 2026. 04. 28
	bool operator==(const ZString& rhs) const;
	// 인터페이스 함수 - 나중에 삭제 예성
	size_t getLen() const;

	// STL 컨테이너가 되려면 다음 함수 정도는 제공해야
	size_t size() const;


	void special(std::string) const;

	void show() const;
	
	friend std::ostream& operator<<(std::ostream& os, const ZString& zs);
	
	// 파일에서 읽어오려고 만듦 - 20260413
	friend std::istream& operator>>(std::istream& is, ZString& zs);

	
private:
	static size_t gid;				 // 고유번호를 부여하기 위한 값
	size_t id;                       // 객체 고유번호 - 생성 시 유일한 값
	size_t len{};				     // 관리하는 글자 개수	
	std::unique_ptr<char[]> p{};	 // 글자가 저장된 free-stroe 메모리	
};