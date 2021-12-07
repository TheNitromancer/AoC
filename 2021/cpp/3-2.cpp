#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int numOfBits = 12;	//Number of bits in each processed binary of the given list

void listToVector(vector<string>& binList, int& crnchd) {
	string temp;
	ifstream dataFile;
	dataFile.open("3-1.txt");

	if (dataFile.is_open()) {
		while (!dataFile.eof()) {
			getline(dataFile, temp);
			binList.push_back(temp);
			}	//Stores the whole thing in a vector for further processing
			crnchd++;
		}	
		dataFile.close();
}

int getRating(vector<string> binList, const char& type) {
	int numOZ, mostCommon;
	vector<string> :: iterator temp;
	for (int j = 0; j < numOfBits; j++) {
		numOZ = 0;	//Resets the number of zeros for each bit column shift
		for (int i = 0; i < binList.size(); i++) {
			if (binList[i][j] == '0') {
				numOZ++;
			}
		}

		switch (type)
		{
		case 'o':
			if (numOZ > (binList.size() / 2)) {
				mostCommon = 0;
			}
			else {
				mostCommon = 1;
			}
			temp = remove_if(binList.begin(), binList.end(), [j, mostCommon](const string& bin) {return (int(bin[j]) - 48) != mostCommon; });
			if (temp == binList.begin()) {
				binList = { binList[binList.size() - 1] };
				continue;
			}	//On full vector removal, set binList to what would be the last remaining item and break off the loop
			else {
				binList.erase(temp, binList.end());
			}	
			break;
		case 'c':
			if (numOZ > (binList.size() / 2)) {
				mostCommon = 0;
			}
			else {
				mostCommon = 1;
			}
			temp = remove_if(binList.begin(), binList.end(), [j, mostCommon](const string& bin) {return (int(bin[j]) - 48) == mostCommon; });
			if (temp == (binList.begin())) {
				binList = { binList[binList.size() - 1] };
				continue;
			}	//On full vector removal, set binList to what would be the last remaining item and break off the loop
			else {
				binList.erase(temp, binList.end());
			}
			break;
		}
	}
	return stoi(binList[0], 0, 2);
}

int main() {
	vector<string> binList;
	int crunchedBinaries = 0;

	listToVector(binList, crunchedBinaries);

	cout << getRating(binList, 'o') * getRating(binList, 'c');
	
	return 0;
}	//What can I say other than: P A I N
//I've learnt a whole lot from this one though, that's for sure. Algorithms, iterators, lambda functions... you name it
