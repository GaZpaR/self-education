#include <iostream>
#include <string.h>

struct Node{
	int payloadsize;
	char content[1];
};

int main(int argc, char **argv){
	char *buffer = new char[256];

	char str[] = "Hello my friend";
	int val = sizeof(str);
	
	memcpy(buffer, &val, sizeof(int));
	memcpy(&buffer[4], str, sizeof(str));

	Node *some = (Node*)buffer;

	std::cout<< "payloadsize is: " << some->payloadsize << std::endl;
	std::cout<< "content is: " << some->content << std::endl;
	return 0;
}
