#include <iostream>

#define DEFAULT_QUEUE_SIZE 256

template<class T>
class pqueue
{
private:
	T *queue_;
	uint N;
public:
	pqueue(){
		queue_ = new T[DEFAULT_QUEUE_SIZE];
		N = DEFAULT_QUEUE_SIZE;
	}
	pqueue(uint size){
		if(size > 0)	queue_ = new T[size];
		else	std::cout << "Queue have 0 size" <<std:: endl;
		N = size;
	}
	~pqueue(){
		delete queue_;
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
		queue_[max] = queue_[N-1];
		queue_[N-1] = el;
		return queue_[N--];
	};
};

int main()
{
	pqueue<uint> q(20);
	
	std::cout<<"Bye bye!"<<std::endl;
	return 0;
}
