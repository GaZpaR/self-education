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
//#define SORTTYPE1
//#define SORTTYPE2
#define SORTTYPE3
template<class Item>
void sort(Item array[], int n, int m){
#ifdef SORTTYPE1
	for(int i = n+1; i <= m; i++){
		for(int j=i; j>=1; j--){
			comparisonexchange(array[j-1], array[j]);
		}
	}
#endif

#ifdef SORTTYPE2
	for(int i = n+1; i <= m; i++){
		for(int j=i; j>=1; j--){
			comparisonexchange(array[j-1], array[j]);
			if(array[j-1] < array[j]) break;
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
