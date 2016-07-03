#include <iostream>

template<typename T>
T factorial(T N){
	if(N == 1) return N;
	return N*factorial(N-1);
}

int main(int argc, char **argv){
	std::cout<< "This is recursively factorial example!" << std::endl;

	std::cout<< "2!= "<< factorial(2)<<std::endl;
	std::cout<< "7!= "<< factorial(7)<<std::endl;
	std::cout<< "15!= "<< factorial(15)<<std::endl;

	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
