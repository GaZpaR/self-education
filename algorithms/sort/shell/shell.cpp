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
	int h;
	for(h=n; h<=(m-n)/9; h=3*h+1);
	for(; h>0; h/=3){
		for(int i = n+h; i<=m; i++){
			int j = i;
			Item v = array[i];
			while(j>n+h && v<array[j-h]){
				array[j] = array[j-h];
				j -= h;
			}
			array[j] = v;
		}

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
