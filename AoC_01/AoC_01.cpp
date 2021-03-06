// AoC_01.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <map>
#include <vector>
#include "readInput.h"



int main()
{
	/* Task 1 : 
	Read Input from textfile, add content together 
	*/

	std::vector<int> temp;
	readVectorFromFile(temp);

	int sum = 0;
	for (std::vector<int>::iterator i = temp.begin(); i != temp.end(); i++) {
		sum = sum + *i;
	}
	//std::cout << sum << std::endl;

	/* Task 2 :
	Find the first value that is reached twice while traversing the vector
	*/

	std::map<int, bool> myFrequencies;

	int frequency = 0;
	bool bFlag = false;
	int loop = 0;

	while (bFlag == false){
		for (std::vector<int>::iterator i = temp.begin(); i != temp.end(); i++) {
			frequency = frequency + *i;
			if (myFrequencies[frequency] == true) {
				std::cout << "Result: " << frequency << std::endl;
				bFlag = true;
				std::cin.get();
				return 0;
			}
			else {
				myFrequencies[frequency] = true;
			}
		}
		loop++;
	}

    return 0;
}



