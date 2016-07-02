#include <iostream>

class POINT{
private:
	int f;
public:

	POINT(){
		static int q = 0;
		q++;
		f = q;
	};
	~POINT(){
	};
	int point_quantity(){
		return f;
	};

};

int main(int argc, char **argv){
	{
		static POINT some;
		std::cout<< "Here we have "<< some.point_quantity()<< " points" << std::endl;
	}
	
	POINT *p = new POINT[600];

	std::cout<< "Here we have "<< p[599].point_quantity()<< " points" << std::endl;

	std::cout<< "Bye Bye!" << std::endl;
	return 0;
}
