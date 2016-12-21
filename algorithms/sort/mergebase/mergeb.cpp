#include <iostream>
#include "ifacesort.h"

template<class Item>
void exchange(Item &A, Item &B){
	Item temp = A;
	A = B;
	B = temp;
}

template<class Item>
int partition(Item a[], int l, int r){
	Item x = a[r];
	int i = l;
	if(l > 0) i -=1;
	for (int j = l; j < r; j++)
	{
		if (a[j] <= x)
		{
			i++;
			if(i != j)exchange<Item>(a[i], a[j]);
		}
	}
	exchange<Item>(a[r], a[i+1]);

	return i + 1;
};

template<class Item>
void sort(Item a[], uint32_t l, uint32_t r){
	int q;
	if (l < r)
	{
		q = partition (a, l, r);
		sort (a, l, q-1);
		sort (a, q+1, r);
	}
}

// Merge
template<class Item>
void merge(Item merged[], Item a[], int aq, Item b[], int bq){
	for(int i=0, j=0, k=0; k<aq+bq; k++){
		if(i == aq){ merged[k] = b[j++]; continue;}
		if(j == bq){ merged[k] = a[i++]; continue;}
		merged[k] = (a[i] < b[j]) ? a[i++] : b[j++];
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
