#include <iostream>

template<typename T>
T gcd(T m, T n){
	if(n == 0) return m;
	return gcd(n , m%n);
}

int main(int argc, char **argv){
	std::cout<< "This is recursively euklid algo!" << std::endl;

	std::cout<< "gcd of (46, 18)= "<< gcd(46, 18)<<std::endl;
	std::cout<< "gcd of (21, 379)= "<< gcd(21, 379)<<std::endl;
	std::cout<< "gcd of (644, 180000)= "<< gcd(644, 180000)<<std::endl;

	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
