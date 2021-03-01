#ifndef SOLUTION_H
#define SOLUTION_H

#include<string>

class Solution {
public:
	virtual std::string solve() = 0;

	virtual std::string correct() = 0;

	virtual ~Solution() {}
};

#endif