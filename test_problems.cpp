#include <iostream>
#include <iomanip>
#include <vector>

#include "solution_generator.h"

using namespace std;

int main(){
	cout << "PROBLEMS TEST" << endl;
	vector<int> solutionNumbers = availableSolutions();
	int fails = 0;
	for(auto i : solutionNumbers){
		Solution *s = getSolution(i);
		auto answer = s->solve();
		auto correct = s->correct();
		if(answer == correct){
			cout << "P" << setw(5) << i << ": ";
			cout << answer << " = " << correct << endl;
		}
		else {
			cout << "F" << setw(5) << i << ": ";
			cout << answer << " != " << correct << endl;
			fails++;
		}
	}
	if(fails > 0){
		cout << fails << " FAILS!!!" << endl;
	}
	else {
		cout << "ALL PASS!!" << endl; 
	}
	return 0;
}