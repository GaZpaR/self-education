#include <iostream>

#define STACK_MAX_SIZE 256

template<typename contenttype>
struct node{
	node *linkprev, *linknext;
	contenttype content;
};

class stack{
private:
	node<int> *topstack, zeronode;
	int stacksize;
public:
	stack(){
		zeronode.linkprev = &zeronode;
		topstack = &zeronode;
		stacksize = 0;
	}
	~stack(){
	}
	void push(node<int> el){
		if(stacksize < STACK_MAX_SIZE){
			node<int> *tnode = new node<int>;
			*tnode = el;
			tnode->linkprev = topstack;
			topstack->linknext = tnode;
			topstack = tnode;
			stacksize++;
		}
		else std::cout<<std::endl<<"Stack is full"<<std::endl;
	}

	node<int> pop(){
		node<int> ret;
		if(stacksize>0){
			ret = *topstack;
			topstack->linkprev->linknext = topstack->linkprev;
			node<int> *tnodep = topstack;
			topstack = topstack->linkprev;
			delete tnodep;
			stacksize--;
		}
		else std::cout<<std::endl<<"Stack is empty"<<std::endl;
		return ret;
	}
};



int main()
{
	uint num = 258;
	stack lst;
	for(uint i=0; i<num; i++){
		node<int> some;
		some.content = i;
		std::cout<<i<<" ";
		lst.push(some);
	}
	std::cout<<std::endl;
	for(uint i=0; i<num+5; i++){
		node<int> some = lst.pop();
		std::cout<<some.content<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"This is stack example"<<std::endl;
	return 0;
}
