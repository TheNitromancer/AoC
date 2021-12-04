#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct subCommand
{
	string instruction;
	int amount;
} Command;

int main() {
	int depth = 0, xPos = 0;
	subCommand currentComm;
	ifstream dataFile;
	dataFile.open("2-1.txt");

	if (dataFile.is_open()) {
		while (!dataFile.eof()) {
			dataFile >> currentComm.instruction;
			dataFile >> currentComm.amount;
			if (currentComm.instruction == "forward") {
				xPos += currentComm.amount;
			}
			else if (currentComm.instruction == "up") {
				depth -= currentComm.amount;
			}
			else {
				depth += currentComm.amount;
			}
		}
		dataFile.close();
	}
	/*Check wether the file opened correctly, if so, read the instruction and its
	value, then operate with the value accordingly*/

	cout << depth * xPos;

	return 0;
}
//Better way of operating once the instruction and value is read? Less use of conditionals?
//Other wise pretty happy with the result, looks compact to me :)
