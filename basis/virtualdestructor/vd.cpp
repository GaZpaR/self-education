#include <iostream>

class Base
{
public:
	virtual ~Base()
	{
		std::cout << "Hello from ~Base()" << std::endl;
	}
};

class Derived : public Base
{
public:
	virtual ~Derived()
	{
		// Здесь могла бы быть очистка ресурсов
		std::cout << "Hello from ~Derived()" << std::endl;
	}
};


int main(int argc, char **argv)
{
	Base *obj = new Derived();
	delete obj;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
