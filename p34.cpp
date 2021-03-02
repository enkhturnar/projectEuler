#include<iostream>
#include<string>
#include<numeric>
#include<vector>
#include<map>

#include "solution.h"
class P34 : public Solution {
	std::map<int,int> mp;
	std::vector<int> fct;
public:
	P34(): Solution(34){};
	int digitSum(int x){
		fct.push_back(1);
		for(int i = 1; i < 10; i++){
			fct.push_back(fct.back()*i);
		}
		if(mp.find(x) != mp.end()){
			return mp[x];
		}
		if(x < 10){
			mp[x] = fct[x];
		}
		else{
			mp[x] = fct[x%10] + digitSum(x/10);
		}
		return mp[x];
	}

	std::string solve(){
		int i = 10;
		int total = 0;
		while(i < 1e6){
			if(i == digitSum(i)){
				total += i;
			}
			i++;
		}

		return std::to_string(total);
	}
	std::string correct(){
		return "40730";
	}
};