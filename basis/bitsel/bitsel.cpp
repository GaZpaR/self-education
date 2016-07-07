#include <iostream>
#define bitsbyte 8
#define bytesword 4
#define R (1<<bitsbyte)

inline int digit(int A, int B){
	return (A << bitsbyte*(bytesword - B -1) & (R-1));
}

int main(int argc, char **argv){
	std::cout<< "This prog to allocate bits" << std::endl;
	int num = 0x0EAFFFCD;

	std::cout<< "Allocated num is " << digit(num, 0) << std::endl;
	std::cout<< "Allocated num is " << digit(num, 1) << std::endl;
	std::cout<< "Allocated num is " << digit(num, 2) << std::endl;
	std::cout<< "Allocated num is " << digit(num, 3) << std::endl;

	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
