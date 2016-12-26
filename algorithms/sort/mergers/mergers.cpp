#include <iostream>
#include <vector>

// Merge
template<class Item>
void merge(Item a[], int l, int m, int r){
	if(r<1)return;

	int i, j;
	Item *const p = new Item[r+1]; // Adding +1 element
	for(i = m+1; i>l; i--) p[i-1] = a[i-1];
	for(j = m; j<r; j++) p[r+m-j] = a[j+1];
	for(int k = l; k <= r; k++)
		if(p[j] < p[i])
			a[k] = p[j--];
		else
			a[k] = p[i++];
	delete p;
}

inline int min(int A, int B){
	return (A<B)? A:B;
}

template<class Item>
void sort(Item a[], int l, int r){
	if(r<=1) return;

	for(int m=1; m<r-l; m = 2*m){
		for(int i=l; i<=r-m; i += 2*m){
			merge(a, i, i+m-1, min(i+m+m-1, r));
		}
	}
}



int main(int argc, char **argv)
{
	if(argc < 1) return -1;
	int i, N = atoi(argv[1]);
	if(N<2) return -2;

	int *a = new int[N];

	std::cout<<"Software way to create unsorted array a"<<std::endl;
	for(i=0; i < N; i++) a[i] = 200*(1.0*rand()/RAND_MAX);
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<std::endl;


	sort(a, 0, N);

	std::cout<<"Sorted with merge array is:"<<std::endl;
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
