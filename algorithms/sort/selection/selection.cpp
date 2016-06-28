#include <iostream>
#include <vector>
// Example from R. Sedgewick

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
void sort(Item array[], int n, int m){
	for(int i = n; i < m; i++){
		int min = i;
		for(int j=i+1; j<=m; j++){
			if(array[j] < array[min]) min = j;
		}
		exchange(array[i], array[min]);
	}
}

int main(int argc, char **argv)
{
	int i,
	N = atoi(argv[1]),
	SW = atoi(argv[2]);
	std::cout<<N<<std::endl;
	std::cout<<SW<<std::endl;
	int *a = new int[N];
	if(SW){
		std::cout<<"Software way to create unsorted array"<<std::endl;
		for(i=0; i < N; i++) a[i] = 1000*(1.0*rand()/RAND_MAX);
		for(i=0; i < N; i++) std::cout<<a[i]<<" ";
		std::cout<<std::endl;
	}
	else{
		std::cout<<"Manual way to create unsorted array"<<std::endl;
		N = 0;
		while(std::cin >> a[N]) N++;
	}
	sort(a, 0, N-1);
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
