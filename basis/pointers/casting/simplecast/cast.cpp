#include <iostream>
#include <string.h>

struct Node{
	int payloadsize;
	char content[1];
};

int AA[3][4] = {
	1, 2, 3, 3, 
	2, 1,	4, 3,
	5, 5, 4, 3
};

int main(int argc, char **argv){
	char *buffer = new char[256];

	char str[] = "Hello my friend";
	int val = sizeof(str);
	
	memcpy(buffer, &val, sizeof(int));
	memcpy(&buffer[4], str, sizeof(str));

	Node *some = (Node*)buffer;

	std::cout << AA[1][1] << " - " << *(*(AA + 1)+ 1) << std::endl;

	std::cout<< "payloadsize is: " << some->payloadsize << std::endl;
	std::cout<< "content is: " << some->content << std::endl;
	return 0;
}
