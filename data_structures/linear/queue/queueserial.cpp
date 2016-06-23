#include <iostream>

#define DEFAULT_QUEUE_SIZE 256

template<typename sometype>
class queue
{
private:
	sometype *queue_;
	uint head, tail, queusize;
public:
	queue(){
		head = 0;
		tail = 0;
		queue_ = new sometype[DEFAULT_QUEUE_SIZE];
		queusize = DEFAULT_QUEUE_SIZE;
	}
	queue(uint size){
		head = 0;
		tail = 0;
		if(size > 0)	queue_ = new sometype[size];
		else	std::cout << "Queue have 0 size" <<std:: endl;
		queusize = size;
	}
	~queue(){
		delete queue_;
	}

	void push(sometype el){
		if((tail - head) < queusize){
			queue_[tail%queusize] = el;
			tail++;
		}
		else std::cout << "Queue is full" << std::endl;
	}

	sometype pop()
	{

		if(head != tail){
			sometype el;
			el = queue_[head%queusize];
			head++;
			return el;
		}
		else{
			std::cout << "Queue is empty" << std::endl;
			return NULL;
		}
	}

};

int main()
{
	queue<uint> q(20);
	for(uint i=0; i<26; i++){
		std::cout << i << " ";
		q.push(i);
	}
	std::cout<<std::endl;
	for(uint i=0; i<27; i++){
		std::cout << q.pop() << " ";
	}
	std::cout<<std::endl;
	std::cout<<"Fuck you!"<<std::endl;
	return 0;
}
