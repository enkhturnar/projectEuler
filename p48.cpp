#include<iostream>
#include<string>

#include "solution.h"
#include "number.h"

class P48 : public Solution {
public:
	P48(): Solution(48){};
	std::string solve(){
		long long mod = 1e10;
		long long sum = 0;
		for(long long i = 1; i <= 1000; i++){
			sum += modFastExp(i,i,mod);
			sum %= mod;
		}

		return std::to_string(sum);
	}
	std::string correct(){
		return "9110846700";
	}
};