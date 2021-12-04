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
/*First functional attempt at the first puzzle. 
Thought I could maybe take the measurements directly from the website, but that's a bit out of my current reach, 
so I instead copied everything into a .txt and read the data from there. I'm sure there are far more elegant and/or efficient solutions, but hey! It works!!
Hope I'll be swifter programming the following puzzles now I've polished some of the rust off.
On with the coding!*/
