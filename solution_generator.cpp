#include<stdexcept>

#include "p1.cpp"
#include "p27.cpp"
#include "solution.h"
#include "solution_generator.h"

Solution* getSolution(int problemNumber){
	Solution *s;
	switch(problemNumber) {
		case 1:
			s = new P1();
		break;
		case 27:
			s = new P27();
		break;
		default:
			throw std::invalid_argument("problem number invalid");
		break;
	}
	return s;
}


std::vector<int> availableSolutions(){
	return {1,27};
}