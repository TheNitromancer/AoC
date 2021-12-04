#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	vector<int> depthMeasurements;
	int dmiTimes = 0, i = 0, temp;
	ifstream dataFile;
	dataFile.open("C:\\Users\\ONeXt\\source\\repos\\Advent of Code\\1-1.txt"); 

	while (!dataFile.eof()) {
		dataFile >> temp;
		depthMeasurements.push_back(temp);
		i++;
	}
	for (int j = 1; j < depthMeasurements.size(); j++) {
		if ((depthMeasurements[j] - depthMeasurements[j - 1]) > 0) {
			dmiTimes++;
		}
	}
	cout << dmiTimes;

	return 0;
}
