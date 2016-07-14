#include <iostream>

typedef struct
{
	int n1;
	mutable int n2;
} A;

// whether foo is declared noexcept depends on if the expression
// T() will throw any exceptions
template <class T>
  void foo() noexcept(noexcept(T())) {}

void bar() noexcept(true) {}
void baz() noexcept { throw 42; }  // noexcept is the same as noexcept(true)

int main(int argc, char* argv[])
{
	const A a = {.n1 = 5, .n2 = 15};
	//a.n1 = 2; // It will cause error
	std::cout<<"a.n2="<<a.n2<<std::endl;

	a.n2 = 2;// It's all right
	std::cout<<"a.n2="<<a.n2<<std::endl;

	foo<int>();  // noexcept(noexcept(int())) => noexcept(true), so this is fine

	bar();  // fine
	baz();  // compiles, but at runtime this calls std::terminate

	std::cout<<"End program. Bye, Bye!"<<std::endl;
	return 0;
}
