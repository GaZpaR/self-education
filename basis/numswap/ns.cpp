#include <iostream>

void swap(int& a, int& b) {

	a = a ^ b; // a = 101^110 = 011
	b = a ^ b; // b = 011^110 = 101
	a = a ^ b; // a = 011^101 = 110

	std::cout<<"a: "<< a<<std::endl;
	std::cout<<"b: " << b<<std::endl;
}

int main(int argc, char **argv)
{
	int a = 15, b = 42;
	std::cout<<"a="<<a<<std::endl;
	std::cout<<"b="<<b<<std::endl;

	swap(a, b);
	int f = 17;
	std::cout<<"a="<<a<<std::endl;
	std::cout<<"b="<<b<<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
