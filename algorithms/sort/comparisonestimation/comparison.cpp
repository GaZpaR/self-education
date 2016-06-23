#include <iostream>
#include <vector>

void comparisonsort(int *objset, int size);

int main(int argc, char **argv)
{
	int array[18] = {1, 15,3,7,2,8,9,0,6,4,34,5,6,7,546,34234,92};
	for(uint i=0; i < 18; i++) std::cout<< array[i] << std::endl;
	std::cout<< "Sort begin!"<< std::endl;
	comparisonsort(array, 18);
	std::cout<< "Sort end!"<< std::endl;
	return 0;
}

void comparisonsort(int *objset, int size)
{
	int *count = new int[size + 1];

	for(int i=size; i>0;  i--){
		for(int j=i-1; j>0;  j--){
			if(objset[i] < objset[j]) count[j]++;
			else count[i]++;
		}
	}
	for(int i=0; i < size; i++) std::cout<< count[i] << std::endl;
}
