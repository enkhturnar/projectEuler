#include <cmath>
#include "number.h"

template<typename T>
T mult(T a, T b, T mod){
	T q = std::round(((double) a * b / mod));
    T result = (a * b - mod * q);
    result %= mod;
    if (result < 0) result += mod;
    return result;
}
template long long mult<long long>(long long a, long long b, long long mod);

template<typename T>
T modFastExp(T x, T n, T mod){
	if(n == 0){
		return 1;
	}
	if(n % 2 == 1){
		return mult( x , modFastExp(mult(x,x,mod), n/2 , mod),  mod);
	}
	else {
		return modFastExp(mult(x,x,mod), n/2 , mod) ;
	}
}
template int modFastExp<int>(int x, int n, int mod);
template long long modFastExp<long long>(long long x, long long n, long long mod);

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

