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

int main(){
	cout << "Number library test" << endl;
	getDigitsTest();
	cout << "ALL PASS!" << endl;
	return 0;
}



void getDigitsTest(){
	auto i = getDigits(4912);
	std::array<int,4> ar = {2,1,9,4};
	mAssert(std::equal(i.begin(),i.end(),ar.begin(),ar.end()),std::to_string(ar[0]) + std::to_string(i[0]));
}