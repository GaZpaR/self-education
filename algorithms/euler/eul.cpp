#include <iostream>


template<class T>
T phi(T n){
	T result = n;
		for (int i=2; i*i<=n; ++i)
			if (n % i == 0) {
				while (n % i == 0)
					n /= i;
				result -= result / i;
			}
		if (n > 1)
			result -= result / n;
		return result;
}

int main(int argc, char **argv)
{
	int	a = atoi(argv[1]);
	std::cout<< a <<std::endl;
	if(a == (int)NULL) a = 0;

	std::cout<<"Euler num of: "<< a <<" is: "<< phi<int>(a) <<std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
