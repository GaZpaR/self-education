#include <iostream>
#include "tree.h"



int main(int argc, char **argv){

	INode *root = new NodeInt(root, 77);

	NodeInt s(root, 363);
	NodeFl s1(&s, (float)228.8);
	NodeStr s2(&s, "s1");

	NodeFl s11(&s1, (float)37.6), s12(&s1, (float)84);

	NodeStr s21(&s2, "ABC"), s22(&s2, "BAC"), s23(&s2, "CAB");

	TreeT t(root);

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

	t.traverseTree(root,// Lambda expression begins
		[](INode *n) {
			switch(n->nodeType()){
				case INT: std::cout << *(int*)n->getContent() << std::endl; break;
				case FLOAT: std::cout << *(float*)n->getContent() << std::endl; break;
				case STR: std::cout << *(std::string*)n->getContent() << std::endl; break;
				default: std::cout << "Undefined Node content type" << std::endl; break;
			}
		}	// end of lambda expression
									);
	std::cout << "Bye bye!" << std::endl;
	return 0;
}
