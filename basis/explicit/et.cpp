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
	DoBar(41);
	DoBar1(33);
	return 0;
}
