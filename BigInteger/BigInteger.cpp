#include "BigInteger.h"
#include <iomanip>
#include <map>
#include <algorithm>

/******** Private 함수 ********/

void BigInteger::init_with_hex_string(const std::string& init_value) {
	std::map<char, int> map {
		{'0', 0x0}, {'1', 0x1}, {'2', 0x2}, {'3', 0x3},
		{'4', 0x4}, {'5', 0x5}, {'6', 0x6}, {'7', 0x7},
		{'8', 0x8}, {'9', 0x9}, {'A', 0xA}, {'B', 0xB},
		{'C', 0xC}, {'D', 0xD}, {'E', 0xE}, {'F', 0xF}
	};

	int counter = 0, shift = 0;
	for (auto it = init_value.rbegin(); it != init_value.rend(); ++it) {
		if (++counter == 8) {
			_value.back() |= (0x0);
		}
		else {
			_value.back() |= (map[*it] << shift);
			shift += 4;
			if (counter == 15)
				counter = 0;
		}
	}
}



/******** 생성자 ********/

BigInteger::BigInteger(int init_value)
	: BigInteger((unsigned int)init_value) {
	if (init_value < 0)
		_value.back() |= 0x3FFFFFFC;
}

BigInteger::BigInteger(unsigned int init_value) {
	_value.push_back(init_value);
	u4_t endbit = get_endbits(init_value);
	if (endbit > 0) {
		set_endbits_0(_value.back());
		_value.push_back(endbit);
	}
}

BigInteger::BigInteger(const std::string& init_value) {
	if (init_value.size() > 2) {
		std::string prefix = init_value.substr(0, 2);
		if (prefix == "0x" || prefix == "0X") {
			init_with_hex_string(init_value);
		}
	}
}


/******** 산술 연산자 ********/

BigInteger BigInteger::operator+(const BigInteger& rhs) {
	BigInteger&& ret(0);

	return ret;
}


/******** I/O 스트림 연산자 ********/

std::ostream& operator<<(std::ostream& os, const BigInteger& val) {
	char buff[16] = { 0 };
	unsigned int i = 0;
	for (auto it = val.data().cbegin(); it != val.data().cend(); ++it, ++i) {
		if (i != 0)
			os << " ";
		sprintf_s(buff, "%u:%0.8X", i, *it);
		os << buff;
	}
	return os;
}


/******** 기타 함수 ********/

const std::list<unsigned int>& BigInteger::data() const {
	return this->_value;
}
