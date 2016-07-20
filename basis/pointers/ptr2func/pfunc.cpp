#include <iostream>

double fltodouble(float num){
	return (double)num;
}

int main(int argc, char **argv){
	double (*fd)(float) = fltodouble;
	float val = 22.4;
	std::cout<<"float val= "<< val << std::endl;
	std::cout<<"double val=" << fd(val) << std::endl;
	return 0;
}
