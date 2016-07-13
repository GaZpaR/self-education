#include <iostream>

int ustrtohash(char *str, int M){
	int h=0, a = 31425, b = 27183;
	for(; *str != '\0'; str++, a = a*b%(M-1)){
		h = (a*h + *str)%M;
	}
	return (h<0)?(h+M):h;
}

int strtohash(char *str, int M){
	int h=0, a = 127;
	for(; *str != '\0'; str++){
		h = (a*h + *str)%M;
	}
	return h;
}

int main(int argc, char **argv)
{
	char str1[] = "sukafromforest";
	std::cout<<"Convert str1: \""<<str1<< "\" is: "<<  strtohash(str1, 500)<< std::endl;
	std::cout<<"uConvert str1: \""<<str1<< "\" is: "<<  ustrtohash(str1, 500)<< std::endl;

	char str2[] = "hellomylittlepony";
	std::cout<<"Convert str2: \""<<str2<< "\" is: "<<  strtohash(str2, 500)<< std::endl;
	std::cout<<"uConvert str2: \""<<str2<< "\" is: "<<  ustrtohash(str2, 500)<< std::endl;

	char str3[] = "somehowisawsaw";
	std::cout<<"Convert str3: \""<<str3<< "\" is: "<<  strtohash(str3, 500)<< std::endl;
	std::cout<<"uConvert str3: \""<<str3<< "\" is: "<<  ustrtohash(str3, 500)<< std::endl;

	std::cout<<"\n Bye bye!!!\n";
	return 0;
}
