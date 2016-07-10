#include <iostream>

template<class Item>
void exchange(Item &A, Item &B){
	Item temp = A;
	A = B;
	B = temp;
}

template<class Item>
void cexchange(Item &A, Item &B){
	if( A < B) exchange(A, B);
}

template<class Item>
void shuffle(Item a[], int l, int r)
{
	int i, j, m=(r+l)/2;
	Item aux[r+2];
	for(i=l, j=0; i<=r; i+=2, j++){
		aux[i]=a[j+l];
		aux[i+1]=a[m+1+j];
	}
	for(i=l; i<=r; i++) a[i] = aux[i];
}

template<class Item>
void unshuffle(Item a[], int l, int r)
{
	int i, j, m=(r+l)/2;
	Item aux[r+2];
	for(i=l, j=0; i<=r; i+=2, j++){
		aux[l+j]=a[i];
		aux[m+1+j]=a[i+1];
	}
	for(i=l; i<=r; i++) a[i] = aux[i];
}

template<class Item>
void merge(Item a[], int l, int m, int r){
	if(r == l+1) cexchange(a[l], a[r]);
	if(r<l+2) return;
	unshuffle(a, l, r);
	merge(a, l, (l+m)/2, m);
	merge(a, m+1, (1+m+r)/2, r);
	shuffle(a, l, r);
	for(int i=l+1; i<r; i+=2) cexchange(a[i], a[i+1]);
}

inline int min(int A, int B){
	return (A<B)? A:B;
}

template<class Item>
void sort(Item a[], int l, int r){
	if(r<=1) return;

	int N=r-l+1;
	for(int p=1; p<N; p+=p)
		for(int k=p; k>0; k /=2)
			for(int j=k%p; j+k<N; j+=(k+k))
				for(int i=0; i<N-j-k; i++)
					if((j+i)/(p+p) == (j+i+k)/(p+p))
						cexchange(a[l+j+i], a[l+j+i+k]);
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
	sort<int>(a, 0, N-1);
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<"\n Bye bye!!!\n";
}
