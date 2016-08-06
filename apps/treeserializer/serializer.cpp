#include <fstream>
#include "serializer.hpp"


void serializeTree(Tree t, std::string ofilename){
	std::cout << "SERIALIZER" << std::endl;
	std::vector<std::string> out;
	t.traverseTree(t.getRoot(),// Lambda expression begins
		[](INode *n, std::vector<std::string> &o) {
			NC cs = n->getCoordinates();

			std::cout << "level=" << cs.lev << ", position=" << cs.pos << ": ";
			
			std::string fe('{' + std::to_string(cs.lev) + '.' + std::to_string(cs.pos)+ ':');

			switch(n->nodeType()){
				case INT:
					fe += std::to_string(*(int*)n->getContent());
					std::cout <<  *(int*)n->getContent() << std::endl;
					break;
				case FLOAT:
					fe += std::to_string(*(float*)n->getContent());
					std::cout << *(float*)n->getContent() << std::endl;
					break;
				case STR:
					fe += (*(std::string*)n->getContent());
					std::cout << *(std::string*)n->getContent() << std::endl; 
					break;
				default: std::cout << "Undefined Node content type" << std::endl; break;
			}
			fe += "}";
			o.push_back(fe);
		}// end of lambda expression
	, out);

	std::cout << "Output vector size is: " << out.size() << std::endl;
	for(uint i=0; i<out.size(); i++)
			std::cout<<out[i];
	std::cout<<std::endl;

	std::ofstream file(ofilename);
	if(file.is_open()){
		for(uint i=0; i<out.size(); i++)
			file<<out[i];
		file.close();
	}
}
