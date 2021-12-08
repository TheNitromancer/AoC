#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int numOfBits = 12;	//Number of bits in each processed binary of the given list

void listToVector(vector<string>& binList) {
	string temp;
	ifstream dataFile("3-1.txt");

	if (dataFile.is_open()) {
		while (getline(dataFile, temp)) {
			binList.push_back(temp);
			}	//Stores the whole thing in a vector for further processing,
		}	    //the C++ way B)
		dataFile.close();
}

int getRating(vector<string> binList, const char& type) {
	    int numOZ, mostCommon;
    vector<string> :: iterator temp;
    for (int j = 0; j < numOfBits; j++) {
        numOZ = 0;    //Resets the number of zeros for each bit column shift
        for (int i = 0; i < binList.size(); i++) {
            if (binList[i][j] == '0') {
                numOZ++;
            }
        }

        mostCommon = numOZ <= (binList.size() / 2); 
        
        if(type == 'o') {
            temp = remove_if(binList.begin(), binList.end(), [j, mostCommon](const string& bin) {return (int(bin[j]) - 48) != mostCommon; });
        } else {
            temp = remove_if(binList.begin(), binList.end(), [j, mostCommon](const string& bin) {return (int(bin[j]) - 48) == mostCommon; });
        }   //Pushes the undesired binary numbers to the end of the vector

        if (temp == binList.begin()) {
            binList = { binList[binList.size() - 1] };
            continue;
        }    //Stores the desired rating and breaks out of the loop if the vector would loose it's last element
        else {
            binList.erase(temp, binList.end()); //Erases the undesired binaries previously pushed to the back
        }    
    }
    return stoi(binList[0], 0, 2);
}

int main() {
	vector<string> binList;

	listToVector(binList);

	cout << getRating(binList, 'o') * getRating(binList, 'c');
	
	return 0;
}	//What can I say other than: P A I N
//I've learnt a whole lot from this one though, that's for sure
//Even more after improving the code with the help of come lovely and very helpful people :)
