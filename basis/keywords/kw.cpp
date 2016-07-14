#include <iostream>

typedef struct
{
	int n1;
	mutable int n2;
} A;

int main(int argc, char* argv[])
{
	const A a = {.n1 = 5, .n2 = 15};
	//a.n1 = 2; // It will cause error
	std::cout<<"a.n2="<<a.n2<<std::endl;

	a.n2 = 2;// It's all right
	std::cout<<"a.n2="<<a.n2<<std::endl;
	
	std::cout<<"End program. Bye, Bye!"<<std::endl;
	return 0;
}
