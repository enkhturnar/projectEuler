#include<iostream>
#include<stdexcept>
#include<sstream>

#include "solution_generator.h"


#ifdef DEBUG
#define _(args) args
#else
#define _(args)
#endif

void get_modes(int argc, char* argv[], int& problemNumber);

int main(int argc, char* argv[]){
	int problemNumber;
	try {
		get_modes(argc,argv,problemNumber);
		Solution* s = getSolution(problemNumber);
		std::cout << s->solve() << std::endl;
	}
	catch(std::invalid_argument& e){
		std::cerr << e.what() << std::endl;
		return -1;
	}

	return 0;
}


void get_modes(int argc, char* argv[], int& problemNumber){
	if(argc < 2){
		throw std::invalid_argument("problem number no given");
	}
	else if(argc > 2){
		throw std::invalid_argument("too many arguments");
	}
	else {
		std::stringstream problemNumberString(argv[1]);
		problemNumberString >> problemNumber;
	}
}