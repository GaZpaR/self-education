#include <iostream>

void func(){
	try{
		throw 999;
	}
	
	catch(int c){
		std::cout<<"We catch exception: " << c << std::endl;
	}
}

int main(){
	std::cout<<"Usage example of try/catch" << std::endl;
	
	func();

	return 0;
}
