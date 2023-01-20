#pragma once
#ifndef _BIGINTEGER_H_
#define _BIGINTEGER_H_

#include <iostream>
#include <list>

class BigInteger {
	typedef unsigned int u4_t;
	typedef unsigned long long u8_t;
private:
	/******** ��� ���� ********/

	/*
	* ������ ������ ���� ���� ���̳ʸ� ���·� u4_t ����Ʈ�� �����Ѵ�.
	* �̶� u4_t�� �� ���� 2�� ��Ʈ�� ���� 30��Ʈ�� ������.
	* �� 2^30 ������ ����Ѵ�.
	* ��Ʋ ����� ����� �����Ͽ� ���� ���Ұ� ���� ���� ����ϸ�
	* ���� �� ������ 29��° ��Ʈ�� 1�̸� ������ ǥ���Ѵ�.
	*/
	//���̳ʸ� ���� �� ���� ���屸��
	std::list<u4_t> _value;


	/******** private ��� �Լ� ********/

	//16���� ���ڿ��� _value �ʱ�ȭ
	void init_with_hex_string(const std::string& init_value);
	//u4_t�� ���� 2�� ��Ʈ ����
	inline void set_endbits_0(u4_t& value) { value &= 0x3FFFFFFF; }
	//u4_t�� ���� 2�� ��Ʈ ���
	inline u4_t get_endbits(const u4_t& value) { return value >> 30; }
	//��ȣ ��Ʈ ����
	inline bool signbit() { return _value.back() & 0x20000000 >> 29; }

public:
	/******** ������ ********/

	BigInteger() : BigInteger(0) {}
	BigInteger(int init_value);
	BigInteger(unsigned int init_value);
	BigInteger(const char* init_value) : BigInteger(std::string(init_value)) {}
	BigInteger(const std::string& init_value);


	/******** ��� ������ ********/

	BigInteger operator+(const BigInteger& rhs);



	/******** I/O ��Ʈ�� ������ ********/

	friend std::ostream& operator<<(std::ostream& os, const BigInteger& val);


	/******** ��Ÿ �Լ� ********/

	//��ü ���ο� ����� ���ð��� hex�� ���
	const std::list<unsigned int>& data() const;
};

#endif