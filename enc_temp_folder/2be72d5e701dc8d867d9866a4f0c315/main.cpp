#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "readInput.h"

int main() {

	std::vector<std::string> myInput;
	readVectorFromFile(myInput);

	//Example input
	//std::vector<std::string> myInput = { "#1 @ 5, 5: 2x2",
	//	"#2 @ 5, 5: 2x2",
	//	"#3 @ 5, 5: 2x2",
	//	"#4 @ 5, 5: 2x2" };

	int size = myInput.size();
	int sizes[2][sizeof(myInput)];
	//std::vector<std::vector<int>> positions(2, std::vector<int>(size));

	std::vector<int> posX;
	std::vector<int> posY;

	std::vector<int> width;
	std::vector<int> heigth;

	std::vector<int> index;
	

	int k = 0;
	for (std::vector<std::string>::iterator i = myInput.begin(); i != myInput.end(); i++) {

		std::string subset = *i;
		std::string position;
		auto index1 = subset.find("@") + 2;
		auto index2 = subset.find(":");
		position = subset.substr(index1, index2-index1);
		std::string pos1 = position.substr(0,position.find(","));
		std::string pos2 = position.substr(position.find(",")+1);
		posX.push_back(std::stoi(pos1));
		posY.push_back(std::stoi(pos2));

		std::string newSubstring = subset.substr(index2 + 2);
		std::string wi = newSubstring.substr(0, newSubstring.find("x"));
		std::string he = subset.substr(subset.find("x")+1);
		width.push_back(std::stoi(wi));
		heigth.push_back(std::stoi(he));
		std::string subset2 = subset.substr(index2+1);

		// get Index Number
		std::string id = subset.substr(subset.find("#") + 1, subset.find("@") - 1);
		index.push_back(std::stoi(id));

		k = k + 1;
		
	}

	std::vector<int> largestWidth = width;
	std::vector<int> largestHeigth = heigth;
	std::sort(largestWidth.begin(), largestWidth.end(), std::greater<int>());
	std::sort(largestHeigth.begin(), largestHeigth.end(), std::greater<int>());

	std::vector<int> posXLargest = posX;
	std::vector<int> posYLargest = posY;
	std::sort(posXLargest.begin(), posXLargest.end(), std::greater<int>());
	std::sort(posYLargest.begin(), posYLargest.end(), std::greater<int>());

	std::vector<std::vector<int>> fabricMatrix(largestWidth[0]+ posXLargest[0], std::vector<int>(largestHeigth[0] + posYLargest[0]));
	//std::vector<std::vector<int>> fabricMatrix(1000, std::vector<int>(1000));
	//std::fill(fabricMatrix[0].begin(), fabricMatrix[0].end(), 0);

	for (int line = 0; line < myInput.size(); line++) {
		for (int x = posX[line]; x < posX[line] + width[line]; x++) {
			for (int y = posY[line]; y < posY[line] + heigth[line]; y++) {
				fabricMatrix[x][y]++;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < fabricMatrix.size(); i++) {
		for (int j = 0; j < fabricMatrix[0].size(); j++) {
			int result = fabricMatrix[i][j];
			if (result >1) {
				sum++;

			}
		}
	}

	std::cout << sum << std::endl;

	for (int line = 0; line < myInput.size(); line++) {
		bool openPatch = true;
		for (int x = posX[line]; x < posX[line] + width[line]; x++) {
			for (int y = posY[line]; y < posY[line] + heigth[line]; y++) {
				if (fabricMatrix[x][y] > 1) {
					openPatch = false;
				}
			}
		}
		if (openPatch == true) {
			std::cout << line << ": " << index[line] << std::endl;
		}


	}

	std::cin.get();
	return 0;
}