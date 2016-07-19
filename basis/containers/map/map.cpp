#include <iostream>
#include <map>    // Lib to work with map
using namespace std;

int main()
{
	map <string,int> myFirstMap = {{ "Mother", 37 },
																{ "Father", 40 },///map explicitly initialized
																{ "Brother", 15 },
																{ "Sister", 20 }};

	// Output of first map
	for (auto it = myFirstMap.begin(); it != myFirstMap.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
	}

	char c;
	map <char,int> mySecondMap;
	for (int i = 0,c = 'a'; i < 5; ++i,++c)
	{
		mySecondMap.insert ( pair<char,int>(c,i) );
	}

	// Output of second map nonexplicit
	for (auto it = mySecondMap.begin(); it != mySecondMap.end(); ++it)
	{
		cout << (*it).first << " : " << (*it).second << endl;
	}
	return 0;
}
