#include <iostream>
#include "ifacesort.h"

void sort(int *a, uint32_t l, uint32_t r){
	int *count = new int[r + 1];

	for(int i=0; i<r+1;  i++){
		for(int j=0; j<i;  j++){
			if(a[i] < a[j]) count[j]++;
			else count[i]++;
		}
	}

	int *t = new int[r + 1];

	for(uint32_t i=0; i<r+1; i++)
		t[i] = a[i];

	for(uint32_t i=0; i<r+1; i++)
		a[count[i]] = t[i];

	delete[] count, t;
}

void help(void);

int main(int argc, char **argv)
{
	if(argc < 3 || argc > 5){
		help();
		return -1;
	}
	void (*sf)(int*, uint32_t, uint32_t) = sort;
	sorter *sp;
	switch(argc){
		case 5:{
			sp = new sorter(atoi(argv[1]), atoi(argv[2]), argv[3]);
			sp->sort(sf);
			sp->writeArrayToFile(argv[4]);
			break;
		}
		default:{
			sp = new sorter(SOFTWARE, atoi(argv[2]));
			sp->printArray();
			sp->sort(sf);
			sp->printArray();
			break;
		}
	}
	std::cout << "time: "<< sp->getSpendedTime() << std::endl;
	delete sp;
	return 0;
}

void help(void){
	std::cout << "Wrong usage!!!" << std::endl;
	std::cout << "Arguments: ['inputArrayType' 'arraySize' 'inputArrayFile' 'outputArrayFile']" << std::endl;
	std::cout << "inputArrayTypes: 0- manual input; 1- create array using rand(); 2- read array from file." << std::endl;
	std::cout << "Examples:" << std::endl;
	std::cout << "./sort 1 69" << std::endl;
	std::cout << "./sort 2 100 \"unsorted_array\" \"sorted_array\"" << std::endl;
}
