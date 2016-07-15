#include <iostream>
class Base
{
public:
	Base()
	{
		base_func();
	}
	void base_func()
	{
		func(); // pure virtual function call exception
	}
	virtual void func() = 0;
};

class Derived : public Base
{
	public:
	virtual void func()
	{
		std::cout<<"This is call of pure virtual function"<<std::endl;
	}
};

int main(int argc, char **argv)
{
	std::cout<<"Creating Base object"<<std::endl;

	Derived *someobj = new Derived;	

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
