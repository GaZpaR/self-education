#include <iostream>
#include "ifacesort.h"
// Example from R. Sedgewick

template<class Item>
void exchange(Item &A, Item &B){
	Item temp = A;
	A = B;
	B = temp;
}

template<class Item>
void comparisonexchange(Item &A, Item &B){
	if( A > B) exchange(A, B);
}
//#define SORTTYPE1
#define SORTTYPE2
//#define SORTTYPE3
template<class Item>
void sort(Item array[], uint32_t n, uint32_t m){
#ifdef SORTTYPE1
	for(int i = n+1; i <= m; i++){
		for(int j=i; j>=1; j--){
			comparisonexchange(array[j-1], array[j]);
		}
	}
#endif

#ifdef SORTTYPE2
	for(uint i = m; i > 0; i--){
		for(uint j=i; j < m+1; j++){
			comparisonexchange(array[j-1], array[j]);
			if(array[j-1] > array[j]) break;
		}
	}
#endif

#ifdef SORTTYPE3
	for(int i = m; i > n; i--) comparisonexchange(array[i-1], array[i]);
	for(int j=n+2; j<=m; j++){
		int f = j;
		Item v = array[j];
		while(v < array[f-1]){
			array[f] = array[f-1];
			f--;
		}
		array[f] = v;
	}
#endif
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
