#include <iostream>

#define MAX (1024*1024)

template<class T>
class Item{
private:
	T keyval;
	float info;
public:
	Item(){
		keyval = MAX;
	}
	Item(int maxKey){
		keyval = maxKey;
	}

	T key(){
		return keyval;
	}

	int null(){
		return keyval == MAX;
	}

	void rand(){
		keyval = 1000*::rand()/RAND_MAX;
		info = 1.0*::rand()/RAND_MAX;
	}
	void show(std::ostream &os = std::cout){
		os <<keyval<<" "<<info<<std::endl;
	}
};

template<class T, class K>
class SymTab{
	SymTab(int);
	int count();
	T search(K);
	void insert(T);
	void remove(T);
	T select(int);
	void show(std::ostream&);
};


int main(int argc, char **argv)
{
	int
	a = atoi(argv[1]),
	pw = atoi(argv[2]);
	std::cout<<a<<std::endl;
	std::cout<<pw<<std::endl;
	if(pw == (int)NULL) pw = 0;
	if(a == (int)NULL) a = 0;

	//std::cout<<"Result of power is: "<<power<int>(a, pw)<<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
