#include "number.h"

template<typename T>
std::vector<int> getDigits(T i){
	std::vector<int> digits;
	while(i > 0){
		digits.push_back(i%10);
		i /= 10;
	}
	return digits;
}

template std::vector<int> getDigits<int>(int i);