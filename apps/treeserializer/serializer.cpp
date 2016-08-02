#include <iostream>
#include "tree.h"



int main(int argc, char **argv){
	if(argc>1){
		std::cout << "Hello, "<< argv[1] << "!" << std::endl;
	}
	else std::cout << "Hello, friend!!!" << std::endl;
	return 0;
}
