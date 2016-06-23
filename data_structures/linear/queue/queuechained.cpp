#include <iostream>
#define QUEUE_MAX_SIZE 28

template<typename contenttype>
class queue
{
private:
	struct node{
		node *linkprev, *linknext;
		contenttype content;
	};
	node *head, *tail;
	uint queusize;
public:
	queue(){
		tail = new node;
		head = tail;
		head->linkprev = tail;
		head->linknext = tail;
		tail->linkprev = head;
		tail->linknext = head;
		queusize = 0;
	}
	~queue(){
	}

	void push(contenttype el){
		if(queusize<QUEUE_MAX_SIZE){
			node *tnode = new node;
			tnode->content = el;
			tail->linknext = tnode;
			tnode->linkprev = tail;
			tail = tnode;
			queusize++;
		}
		else std::cout<< std::endl << "Queue is full" << std::endl;
	}

	contenttype pop()
	{

		if(head != tail){
			contenttype ret = head->linknext->content;
			head->linknext->linkprev = head->linknext;
			node *tnodep = head;
			head = head->linknext;
			delete tnodep;
			queusize--;
			return ret;
		}
		else{
			std::cout<< std::endl << "Queue is empty" << std::endl;
			return NULL;
		}
	}

};
int main()
{
	queue<uint> q;
	for(uint i=0; i<34; i++){
		std::cout << i << " ";
		q.push(i);
	}
	std::cout<<std::endl;
	for(uint i=0; i<32; i++){
		std::cout << q.pop() << " ";
	}
	std::cout<<std::endl;
	std::cout<<"Fuck you!"<<std::endl;
	return 0;
}
