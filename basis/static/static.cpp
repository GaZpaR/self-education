#include <iostream>
#include <string>
#include <vector>

class inherit{
public:
	virtual void print_hello() = 0;
};

class some_static: public inherit{
public:
	some_static set_new_handler(){
		some_static *ptr = (some_static*)malloc(sizeof(some_static));
		std::cout << "new_handler" << std::endl;
		return *ptr;
	};
	void print_hello();
};

void some_static::print_hello(){
	std::cout << "Hello!" << std::endl;
}

class child: public inherit{
public:
	void print_hello(){
		std::cout << "olleH!" << std::endl;
	}
};

class A {
public:
	A(){
		std::cout << "A" << std::endl;
	}
	~A(){
		std::cout << "~A" << std::endl;
	}
};

class B: public A {
public:
  B(){
		std::cout << "B" << std::endl;
	}
  ~B(){
		std::cout << "~B" << std::endl;
	}
};

class C: public A, B{
public:
	C(){
		std::cout << "C" << std::endl;
	}
	~C(){
		std::cout << "~C" << std::endl;
	}
};

int main(void){
	C c;
	some_static f;
	some_static *r = new some_static();
	r->print_hello();

	child m;
	f.print_hello();
	m.print_hello();
	return 0;
}
