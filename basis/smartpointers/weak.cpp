#include <iostream>
#include <memory>
#include <thread>

std::shared_ptr<int> g(new int);
std::weak_ptr<int> p = g;
std::unique_ptr<bool> e(new bool);


void func1(void){
	std::shared_ptr<int> s = p.lock();
	if(s.get() == 0){
		while(*e){
			std::cout << "f1: "<< *s << std::endl;
			(*s)--;
		}
	}
};

void func2(void){
	std::shared_ptr<int> s = p.lock();
	if(s.get() == 0){
		while(*e){
			std::cout << "f2: "<< *s << std::endl;
			(*s)--;
		}
	}
};

bool f = true;
volatile int cnt = 20;

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
	std::shared_ptr<int> s = p.lock();
	*s = 633;
	std::cout<<*s<<std::endl;
	*s = 256;
	std::cout<<*s<<std::endl;
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
