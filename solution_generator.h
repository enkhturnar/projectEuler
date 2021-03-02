#ifndef SOLUTION_GENERATOR_H
#define SOLUTION_GENERATOR_H

#include <vector>

#include "solution.h"


Solution* getSolution(int problemNumber);

const std::vector<Solution*>* availableSolutions();

#endif