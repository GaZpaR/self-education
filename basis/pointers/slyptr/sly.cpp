#include <iostream>
#include <string.h>

struct st{
	int b;
	float c;
	char s[20];
	float m[128];
	char l;
};

int main(int argc, char **argv){
	std::cout<< "b position is: " << (long)(&(((st*)(NULL))->b))<<std::endl;

	std::cout<< "c position is: " << (long)(&(((st*)(NULL))->c))<<std::endl;

	std::cout<< "s position is: " <<(long)((void*)(& (((st*)(NULL))->s)))<< std::endl;
	
	std::cout<< "m position is: " <<(long)(& (((st*)(NULL))->m))<< std::endl;

	std::cout<< "s position is: " <<(long)(& (((st*)(NULL))->l))<< std::endl;

	std::cout<< "Bye, bye!"  << std::endl;
	return 0;
}
