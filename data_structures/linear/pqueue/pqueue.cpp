#include <iostream>

#define DEFAULT_QUEUE_SIZE 256

template<class T>
void fixUp(T a[], int k){
	while(k>1 && a[k/2] < a[k]){
		T t;
		a[k] = t;
		a[k] = a[k/2];
		a[k/2] = t;

		k = k/2;
	}
}

template<class T>
void fixDown(T a[], int k, int N){
	while(2*k <= N){
		int j=2*k;
		if(j<N && a[j] < a[j+1]) j++;
		if(!a[k] < a[j]) break;

		T t;
		a[k] = t;
		a[k] = a[j];
		a[j] = t;

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
		queue_ = new T[DEFAULT_QUEUE_SIZE];
		N = DEFAULT_QUEUE_SIZE;
	}
	pqueue(int size){
		if(size > 0)	queue_ = new T[size];
		else	std::cout << "Queue have 0 size" <<std:: endl;
		N = size;
	}
	~pqueue(){
		//delete queue_;
	}

	int empty() const{
		return N == 0;
	};

	void insert(T item){
		queue_[N++] = item;
		fixUp(queue_, N);
	}

	T getmax(){
		T el = queue_[1];
		queue_[1] = queue_[N];
		queue_[N] = el;
		fixDown(queue_, 1, N-1);
		return queue_[N--];
	};
};

int main()
{
	pqueue<int> q(20);
	for(int i=0; i<20; i++)
		q.insert(600*(1.0*rand()/RAND_MAX));
	for(int i=0; i<20; i++)
		std::cout<<q.getmax()<<" ";
	std::cout<<std::endl;

	std::cout<<"Bye bye!"<<std::endl;
	return 0;
}
