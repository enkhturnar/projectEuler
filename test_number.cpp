#include <iostream>
#include <cassert>
#include <array>

#include "number.h"

using namespace std;

#define mAssert(condition, message)\
   (!(condition)) ?\
      (std::cerr << "Assertion failed: (" << #condition << "), "\
      << "function " << __FUNCTION__\
      << ", file " << __FILE__\
      << ", line " << __LINE__ << "."\
      << std::endl << message << std::endl, abort(), 0) : 1


void getDigitsTest();
void modFastExpTest();

int main(){
	cout << "Number library test" << endl;
	getDigitsTest();
	modFastExpTest();
	cout << "ALL PASS!" << endl;
	return 0;
}

void modFastExpTest(){
	mAssert(modFastExp(4,4,1000000) == 256, to_string(modFastExp(4,4,1000000)));
}


void getDigitsTest(){
	auto i = getDigits(4912);
	std::array<int,4> ar = {2,1,9,4};
	mAssert(std::equal(i.begin(),i.end(),ar.begin(),ar.end()),std::to_string(ar[0]) + std::to_string(i[0]));
}