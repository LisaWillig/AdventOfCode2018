#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "readInput.h"

int main() {

	/* Day 2 part 1 :
		- Find exactly repeated chars in one string: 2x anf 3x repetition per string.
		- Count Checksum of these:
		checksum = checkTwo * checkThree
	*/
	std::vector<std::string> myInput;
	readVectorFromFile(myInput);

	int checkTwo = 0;
	int checkThree = 0;

	for (std::vector<std::string>::iterator i = myInput.begin(); i != myInput.end(); i++) {

		std::map<char, int> checkHash;
		bool bTwoAlready = false;
		bool bThreeAlready = false;

		for (auto letter : *i) {
			checkHash[letter] = checkHash[letter] + 1;
		}
		for (auto const&x : checkHash) {
			if (x.second == 2 && bTwoAlready == false) {
				checkTwo++;
				bTwoAlready = true;
			}
			if (x.second == 3 && bThreeAlready == false) {
				checkThree++;
				bThreeAlready = true;
			}
		}
	}
	int checksum = checkTwo * checkThree;
	//std::cout << checksum;

	/* Day 2 part 2:
	- Find identical strings with one char different
	- print returning pattern
	*/
	for (std::vector<std::string>::iterator i = myInput.begin(); i != myInput.end(); i++) {
		for (std::vector<std::string>::iterator j = myInput.begin() + 1; j != myInput.end(); j++) {
			if (j > i){
			break;
			}
			std::string string1 = *i;
			std::string string2 = *j;

			int num = 0;
			std::string newString = "";

			for (int k = 0; k < string1.size(); k++) {
					if (string1[k] == string2[k]) {
						num++;
						newString.insert(newString.end(), string1[k]);
					}
			}
				if (num == string1.size()-1) {
					// Strings fullfilling the condition
					std::cout << *i << std::endl;
					std::cout << *j << std::endl;
					std::cout << std::endl;
					// Reoccuring Pattern
					std::cout << newString << std::endl;
				}
		}
	}
	std::cout << "Finished" << std::endl;
	std::cin.get();
	return 0;
}