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
void quicksortb(Item a[], int l, int r, int d){
	int i = l, j = r;
	if(r <= l || d > bitsword) return;
	while(j > i){
		while(digit(a[i], d) == 0 && (i<j)) i++;
		while(digit(a[j], d) == 1 && (j>i)) j--;
		exchange(a[i], a[j]);
	}
	if(digit(a[r], d) == 0) j++;
	quicksortb(a, l, j-1, d+1);
	quicksortb(a, j, r, d+1);
}

template<class Item>
void sort(Item a[],  int l, int r){
	quicksortb<Item>(a, l, r, 0);
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
