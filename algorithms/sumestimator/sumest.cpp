#include <iostream>
#include <list>

int main(int argc, char **argv){
	int ar[15] = {0, 1, 2, 3, 4, 5, 6, 4, 4, 6 ,7, 3, 2, 8, 2};
	std::list<int> lst(ar, ar+15);

	std::cout << "Show input list" << std::endl;
	for(std::list<int>::iterator it=lst.begin(); it != lst.end(); it++){
		std::cout << "\t" << *it;
	}
	std::cout << std::endl;

	
	std::list<int>::iterator it=lst.begin();
	int val = *it;
	while(true){

		++it;
		if(it == lst.end()){
			if((val + (*it)) == 10){
				it = lst.erase(it);
			}
			break;
		}
	
		if((val + (*it)) == 10){
			it = lst.erase(it);
			it--;
		}
		else val = *it;


	}
	std::cout << "Show result list" << std::endl;
	for(std::list<int>::iterator tt=lst.begin(); tt != lst.end(); tt++){
		std::cout << "\t" << *tt;
	}
	std::cout << std::endl;

	
	std::cout << "Bye bye!" << std::endl;
	return 0;
}
