#define MAIN

#include "nodes.hpp"
#include "tree.hpp"

#include <iostream>
#include "serializer.hpp"
#include "deserializer.hpp"

int main(int argc, char **argv){
	if(argc < 3){
		std::cout << "There is not enough arguments" << std::endl;
		std::cout << "Example: ./bin \"inputtreefilename\" \"outputfiletreename\"" << std::endl;
		return -1;
	}
	
	std::string input(argv[1]), output(argv[2]);
	Tree t = deserializeTree(input);

	serializeTree(t, output);

	return 0;
}

