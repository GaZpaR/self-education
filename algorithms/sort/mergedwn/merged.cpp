#include <iostream>
#include <vector>

// Merge
template<class Item>
void merge(Item merged[], Item a[], int aq, Item b[], int bq){
	for(int i=0, j=0, k=0; k<aq+bq; k++){
		if(i == aq){ merged[k] = b[j++]; continue;}
		if(j == bq){ merged[k] = a[i++]; continue;}
		merged[k] = (a[i] < b[j]) ? a[i++] : b[j++];
	}
}

template<class Item>
void sort(Item a[], int r){
	if(r<=1) return;
	if(r==2){
		if( a[0] > a[1] ) { Item const t(a[0]); a[0]=a[1]; a[1]=t; }
			return;
	}

	sort(a, r/2);
	sort(a + r/2, r - r/2);

	Item *t = new Item[r];
	merge(t, a, r/2, a + r/2, r - r/2);
	for(int i=0; i<r; i++) a[i] = t[i];
	delete t;
}



int main(int argc, char **argv)
{
	if(argc < 1) return -1;
	int i, N = atoi(argv[1]);
	if(N<2) return -2;

	std::cout<<N<<std::endl;

	int *a = new int[N];

	std::cout<<"Software way to create unsorted array a"<<std::endl;
	for(i=0; i < N; i++) a[i] = 200*(1.0*rand()/RAND_MAX);
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<std::endl;


	sort(a, N);

	std::cout<<"Sorted with merge array is:"<<std::endl;
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
