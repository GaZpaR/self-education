#include <iostream>
#include "ifacesort.h"

template<class Item>
void exchange(Item &A, Item &B){
	Item temp = A;
	A = B;
	B = temp;
}

template<class Item>
void sort(Item a[], uint32_t n, uint32_t m){
	int step = 7;
	while (step > 0){
		for (int i = 0; i < (m - step); i++){
			int j = i;
			while (j >= 0 && a[j] > a[j + step]){
				int temp = a[j];
				a[j] = a[j + step];
				a[j + step] = temp;
				j--; 
			}
		}
		step = step / 2;
	}
}

void help(void);

int main(int argc, char **argv)
{
	if(argc < 3 || argc > 5){
		help();
		return -1;
	}
	void (*sf)(int*, uint32_t, uint32_t) = sort<int>;
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
