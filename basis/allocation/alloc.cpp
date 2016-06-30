#include <iostream>
#include <string.h>

uint bitsalloc(int num, int start, int end){
	std::cout<< "Allocated base is: " << num << std::endl;
	std::cout<< "start bit is: " << start << std::endl;
	std::cout<< "end bit is: " << end << std::endl;
	uint retval = num;
	retval = retval << (32 - end);
	retval = retval >> (32 - end + start);
	return retval;
};

int main(int argc, char **argv){
	std::cout<< "This prog to allocate bits" << std::endl;
	int num = 0x0EAFFFCD;

	std::cout<< "Allocated num is " << bitsalloc(num, 0, 8) << std::endl;
	std::cout<< "Allocated num is " << bitsalloc(num, 8, 16) << std::endl;
	std::cout<< "Allocated num is " << bitsalloc(num, 16, 24) << std::endl;
	std::cout<< "Allocated num is " << bitsalloc(num, 24, 32) << std::endl;
	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
