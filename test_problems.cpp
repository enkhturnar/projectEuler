#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <mutex>          // std::mutex

#include <map>

#include "solution_generator.h"

using namespace std;

mutex mtx;           // mutex for critical section
int fails = 0;

void runSolution(int idx);
int main(){
	cout << "PROBLEMS TEST" << endl;
	vector<int> solutionNumbers = availableSolutions();
	vector<thread> threads(solutionNumbers.size());
	for(size_t i = 0; i < solutionNumbers.size(); i++){
		threads[i] = thread(runSolution, solutionNumbers[i]);
	}

	for(size_t i = 0; i < solutionNumbers.size(); i++){
		threads[i].join();
	}
	if(fails == 0){
		cout << "ALL PASS!" << endl;
	}
	else {
		cout << fails << " FAILS!" << endl;
	}

	return 0;
}


void runSolution(int idx){
	Solution *s = getSolution(idx);
	auto answer = s->solve();
	auto correct = s->correct();
	mtx.lock();
	if(answer == correct){
		cout << "P" << setw(5) << idx << ": ";
		cout << answer << " = " << correct << endl;
	}
	else {
		fails ++;
		cout << "F" << setw(5) << idx << ": ";
		cout << answer << " != " << correct << endl;
	}
	mtx.unlock();
}