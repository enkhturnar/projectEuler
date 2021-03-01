#ifndef NUMBER_H
#define NUMBER_H

#include<vector>

template<typename T>
std::vector<int> getDigits(T i);

template<typename T>
T modFastExp(T x, T n, T mod);

template<typename T>
T mult(T a, T b, T mod);

#endif