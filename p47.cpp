#include<string>

#include "solution.h"
#include "prime.h"

class P47 : public Solution {
public:
	P47(): Solution(47){};
	bool have4distict(int n){
		for(int i = 0 ; i < 4; i++){
			auto fact = primeFactorization(n + i);
			if( fact.size() < 4 ){
				return false;
			}
		}
		return true;
	}
	std::string solve(){
		int n = 1;
		while(!have4distict(n)){
			n++;
		};
		return std::to_string(n);
	}
	std::string correct(){
		return "134043";
	}
};