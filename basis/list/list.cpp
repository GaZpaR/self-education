#include <iostream>
#include <list>     // Header with list
#include <iterator> // Header with iterators
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	list<int> myList; // Definition of empty list
	srand(time(NULL));

	for(int i = 0; i < 15; i++) {
		myList.push_back(rand()%20); //Adding new elements
	}

	cout << "List1: ";
	copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));

	myList.sort();   // Sort
	cout << "\nSorted list: ";
	copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));

	myList.unique();   // Deleting clones of elements
	cout << "\nList with unique elements: ";
	copy(myList.begin(), myList.end(), ostream_iterator<int>(cout," "));

	list<int> myList2; // Defining second list
	for(int i = 0; i < 15; i++) {
		myList2.push_back(rand()%20); // Adding elements to the list
	}

	cout << "\nList2: ";
	copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout," "));

	myList2.merge(myList);
	cout << "\nMerging lists: ";
	copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout," "));
	cout<<endl;
	return 0;
}
