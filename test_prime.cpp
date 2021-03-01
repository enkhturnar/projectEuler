#include <iostream>
#include <cassert>

#include "prime.h"

using namespace std;

void isPrimeTest();
void primeFactorizationTest();
int main(){
	cout << "Prime library test" << endl;
	isPrimeTest();
	primeFactorizationTest();
	cout << "ALL PASS!" << endl;
	return 0;
}


void isPrimeTest(){
	assert(isPrime(13) == true);
	assert(isPrime(12) == false);
	assert(isPrime(49) == false);
	assert(isPrime(107) == true);
}

void primeFactorizationTest(){
	auto f = primeFactorization(644);
	assert(f.size() == 3);
	assert(f.count(23) == 1);
	assert(f[23] == 1);
	assert(f.count(2) == 1);
	assert(f[2] == 2);
}
