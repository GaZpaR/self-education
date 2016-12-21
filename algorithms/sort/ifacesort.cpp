#include "ifacesort.h"
#include "timeestimator.hpp"
#include <string>
#include <fstream>

void sorter::createUnsortedArray(uint8_t arrayCreateMethod, std::string file){
	if(size < 2){
		std::cout << "Size of array is less the 2. There is nothing to sort" << std::endl;
		return;
	}

	switch(arrayCreateMethod){
		case MANUALLY:{
			std::cout << "MANUAL method to create unsorted array" << std::endl;
			for(uint i=0; i < size; i++) std::cin >> ptr[i];
      break;
		}

		default:
			std::cout << "Unknown type to create unsorted array...choose:" << std::endl;
		case SOFTWARE:{
			std::cout << "SOFTWARE method to create unsorted array" << std::endl;
			for(uint32_t i=0; i < size; i++) ptr[i] = 1000*(1.0*rand()/RAND_MAX);
			break;
		}

		case FROM_FILE:{
			std::cout << "FROM_FILE method to create unsorted array" << std::endl;
			std::ifstream array;
			array.open(file);
			if(array.is_open()){
				for(uint32_t i=0; i < size; i++){
					char *numstr = new char[64];
					array.getline(numstr, 64);
					ptr[i] = (int) std::stod((std::string)numstr);
					delete[] numstr;
				}
				array.close();
			}
			else{
				std::cout << "Can't open file: " << file << " with array nubers." << std::endl;
			}
			break;
		}
	}
}

void sorter::writeArrayToFile(std::string filename){
	std::ofstream sorted;
  sorted.open (filename);
  if (sorted.is_open()) {
    for(uint32_t i=0; i < size; i++)
			sorted << std::to_string(ptr[i]) << std::endl;
    std::cout << "Wrote to the file: " << filename << "." << std::endl;
    sorted.close();
  }
  else 
	  std::cout << "Error opening file. Print result in terminal.";
}

void sorter::printArray(void){
	std::cout << "Array is:" << std::endl;
	for(uint32_t i=0; i < size; i++)
		std::cout << std::to_string(ptr[i]) << '\t';
	std::cout << std::endl;
}

void sorter::sort(void (*func)(int *a, uint32_t start, uint32_t max)){
	mTim _tim;
	_tim.mStart();
	func(ptr, 0, size - 1);
	_tim.mStop();
	spendedTime = std::to_string(_tim.value());
}

std::string sorter::getSpendedTime(void){
	return spendedTime;
}
