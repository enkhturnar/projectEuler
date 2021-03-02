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

void runSolution(Solution* s);
int main(){
	cout << "PROBLEMS TEST" << endl;
	const vector<Solution*>* solutions = availableSolutions();
	vector<thread> threads(solutions->size());
	for(size_t i = 0; i < solutions->size(); i++){
		threads[i] = thread(runSolution, solutions->at(i));
	}

	for(size_t i = 0; i < solutions->size(); i++){
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

void runSolution(Solution* s){
	auto answer = s->solve();
	auto correct = s->correct();
	mtx.lock();
	if(answer == correct){
		cout << "P" << setw(5) << s->getProblemNumber() << ": ";
		cout << answer << " = " << correct << endl;
	}
	else {
		fails ++;
		cout << "F" << setw(5) << s->getProblemNumber() << ": ";
		cout << answer << " != " << correct << endl;
	}
	mtx.unlock();
}