#include<string>

#include "solution.h"
#include "prime.h"

class P27: public Solution {
public:
	P27(){};

	int func(int a, int b, int n){
		return n*n + a*n + b;
	}

	std::string solve(){
		int maxConseq = 0;
		int ans = 1e9;
		for(int a = -999; a < 1000; a++){
			for(int b = -1000; b <= 1000; b++){
				int n = 0;
				while(isPrime(func(a,b,n))){
					n++;
				}
				if(maxConseq < n){
					maxConseq = n;
					ans = a*b;
				}
			}
		}
		return std::to_string(ans);
	}
	std::string correct(){
		return "-59231";
	}	
};