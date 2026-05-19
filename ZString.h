//--------------------------------------------------------------------------
// STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class
// 
// 2026.4.13
//--------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <string>
#include <memory>

// 2026. 05. 19
class ZString_Iterator {
public:
	// 표준 반복자가 되려면 다음 5가지 타입을 제공해야 한다.
	using iterator_category = std::random_access_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;

public:
	ZString_Iterator() = default;
	ZString_Iterator(char* p) : p{ p } { }

	// void로 놓으면 안된다.
	ZString_Iterator operator++() {
		return ++p;
	}
	ZString_Iterator operator--() {
		return --p;
	}
	char operator*() const {
		return *p;
	}
	char& operator*() {
		return *p;
	}

	difference_type operator-(const ZString_Iterator& rhs) const {
		return p - rhs.p;
	}
	ZString_Iterator operator+(difference_type n) const {
		 return p + n;
	}

	auto operator<=>(const ZString_Iterator& rhs) const = default;

private:
	char* p;
};

// 2026. 05. 19
class ZString_Reverse_Iterator {
public:
	ZString_Reverse_Iterator() = default;
	ZString_Reverse_Iterator(char* p) : p{ p } { }

	void operator++() { 
		--p;
	}
	char operator*() const { 
		return *(p - 1);
	}

	// 관계연산자는 6가지가 있음.
	// 그런데 우주선 연산자 한 개만 코딩해서 6개를 자동으로 만들 수 있다. - auto로 정의해야함.
	auto operator<=>(const ZString_Reverse_Iterator& rhs) const = default;

private:
	char* p;
};

class ZString {
public:
	ZString();
	~ZString();

	ZString(const char* s);

	// 복사
	ZString(const ZString&);
	ZString& operator=(const ZString&);

	// 이동
	ZString(ZString&&) noexcept;		// 2026. 4. 20 - move에서 예외를 던지지 않는다.
	ZString& operator=(ZString&&) noexcept;
	// move에서 예외를 던지면 컴파일러는 move대신 copy를 사용하게 됨.
	// 원본이 망가지고 복구가 불가하기 떄문.
	// copy는 속도가 느림.
	// noexcept -> 예외를 던지면 프로그램을 종료.


	// 2026. 04. 28 - 연산자 오버로딩
	bool operator==(const ZString& rhs) const;

	// 2026. 05. 12 - 반복자 인터페이스
	// 2026. 05. 19 - begin이 되돌려줘야할 타입은 클래스여야 한다.
	ZString_Iterator begin() const;
	ZString_Iterator end() const;

	// 2026. 05. 18 - 역방향 반복자 추가
	// 2026. 05. 19 - 역방향 반복자는 반드시 클래스로 코딩한다.
	ZString_Reverse_Iterator rbegin() const;
	ZString_Reverse_Iterator rend() const;

	// 인터페이스 함수 - 나중에 삭제 예성
	size_t getLen() const;

	// STL 컨테이너가 되려면 다음 함수 정도는 제공해야
	size_t size() const;
	char* data() const;			// 2026. 5. 11


	void special(std::string) const;

	void show() const;
	
	friend std::ostream& operator<<(std::ostream& os, const ZString& zs);
	
	// 2026. 04. 13
	friend std::istream& operator>>(std::istream& is, ZString& zs);

	
private:
	static size_t gid;				 // 고유번호를 부여하기 위한 값
	size_t id;                       // 객체 고유번호 - 생성 시 유일한 값
	size_t len{};				     // 관리하는 글자 개수	
	std::unique_ptr<char[]> p{};	 // 글자가 저장된 free-stroe 메모리	
};