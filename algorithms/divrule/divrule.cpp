#include <iostream>

template<typename T>
T max(T N[], int l, int r){
	if(l == r) return N[l];
	int m = (l+r)/2;
	T u = max(N, l, m);
	T v = max(N, m+1, r);
	return (u > v)? u : v;
}

int main(int argc, char **argv){
	if(argc < 1) return -1;
	int i, N = atoi(argv[1]);
	if(N<2) return -2;

	int *a = new int[N];

	std::cout<<"Software way to create arbitary array"<<std::endl;
	for(i=0; i < N; i++) a[i] = 200*(1.0*rand()/RAND_MAX);
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<std::endl;

	std::cout<< "The maximum value is: "<<max(a, 0, N-1)<<std::endl;

	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
