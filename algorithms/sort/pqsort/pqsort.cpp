#include <iostream>

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
	pqueue(){
		queue_ = new T[DEFAULT_QUEUE_SIZE+1];
		N = DEFAULT_QUEUE_SIZE;
	}
	pqueue(int size){
		if(size > 0)	queue_ = new T[size+1];
		else	std::cout << "Queue have 0 size" <<std:: endl;
		N = 0;
	}
	~pqueue(){
		//delete queue_;
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

int main(int argc, char *argv[])
{
	if(argc < 1) return -1;
	int i, N = atoi(argv[1]);
	if(N<2) return -2;

	int *a = new int[N];

	std::cout<<"Software way to create unsorted array a"<<std::endl;
	for(i=0; i < N; i++) a[i] = 200*(1.0*rand()/RAND_MAX);
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<std::endl;


	simplesort(a, 0, N);

	std::cout<<"Sorted array with heap-ordered tree is:"<<std::endl;
	for(i=0; i < N; i++) std::cout<<a[i]<<" ";
	std::cout<<"\n Bye bye!!!\n";

	return 0;
}
