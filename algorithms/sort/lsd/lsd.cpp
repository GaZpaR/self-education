#include <iostream>
#include "ifacesort.h"

const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1<<bitsbyte;

template<class Item>
inline int digit(Item A, int B){
	return (A&((Item)1<<B) > 0)? 1: 0;
}

template<class Item>
void lsd(Item a[], int l, const int r){
	Item aux[r+1];
	for(int d=0; d<bytesword; d++){
		int i, j, count[R+1];

		for(j=0; j<R; j++) count[j] = 0;

		for(i=l; i<r; i++)
			count[digit(a[i], d) + 1]++;

		for(j=1; j<R; j++)
			count[j] += count[j-1];

		for(i=l; i<r; i++)
			aux[count[digit(a[i], d)]++] = a[i];

		for(i=l; i<r; i++) a[i] = aux[i];
	}
}

template<class Item>
void sort(Item a[],  uint32_t l, uint32_t r){
	lsd<Item>(a, l, r);
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
