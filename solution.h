#ifndef SOLUTION_H
#define SOLUTION_H

#include<string>

class Solution {
	int problemNumber;
public:
	Solution(int _problemNumber) : problemNumber(_problemNumber) {};

	virtual std::string solve() = 0;

	virtual std::string correct() = 0;

	int getProblemNumber(){
		return problemNumber;
	};

	virtual ~Solution() {}
};

#endif