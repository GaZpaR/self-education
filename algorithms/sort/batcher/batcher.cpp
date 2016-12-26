#include <iostream>
#include "ifacesort.h"

template<class Item>
void exchange(Item &A, Item &B){
	Item temp = A;
	A = B;
	B = temp;
}

template<class Item>
void cexchange(Item &A, Item &B){
	if( A < B) exchange(A, B);
}

template<class Item>
void shuffle(Item a[], int l, int r)
{
	int i, j, m=(r+l)/2;
	Item aux[r+2];
	for(i=l, j=0; i<=r; i+=2, j++){
		aux[i]=a[j+l];
		aux[i+1]=a[m+1+j];
	}
	for(i=l; i<=r; i++) a[i] = aux[i];
}

template<class Item>
void unshuffle(Item a[], int l, int r)
{
	int i, j, m=(r+l)/2;
	Item aux[r+2];
	for(i=l, j=0; i<=r; i+=2, j++){
		aux[l+j]=a[i];
		aux[m+1+j]=a[i+1];
	}
	for(i=l; i<=r; i++) a[i] = aux[i];
}

template<class Item>
void merge(Item a[], int l, int m, int r){
	if(r == l+1) cexchange(a[l], a[r]);
	if(r<l+2) return;
	unshuffle(a, l, r);
	merge(a, l, (l+m)/2, m);
	merge(a, m+1, (1+m+r)/2, r);
	shuffle(a, l, r);
	for(int i=l+1; i<r; i+=2) cexchange(a[i], a[i+1]);
}

inline int min(int A, int B){
	return (A<B)? A:B;
}

template<class Item>
void sort(Item a[], uint32_t l, uint32_t r){
	if(r<=1) return;

	int N=r-l+1;
	for(int p=1; p<N; p+=p)
		for(int k=p; k>0; k /=2)
			for(int j=k%p; j+k<N; j+=(k+k))
				for(int i=0; i<N-j-k; i++)
					if((j+i)/(p+p) == (j+i+k)/(p+p))
						cexchange(a[l+j+i], a[l+j+i+k]);
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
