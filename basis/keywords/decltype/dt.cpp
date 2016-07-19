#include <iostream>

int main(int argc, char **argv)
{
	std::cout<<"Software way to create unsorted array a"<<std::endl;
	int f = 17;
	std::cout<<"int f = "<<f<<std::endl;
	decltype(f) m = f;
	std::cout<<"decltype(f) m = "<<m<<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
