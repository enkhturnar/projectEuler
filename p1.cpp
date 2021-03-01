#include<string>

#include "solution.h"

class P1 : public Solution {
public:
	P1(){};
	std::string solve(){
		int sum = 0;
		for(int i = 1 ; i < 1000; i++){
			if(i % 3 == 0 or i % 5 == 0){
				sum += i;
			}
		}
		return std::to_string(sum);
	}
	std::string correct(){
		return "233168";
	}
};