#include <iostream>
#include <vector>
// Example from R. Sedgewick
// Quick sort- base variant
template<class Item>
void exchange(Item &A, Item &B){
	Item temp = A;
	A = B;
	B = temp;
}

template<class Item>
int partition(Item a[], int l, int r){
	Item x = a[r];
	int i = l - 1;

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
void sort(Item a[], int l, int r){
	int q;
	if (l < r)
	{
		q = partition (a, l, r);
		sort (a, l, q-1);
		sort (a, q+1, r);
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
		for(i=0; i < N; i++) a[i] = 200*(1.0*rand()/RAND_MAX);
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
