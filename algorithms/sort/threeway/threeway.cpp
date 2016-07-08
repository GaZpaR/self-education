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

#define ch(A) digit(A, d)
template<class Item>
void msd3way(Item a[], int l, int r, int d){
	int i, j, k, p, q, v;

	if(r-l <= M){insertion(a, l, r); return;}

	v = ch(a[r]);
	i = l-1;	j = r;
	p = l-1;	q = r;
	while(i<j){
		while(ch(a[++i]) < v);
		while(v < ch(a[--j])) if(j == l) break;
		if(i>j) break;
		exchange(a[i], a[j]);
		if(ch(a[i]) == v){p++; exchange(a[p], a[i]);}
		if(v == ch(a[j])){q--; exchange(a[q], a[j]);}
	}

	if(p == q){
		if(v != '\0') msd3way(a, l, r, d+1);
		return;
	}

	if(ch(a[i]) < v) i++;
	for(k=l; k <= p; k++, j--) exchange(a[k], a[j]);
	for(k=r; k >= q; k--, i++ ) exchange(a[k], a[i]);
	msd3way(a, l, r, d);
	if((i == r) && (ch(a[i]) == v)) i++;
	if(v != '\0') msd3way(a, j+1, i-1, d+1);
	msd3way(a, i, r, d);

}

template<class Item>
void sort(Item a[],  int l, int r){
	msd3way<Item>(a, l, r, 0);
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
		for(i=0; i < N; i++) a[i] = 60*(1.0*rand()/RAND_MAX);
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
