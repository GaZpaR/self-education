#include <iostream>
#include <vector>

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

// Merge
template<class Item>
void merge(Item merged[], Item a[], int aq, Item b[], int bq){
	for(int i=0, j=0, k=0; k<aq+bq; k++){
		if(i == aq){ merged[k] = b[j++]; continue;}
		if(j == bq){ merged[k] = a[i++]; continue;}
		merged[k] = (a[i] < b[j]) ? a[i++] : b[j++];
	}
}

int main(int argc, char **argv)
{
	if(argc < 2) return -1;
	int i,
	N = atoi(argv[1]),
	M = atoi(argv[2]);
	std::cout<<N<<std::endl;
	std::cout<<M<<std::endl;
	int *a = new int[N];
	int *b = new int[M];

	std::cout<<"Software way to create unsorted array a"<<std::endl;
	for(i=0; i < N; i++) a[i] = 200*(1.0*rand()/RAND_MAX);
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<std::endl;

	std::cout<<"Software way to create unsorted array b"<<std::endl;
	for(i=0; i < M; i++) b[i] = 200*(1.0*rand()/RAND_MAX);
	for(i=0; i < M; i++) std::cout<<b[i]<<" ";
	std::cout<<std::endl;
	sort(a, 0, N-1);
	sort(b, 0, M-1);

	int *c = new int[N+M];

	merge<int>(c, a, N, b, M);

	std::cout<<"Merged array is:"<<std::endl;
	for(i=0; i < N + M; i++) std::cout<<c[i]<<" ";

	delete a, b, c;
	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
