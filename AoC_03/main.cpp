#include <iostream>
#include <string>
#include <vector>

#include "readInput.h"

int main() {

	//std::vector<std::string> myInput;
	//readVectorFromFile(myInput);

	//Example input
	std::vector<std::string> myInput ={"#1 @ 1,3: 4x5",
		"#2 @ 3,1: 4x4",
		"#3 @ 10,5: 3x2"};

	int size = myInput.size();
	std::vector<std::vector<int>> positions;
	int sizes[2][sizeof(myInput)];
	std::vector<std::vector<int>> fabricMatrix;
	int k = 0;
	for (std::vector<std::string>::iterator i = myInput.begin(); i != myInput.end(); i++) {
		std::cout << *i << std::endl;

		std::string subset = *i;
		std::string position;
		auto index1 = subset.find("@") + 2;
		auto index2 = subset.find(":");
		position = subset.substr(index1, index2-index1);
		std::string pos1 = position.substr(0,position.find(","));
		std::string pos2 = position.substr(position.find(",")+1);
		positions[0][k] = std::stoi(pos1);
		positions[1][k] = std::stoi(pos2);

		std::string newSubstring = subset.substr(index2 + 2);
		std::string width = newSubstring.substr(0, newSubstring.find("x"));
		std::string heigth = subset.substr(subset.find("x")+1);
		sizes[0][k] = std::stoi(width);
		sizes[1][k] = std::stoi(heigth);

		std::cout << position << std::endl;
		std::string subset2 = subset.substr(index2+1);
		std::cout << subset2 << std::endl;

		// get Index Number
		std::string id = subset.substr(subset.find("#") + 1, subset.find("@") - 1);
		//positions[0][k] = std::stoi(id);

		k = k + 1;
		
	}


	std::cin.get();
	return 0;
}