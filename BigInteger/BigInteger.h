#pragma once
#ifndef _BIGINTEGER_H_
#define _BIGINTEGER_H_

#include <iostream>
#include <list>

class BigInteger {
	typedef unsigned int u4_t;
	typedef unsigned long long u8_t;
private:
	/******** 멤버 변수 ********/

	/*
	* 임의의 길이의 정수 값을 바이너리 형태로 u4_t 리스트에 저장한다.
	* 이때 u4_t의 각 상위 2개 비트를 비우고 30비트씩 나눈다.
	* 즉 2^30 진법을 사용한다.
	* 리틀 엔디안 방식을 적용하여 앞의 원소가 작은 값을 담당하며
	* 가장 뒤 원소의 29번째 비트가 1이면 음수를 표현한다.
	*/
	//바이너리 정수 값 내부 저장구조
	std::list<u4_t> _value;


	/******** private 멤버 함수 ********/

	//16진수 문자열로 _value 초기화
	void init_with_hex_string(const std::string& init_value);
	//u4_t의 상위 2개 비트 제거
	inline void set_endbits_0(u4_t& value) { value &= 0x3FFFFFFF; }
	//u4_t의 상위 2개 비트 얻기
	inline u4_t get_endbits(const u4_t& value) { return value >> 30; }
	//부호 비트 구함
	inline bool signbit() { return _value.back() & 0x20000000 >> 29; }

public:
	/******** 생성자 ********/

	BigInteger() : BigInteger(0) {}
	BigInteger(int init_value);
	BigInteger(unsigned int init_value);
	BigInteger(const char* init_value) : BigInteger(std::string(init_value)) {}
	BigInteger(const std::string& init_value);


	/******** 산술 연산자 ********/

	BigInteger operator+(const BigInteger& rhs);



	/******** I/O 스트림 연산자 ********/

	friend std::ostream& operator<<(std::ostream& os, const BigInteger& val);


	/******** 기타 함수 ********/

	//객체 내부에 저장된 원시값을 hex로 출력
	const std::list<unsigned int>& data() const;
};

#endif