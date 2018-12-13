#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "readInput.h"

int main() {

	/* Day 3 part 1 :
	- generate matrix filled by input orders: string containing "#1" id, "@ posX, PosY" 
	as start of position of patch (rectangle) and "2x2" as size of the rectangle.
	- find the number of overlapping patch elements
	*/

	// Inpput vector returned from function, read from external file 
	std::vector<std::string> myInput;
	readVectorFromFile(myInput);

	//Example input
	//std::vector<std::string> myInput = { "#1 @ 5, 5: 2x2",
	//	"#2 @ 5, 5: 2x2",
	//	"#3 @ 5, 5: 2x2",
	//	"#4 @ 5, 5: 2x2" };

	// Entries read from string
	std::vector<int> posX;
	std::vector<int> posY;

	std::vector<int> width;
	std::vector<int> heigth;

	std::vector<int> index;

	//Loop through input vector and disentangle string
	int k = 0;
	for (std::vector<std::string>::iterator i = myInput.begin(); i != myInput.end(); i++) {

		std::string subset = *i;
		std::string position;

		int index1 = subset.find("@") + 2;
		int index2 = subset.find(":");
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

	// create the matrix for the patches with the maximum size needed: 
	// largest Position with largest rectangle size (as worst case)
	std::vector<int> largestWidth = width;
	std::vector<int> largestHeigth = heigth;
	std::sort(largestWidth.begin(), largestWidth.end(), std::greater<int>());
	std::sort(largestHeigth.begin(), largestHeigth.end(), std::greater<int>());
	std::vector<int> posXLargest = posX;
	std::vector<int> posYLargest = posY;
	std::sort(posXLargest.begin(), posXLargest.end(), std::greater<int>());
	std::sort(posYLargest.begin(), posYLargest.end(), std::greater<int>());

	std::vector<std::vector<int>> fabricMatrix(largestWidth[0]+ posXLargest[0], 
		std::vector<int>(largestHeigth[0] + posYLargest[0]));

	// Increase the number in patch matrix for each single patch positioned on it
	for (int line = 0; line < myInput.size(); line++) {
		for (int x = posX[line]; x < posX[line] + width[line]; x++) {
			for (int y = posY[line]; y < posY[line] + heigth[line]; y++) {
				fabricMatrix[x][y]++;
			}
		}
	}

	// Check for all Patches with more than one contributor
	int sum = 0;
	for (int i = 0; i < fabricMatrix.size(); i++) {
		for (int j = 0; j < fabricMatrix[0].size(); j++) {
			int result = fabricMatrix[i][j];
			if (result >1) {
				sum++;

			}
		}
	}
	//Result
	std::cout << sum << std::endl;

	/* Day 3 part 2 :
	- return the only complete patch not overlapping with any other patch
	*/
	// if any of the patch parts is part of any other patch (value larger than one),
	// boolean is set to false, only one true result remains.

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