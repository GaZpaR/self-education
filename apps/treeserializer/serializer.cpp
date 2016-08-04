#include <iostream>
#include <fstream>
#include "tree.h"
#include "serializer.hpp"

int main(int argc, char **argv){

	INode *root = new NodeInt(root, 77);

	NodeInt s(root, 363);
	NodeFl s1(&s, (float)228.8);
	NodeStr s2(&s, "s1");

	NodeFl s11(&s1, (float)37.6), s12(&s1, (float)84);

	NodeStr s21(&s2, "ABC"), s22(&s2, "BAC"), s23(&s2, "CAB");

	Tree t(root);

	t.appendNode(&s);
	t.appendNode(s, &s1);
	t.appendNode(s, &s2);
	t.appendNode(s1, &s11);
	t.appendNode(s1, &s12);

	t.appendNode(s2, &s21);
	t.appendNode(s2, &s22);
	t.appendNode(s2, &s23);

	t.appendNode(new NodeInt(root, 128));
	t.appendNode(new NodeStr(root, "Hello, drug!!"));
	
	std::vector<std::string> out;

	t.traverseTree(root,// Lambda expression begins
		[](INode *n, std::vector<std::string> &o) {
			NC cs = n->getCoordinates();


			std::cout << "level=" << cs.lev << ", position=" << cs.pos << ": ";
			std::string temps; 
			
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
	
	std::ofstream file;
	file.open("simpletree.txt");
	for(uint i=0; i<out.size(); i++)
		file<<out[i];
	file.close();

	std::cout << "Bye bye!" << std::endl;
	return 0;
}
