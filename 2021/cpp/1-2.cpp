#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<int> depthMeasurements;
	int dmiTimes = 0, i = 0, j = 0, temp, A, B; //A and B will be the threegroups to compare
	ifstream dataFile;
	dataFile.open("C:\\Users\\ONeXt\\source\\repos\\Advent of Code\\1-1.txt");

	if (dataFile.is_open()) {
		while (!dataFile.eof()) {
			dataFile >> temp;
			depthMeasurements.push_back(temp);
			i++;
		}
		dataFile.close();
	}

	A = depthMeasurements[0] + depthMeasurements[1] + depthMeasurements[2];
	//Setup of the first threegroup
	while (j < (depthMeasurements.size() - 3)) {
		if (j % 2 == 0) {	
			B = depthMeasurements[j + 1] + depthMeasurements[j + 2] + depthMeasurements[j + 3];
			if (B > A) dmiTimes++;
		} else {
			A = depthMeasurements[j + 1] + depthMeasurements[j + 2] + depthMeasurements[j + 3];
			if (A > B) dmiTimes++;
		}
		//Iteration that shifts A and B as the first threegroup and checks for depth increments accordingly
		j++;
	}

	cout << dmiTimes;
	
	return 0;
}
//No functions were used due to lack of reusability in the program*
//Would a better solution make use of vectors/arrays to store the numbers
//in threegroups and compare them that way?
//Overuse of conditionals? 
//Too many variables?
