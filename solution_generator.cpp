#include<stdexcept>

#include "p1.cpp"
#include "p27.cpp"
#include "p34.cpp"
#include "p47.cpp"
#include "p48.cpp"
#include "solution.h"
#include "solution_generator.h"

const std::vector<Solution*> solutions{
	new P1(),
	new P27(),
	new P34(),
	new P47(),
	new P48(),
};

Solution* getSolution(int problemNumber){
	int s = 0, e = solutions.size() - 1;
	while (s < e){
		int mid = (s + e) / 2;
		if(solutions[mid]->getProblemNumber() <= problemNumber){
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}
	if(solutions[s]->getProblemNumber() == problemNumber){
		return solutions[s];
	}
	else{
		throw std::invalid_argument("problem number invalid");
		return 0;
	}
}

const std::vector<Solution*>* availableSolutions(){
	return &solutions;
}