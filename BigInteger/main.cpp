#include <iostream>
#include "BigInteger.h"

void TEST_INIT_WITH_INT() {
	using std::cout;
	using std::endl;

	BigInteger val1;
	cout << val1 << endl;
	BigInteger val2 = 0x1AEF;
	cout << val2 << endl;
	BigInteger val3 = 0x3FFFFFFF;
	cout << val3 << endl;

	BigInteger val4 = 0x40000000;
	cout << val4 << endl;

	BigInteger val5 = 0x40000017;
	cout << val5 << endl;
	BigInteger val6 = 0x80000017;
	cout << val6 << endl;
	BigInteger val7 = 0xC0000017;
	cout << val7 << endl;
	BigInteger val8 = 0xFFFFFFFF;
	cout << val8 << endl;

	BigInteger val9 = (int)0x80000017;
	cout << val9 << endl;
	BigInteger val10 = (int)0xC0000017;
	cout << val10 << endl;
	BigInteger val11 = (int)0xFFFFFFFF;
	cout << val11 << endl;
}

void TEST_INIT_WITH_HEX_STRING() {
	BigInteger val = "0x3e5";
	BigInteger val2 = "0X3E5";
}


void TEST_ADD_BigInteger() {
	BigInteger v1(5), v2(3);
	std::cout << "v1: " << v1 << ", v2: " << v2 << "\n";
	std::cout << "v1 + v2: " << (v1 + v2) << "\n";
}


int main(void) 
{
	std::cout << "BigInteger Project\n";
	TEST_INIT_WITH_INT();
}