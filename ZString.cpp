//--------------------------------------------------------------------------
// STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class
// 
// 2026.4.13
//--------------------------------------------------------------------------
#pragma once
#include <print>
#include <algorithm>
#include "ZString.h"

size_t ZString::gid{};        // 외부에서 초기화
bool 관찰{ false };

ZString::ZString()
	: id {++gid}
{
	if (관찰)
		special("생성");
}

ZString::~ZString()
{
	if (관찰)
		special("소멸");
}

ZString::ZString(const char* s) 
	: id{++gid}
{
	len = strlen(s);
	p = std::make_unique<char[]>(len);									 // p = new char[len]; 스마트포인터를 만들고 초기화 할때는 해당방식으로 초기화 X
	memcpy(p.get(), s, len);										 // make_unique<char[]>(len) 스마트포인터는 이렇게 초기화함

	if (관찰)
		special("생성(*)");
}


// 복사생성과 복사할당연산자
ZString::ZString(const ZString& other)
	: id{++gid}
{
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰)
		special("복사생성");
}

ZString& ZString::operator=(const ZString& other)
{
	if (this == &other)
		return *this;

	len = other.len;
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰)
		special("복사할당");

	return *this;
}

// 이동생성과 이동할당연산자
ZString::ZString(ZString&& other) noexcept
	: id {++gid}
{
	len = other.len;
	p.reset(other.p.release());	// other가 가지고 있던 memory를 p로 가져옴, other는 해제

	other.len = 0;				
	// 자기 자원이 이동된 other는 xvalue가 되고 이것을 사용하면 undefined behavior

	if (관찰)
		special("이동생성");
}

ZString& ZString::operator=(ZString&& other) noexcept
{
	if (this == &other)
		return *this;

	len = other.len;
	// 메모리 잘 반환 되었는지 주의.
	p.reset(other.p.release());
	other.len = 0;

	if (관찰)
		special("이동할당");

	return *this;
}

// 2026. 04. 28
bool ZString::operator==(const ZString& rhs) const
{
	// 동등성과(equality) 상등성(equivalence)의 차이
	//id, len, p가 있는데 -> 내가 관리하는 글자가 같으면 같은거다.
	if (len != rhs.len) return false;


	return std::equal(p.get(), p.get() + len, rhs.p.get());	// bool을 리턴함.

	//for (int i = 0; i < len; ++i) {
	//	if (p[i] != rhs.p[i]) return false;
	//} -> 이따위로 쓰지 말아라
	// return true;
}

size_t ZString::getLen() const
{
	return len;
}

size_t ZString::size() const
{
	return len;
}

char* ZString::data() const
{
	return p.get();
}

void ZString::special(std::string 동작) const
{
	// 글자수가 10개 이살이라도 10개 까지만 출력
	int num = 10;
	if (len < 10)
		num = len;
	std::string 글자{};
	for (int i = 0; i < num; ++i)
		글자 += p[i];

	if (관찰) {
		std::println("[{:7}] {:8} - 객체:{:#016X}, 글자:{:#016X}, 개수:{:<6} 내용:{}",
			id, 동작, (long long)this, (long long)p.get(), len, 글자);
	}
}

void ZString::show() const	// 2026. 4. 20
{
	special("show");

}


std::ostream& operator<<(std::ostream& os, const ZString& zs) 
{
	for (int i = 0; i < zs.len; ++i)
		os << *(zs.p.get() + i);
	return os;
}

std::istream& operator>>(std::istream& is, ZString& zs)
{
	// 내일 그림 설명으로 시작~

	std::string s;
	is >> s;
	zs.len = s.size();
	zs.p.reset();
	zs.p = std::make_unique<char[]>(s.size());
	memcpy(zs.p.get(), s.data(), zs.len);

	return is;
}
