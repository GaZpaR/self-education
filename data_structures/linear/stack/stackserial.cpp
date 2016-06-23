#include <iostream>

#define STACK_DEFAULT_VALUE 256

template <typename sometype>
class stack{
private:
	sometype *stack_;
	int stacksize;
	int currentpos;
public:
	stack(){
		stack_ = new sometype[STACK_DEFAULT_VALUE];
		stacksize = STACK_DEFAULT_VALUE;
		currentpos = 0;
	}
	stack(int size){
		stack_ = new sometype[size];
		stacksize = size;
		currentpos = 0;
	}
	~stack(){
		delete stack_;
	}
	void push(sometype el){
		stack_[currentpos] = el;
		if(currentpos<stacksize) currentpos++;
		else std::cout << std::endl << "Stack is full" << std::endl;
	}

	sometype pop(){
		sometype ret = NULL;
		if(currentpos>0){
			currentpos--;
			ret = stack_[currentpos];
		}
		else std::cout << std::endl << "Stack is empty" << std::endl;

		return ret;
	}
};



int main()
{
	stack<int> st(60);
	for(int i=0; i<67; i++){
		 st.push(i*2);
		 std::cout<<" "<<i*2;
	 }
	 std::cout<<std::endl;

	 for(int i=0; i<61; i++){
 		 std::cout<<" "<< st.pop();
 	 }
	 std::cout<<std::endl;
	std::cout<<"This is stack example"<<std::endl;
	return 0;
}
