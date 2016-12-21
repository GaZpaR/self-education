#include <iostream>
#include "ifacesort.h"

#define DEFAULT_QUEUE_SIZE 256

template<class Item>
void exchange(Item &A, Item &B){
	Item temp = A;
	A = B;
	B = temp;
}

template<class T>
void fixUp(T a[], int k){
	while(k>1 && a[k/2] < a[k]){
		exchange(a[k], a[k/2]);
		k = k/2;
	}
}

template<class T>
void fixDown(T a[], int k, int N){
	while(2*k <= N){
		int j=2*k;
		if(j<N && a[j] < a[j+1]) j++;
		if(!a[k] < a[j]) break;
		exchange(a[k], a[j]);
		k = j;
	}
}

template<class T>
class pqueue
{
private:
	T *queue_;
	int N;
public:

	pqueue(uint32_t size = DEFAULT_QUEUE_SIZE+1){
		queue_ = new T[size+1];
		N = DEFAULT_QUEUE_SIZE;
	}

	~pqueue(){
		delete[] queue_;
	}

	int empty() const{
		return N == 0;
	};

	void insert(T item){
		queue_[++N] = item;
		fixUp(queue_, N);
	}

	T getmax(){
		exchange(queue_[1], queue_[N]);
		fixDown(queue_, 1, N-1);
		return queue_[N--];
	};
};

template<class T>
void simplesort(T a[], int l, int r){
	int k;
	pqueue<T> pq(r-l+1);
	for(k=l; k<=r; k++) pq.insert(a[k]);
	for(k=r; k>=l; k--) a[k] = pq.getmax();
}

template<class T>
void heapsort1(T a[], int l, int r){
	int k, N=r-l+1;
	T *pq=a+l-1;
	for(k=N/2; k>=1; k--)
		fixDown(pq, k, N);
	while(N>1){
		exchange(pq[1], pq[N]);
		fixDown(pq, 1, --N);
	}
}

template<class T> void SiftDown(T* const heap, int i, int const n)
{
	int nMax(i);

	T const value(heap[i]);

	while (true)
	{
		int childN( i*2+1 );
		if ((childN < n) && (heap[childN] > value))
		  nMax = childN;

		++childN;
		if ((childN < n) && (heap[childN] > heap[nMax]))
		  nMax = childN;
		if (nMax == i) break;
		heap[i] = heap[nMax]; heap[nMax] = value;
		i = nMax;

	};
}

template<class T>
void heapsort(T* const heap, int n)
{
	for(int i(n/2-1); i>=0; --i) SiftDown(heap, i, n);
		while( n > 1 )
		{
			--n;
			exchange(heap[0], heap[n]);
			SiftDown(heap, 0, n);
		}
}

void sort(int *a, uint32_t m, uint32_t j){
	heapsort(a, j+1);
}

void help(void);

int main(int argc, char **argv)
{
	if(argc < 3 || argc > 5){
		help();
		return -1;
	}
	void (*sf)(int*, uint32_t, uint32_t) = sort;
	sorter *sp;
	switch(argc){
		case 5:{
			sp = new sorter(atoi(argv[1]), atoi(argv[2]), argv[3]);
			sp->sort(sf);
			sp->writeArrayToFile(argv[4]);
			break;
		}
		default:{
			sp = new sorter(SOFTWARE, atoi(argv[2]));
			sp->printArray();
			sp->sort(sf);
			sp->printArray();
			break;
		}
	}
	std::cout << "time: "<< sp->getSpendedTime() << std::endl;
	delete sp;
	return 0;
}

void help(void){
	std::cout << "Wrong usage!!!" << std::endl;
	std::cout << "Arguments: ['inputArrayType' 'arraySize' 'inputArrayFile' 'outputArrayFile']" << std::endl;
	std::cout << "inputArrayTypes: 0- manual input; 1- create array using rand(); 2- read array from file." << std::endl;
	std::cout << "Examples:" << std::endl;
	std::cout << "./sort 1 69" << std::endl;
	std::cout << "./sort 2 100 \"unsorted_array\" \"sorted_array\"" << std::endl;
}
