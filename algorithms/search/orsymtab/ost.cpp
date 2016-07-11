#include <iostream>


template<class T>
T power(T num, T pow){
	if(pow==0)
		return 1;
	if(pow%2 == 1)
		return power(num, pow-1)*num;
	else{
		T b=power(num, pow/2);
		return b*b;
	}
}

int main(int argc, char **argv)
{
	int
	a = atoi(argv[1]),
	pw = atoi(argv[2]);
	std::cout<<a<<std::endl;
	std::cout<<pw<<std::endl;
	if(pw == (int)NULL) pw = 0;
	if(a ==(int)NULL) a = 0;

	std::cout<<"Result of power is: "<<power<int>(a, pw)<<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
