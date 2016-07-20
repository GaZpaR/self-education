#include <iostream>
#include <memory>
#include <thread>

std::unique_ptr<int> some(new int);
std::unique_ptr<bool> e(new bool);


void func1(void){
	while(*e){
		std::cout << "f1: "<< *some << std::endl;
		(*some)--;
	}
};

void func2(void){
	while(*e){
		std::cout << "f2: "<< *some << std::endl;
		(*some)++;
	}

}

bool f = true;
volatile int cnt = 1000;

void func21(){
	while(f){
		std::cout<< "11111" << std::endl;
		cnt--;
		if(cnt <= 0) f = false;
	}
	*e = false;
}

void func22(){
	while(f){
		std::cout<< "22222" << std::endl;
		cnt--;
		if(cnt <= 0) f = false;

	}
	*e = false;
}

int main(int argc, char **argv){
	*e = true;
	std::cout<< "This prog example of usage smart pointers" << std::endl;
	std::thread t1(func1), t2(func2), t3(func21), t4(func22);

	*some = 633;
	std::cout<<*some<<std::endl;
	*some = 256;
	std::cout<<*some<<std::endl;
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
