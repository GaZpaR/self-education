#include <iostream>

const int bitsword = 8;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1<<bitsbyte;

template<class Item>
inline int digit(Item A, int B){
	return (A*((Item)1<<B) > 0)? 1: 0;
}

template<class Item>
void lsd(Item a[], int l, const int r){
	Item aux[r+1];
	for(int d=bytesword-1; d>=0; d--){
		int i, j, count[R+1];

		for(j=0; j<R; j++) count[j] = 0;

		for(i=l; i<=r; i++)
			count[digit(a[i], d) + 1]++;

		for(j=1; j<R; j++)
			count[j] += count[j-1];

		for(i=l; i<=r; i++)
			aux[count[digit(a[i], d)]++] = a[i];

		for(i=l; i<=r; i++) a[i] = aux[i];
	}
}

template<class Item>
void sort(Item a[],  int l, int r){
	lsd<Item>(a, l, r);
}

int main(int argc, char **argv)
{
	int i,

	N = atoi(argv[1]),
	SW = atoi(argv[2]);
	std::cout << R-1<<std::endl;
	std::cout<<N<<std::endl;
	std::cout<<SW<<std::endl;
	char *a = new char[N];
	if(SW){
		std::cout<<"Software way to create unsorted array"<<std::endl;
		for(i=0; i < N; i++) a[i] = 0x16+60*(1.0*rand()/RAND_MAX);
		for(i=0; i < N; i++) std::cout<<a[i]<<" ";
		std::cout<<std::endl;
	}
	else{
		std::cout<<"Manual way to create unsorted array"<<std::endl;
		N = 0;
		while(std::cin >> a[N]) N++;
	}
	sort<char>(a, 0, N-1);
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
