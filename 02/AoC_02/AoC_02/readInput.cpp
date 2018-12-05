#include "readInput.h"



void readVectorFromFile(std::vector<std::string> &temp) {
	std::ifstream infile;
	infile.open("..\\..\\input.txt");

	if (infile.fail()) {
		std::cout << "Could not open file numbers." << "\n";
		return;
	}

	std::string data;
	while (infile >> data) {
		temp.push_back(data);
	}
}