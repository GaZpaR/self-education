#include <iostream>

#define DEFAULT_QUEUE_SIZE 256

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
	}

	T getmax(){
		int max = 0;
		for(int i=0; i<N; i++)
			if(queue_[max] < queue_[i]) max = i;
		T el = queue_[max];
		if(N>0){
			queue_[max] = queue_[N-1];
			queue_[N-1] = el;
			return queue_[N--];
		}
		else return (T)NULL;
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
