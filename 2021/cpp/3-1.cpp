#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

void gammaArchitect(const vector<int>& nZ, string& gamma, int crnchd) {
	for (int i = 0; i < nZ.size(); i++) {
		if (nZ[i] <= (crnchd / 2)) {
			gamma[i] = '1';
		}	//Updates bit to 1 if there are less 0s than there are 1s
			//*takes into account c++'s "/" operator rounds down the result
	}
}	//Since gamma is 0 by default, it is only necessary to update the bits that are 1

void bitSwitch(string& binN) {
	for (int i = 0; i < binN.size(); i++) {
		switch (binN[i]) {
		case '1':
			binN[i] = '0';
			break;
		case '0':
			binN[i] = '1';
			break;
		}
	}
}	//Precedure for binary bit switch

int binaryToDecimal(const string& bin) {
	int val = 0, temp;
	for (int i = 0; i < bin.size(); i++) {
		temp = int(bin[i]) - 48;
		val += temp * (pow(2, 11 - i));
	}
	return val;
}

int main() {
	vector<int> numOfZeros(12, 0);
	string number, gammaRate = "000000000000", epsilonRate = gammaRate;
	int numOfBits = 12, binariesCrunched = 0;
	//Binaries can be safely stored in strings, the number of zeros has to be a vector
	//so it can store numbers past 9. I've learnt the hard way why it shouldn't be a string too

	ifstream dataFile;
	dataFile.open("3-1.txt");

	if (dataFile.is_open()) {
		while (!dataFile.eof()) {
			dataFile >> number;
			for (int i = 0; i < numOfBits; i++) {
				if (number[i] == '0') {
					numOfZeros[i]++;
				}
			}
			binariesCrunched++;
		}	//Stores the total number of 0s for each bit and the number of binary numbers computed
		dataFile.close();
	}
	//Total number of zeros for each bit is known
	//Time to check for most common:
	gammaArchitect(numOfZeros, gammaRate, binariesCrunched);

	epsilonRate = gammaRate;
	bitSwitch(epsilonRate);

	//Convert to decimal and print final value:
	cout << binaryToDecimal(gammaRate) * binaryToDecimal(epsilonRate);

	return 0;
}
/*This one was quite the challenge! Started by having numOfZeros be a string: huge mistake,
once a character exceded number 9 it wasn't a number anymore. Binaries work no problem as strings though,
just have to remember to "x = int(bin[i]) - 48" when operating with a bit*/
