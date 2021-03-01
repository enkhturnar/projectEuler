#include "prime.h"

template<typename T>
bool isPrime(T x){
	if(x < 2){
		return false;
	}
	else if(2 <= x and x < 4){
		return true;
	}
	else {
		T i = 2;
		while( i*i <= x){
			if(x%i == 0){
				return false;
			}
			i++;
		}
		return true;
	}
}

template bool isPrime<int>(int x);
template bool isPrime<unsigned int>(unsigned int x);
template bool isPrime<long>(long x);
template bool isPrime<unsigned long>(unsigned long x);
template bool isPrime<long long>(long long x);
template bool isPrime<unsigned long long>(unsigned long long x);