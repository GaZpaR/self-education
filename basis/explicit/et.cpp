#include <iostream>

class Foo
{
public:
  // single parameter constructor, can be used as an implicit conversion
  Foo (int foo) : m_foo (foo)
  {
  }

  int GetFoo () { return m_foo; }

private:
  int m_foo;
};

void DoBar (Foo foo)
{
  int i = foo.GetFoo ();
}


class Foo1
{
public:
  // single parameter constructor, can be used as an implicit conversion
  explicit Foo (int foo) : m_foo (foo)
  {
  }

  int GetFoo () { return m_foo; }

private:
  int m_foo;
};

void DoBar1 (Foo1 foo)
{
  int i = foo.GetFoo ();
}


int main()
{
	DoBar(41); // Here will be implicit argument construction of Foo class
	DoBar1(33); // This implicit argument construction of Foo1 class will cause compile error
	return 0;
}
