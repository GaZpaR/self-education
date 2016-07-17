#include <iostream>
using namespace std;

class SomeClass
{
	int *ptr; // указатель на какой-либо участок памяти
public:

	SomeClass() //  конструктор
	{
		cout << "\nОбычный конструктор\n";
	}
	SomeClass(const SomeClass &obj)
	{
		cout << "\nКонструктор копирования\n";
	}
	~SomeClass()
	{
		cout << "\nДестркуктор\n";
	}
};
void funcShow(SomeClass object)
{
	cout << "\nФункция принимает объект, как параметр\n";
}

SomeClass funcReturnObject()
{
	SomeClass object;
	cout <<   "\nФункция возвращает объект\n";
	return object;
}

int main()
{
	setlocale(LC_ALL,"rus");

	cout << "1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	SomeClass obj1; // создаем объект класса

	cout << "2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	funcShow(obj1); // передаем объект в функцию

	cout << "3 - 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	funcReturnObject(); // эта функция возвращает объект

	cout << "5 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	SomeClass obj2 = obj1;  // инициализация объекта при создании

}
