#include "readInput.h"


void readVectorFromFile(std::vector<int> &temp) {
	std::ifstream infile;
	infile.open("..\\..\\input.txt");

	if (infile.fail()) {
		std::cout << "Could not open file numbers." << "\n";
		return;
	}

	int data;
	while (infile >> data) {
		temp.push_back(data);
	}
}