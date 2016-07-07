#include <iostream>

const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1<<bitsbyte;

template<class Item>
inline int digit(Item A, int B){
	return (A*((Item)1<<B) > 0)? 1: 0;
}

template<class Item>
void exchange(Item &A, Item &B){
	Item temp = A;
	A = B;
	B = temp;
}

template<class Item>
void comparisonexchange(Item &A, Item &B){
	if( A < B) exchange(A, B);
}

template<class Item>
void insertion(Item a[], int l, int r){
	for(int i = l+1; i <= r; i++){
		for(int j=i; j>=1; j--){
			comparisonexchange(a[j-1], a[j]);
		}
	}
}

#define M 55

#define bin(A) (l+count[A])
template<class Item>
void msd(Item a[], int l, int r, int d){
	int i, j, count[R+1];
	Item aux[r+1];

	if(d > bytesword) return;

	if(r-l <= M){	insertion(a, l, r);	return;	};

	for(j = 0; j < R; j++) count[j] = 0;

	for(i = l; i <= r; i++) count[digit(a[i], d)+1]++;

	for(j=1; j<R; j++) count[j] += count[j-1];

	for(i=l; i<= r; i++) aux[l+count[digit(a[i], d)]++] = a[i];

	for(i=l; i<= r; i++) a[i] = aux[i];

	msd(a, l, bin(0)-1, d+1);

	for(j=0; j < R-1; j++) msd(a, bin(j), bin(j+1)-1, d+1);
}

template<class Item>
void sort(Item a[],  int l, int r){
	msd<Item>(a, l, r, 0);
}

int main(int argc, char **argv)
{
	int i,

	N = atoi(argv[1]),
	SW = atoi(argv[2]);
	std::cout << R-1<<std::endl;
	std::cout<<N<<std::endl;
	std::cout<<SW<<std::endl;
	int *a = new int[N];
	if(SW){
		std::cout<<"Software way to create unsorted array"<<std::endl;
		for(i=0; i < N; i++) a[i] = 10000*(1.0*rand()/RAND_MAX);
		for(i=0; i < N; i++) std::cout<<a[i]<<" ";
		std::cout<<std::endl;
	}
	else{
		std::cout<<"Manual way to create unsorted array"<<std::endl;
		N = 0;
		while(std::cin >> a[N]) N++;
	}
	sort<int>(a, 0, N-1);
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
