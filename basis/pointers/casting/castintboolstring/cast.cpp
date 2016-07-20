#include <iostream>
#include <string>

void print(int v)
{
    std::cout << "int:" << v << std::endl;
}

void print(bool v)
{
    std::cout << "bool:" << v << std::endl;
}

void print(std::string v)
{
    std::cout << "std::string:" << v << std::endl;
}


int main(int argc, char **argv){
	print((int)56);
	print((bool)true);
	print((std::string)"Hello world");

	print(1);
	print(true);
	print("Hello world");

	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
