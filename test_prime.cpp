#include <iostream>
#include <cassert>

#include "prime.h"

using namespace std;

void isPrimeTest();

int main(){
	cout << "Prime library test" << endl;
	isPrimeTest();
	cout << "ALL PASS!" << endl;
	return 0;
}


void isPrimeTest(){
	assert(isPrime(13) == true);
	assert(isPrime(12) == false);
	assert(isPrime(49) == false);
	assert(isPrime(107) == true);
}