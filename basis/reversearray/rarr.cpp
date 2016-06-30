#include <iostream>

template<typename T>
void rarr(T array[], int size){
	if(size <= 0 ) {
		std::cout<< "Error: Invalid array size" << std::endl;
		return;
	}
	int stepsq = size/2;

	for(int i=0; i<stepsq; i++){
		T temp;
		temp = array[i];
		array[i] = array[size-i-1];
		array[size-i-1] = temp;
	}
};

int main(int argc, char **argv){
	int ar1[7] = {1, 2, 3, 4, 5, 6, 7};
	int ar2[6] = {1, 2, 3, 4 , 5, 6};

	std::cout<< "Right array with 7 elements" << std::endl;
	for(int i=0; i<7; i++) std::cout<<ar1[i]<< " ";
	std::cout<< std::endl;

	rarr<int>(ar1, 7);

	std::cout<< "Reverse array with 7 elements" << std::endl;
	for(int i=0; i<7; i++) std::cout<<ar1[i]<< " ";
	std::cout<< std::endl;


	std::cout<< "Right array with 6 elements" << std::endl;
	for(int i=0; i<6; i++) std::cout<<ar2[i]<< " ";
	std::cout<< std::endl;

	rarr<int>(ar2, 6);

	std::cout<< "Reverse array with 6 elements" << std::endl;
	for(int i=0; i<6; i++) std::cout<<ar2[i]<< " ";
	std::cout<< std::endl;

	rarr<int>(ar1, 0);
	rarr<int>(ar2, -5);

	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
