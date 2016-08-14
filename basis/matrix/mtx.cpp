#include <iostream>

template<typename T>
void mtxeval(T *mtx[]){
	
}

int main(int argc, char **argv){
	if(argc < 3){
		std::cout << "Not enough args to ceate matrix" << std::endl;
		return -1;
	}
	uint x = std::stoi(argv[1]), y = std::stoi(argv[2]);

	std::cout << "x=" << x << ", y=" << y << std::endl;

	uint *MTX[x];
	for(uint i=0; i<x; i++)
		MTX[i] = new uint[y];

	mtxeval<uint>(MTX);

	std::cout << "Simple matrix evaluator" << std::endl;
	return 0;
}

