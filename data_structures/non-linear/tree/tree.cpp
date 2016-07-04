#include "tree.h"
#include <stdbool.h>

int main()
{
	std::cout<<"Hello, this is tree example!"<<std::endl;

	std::string somestr("Ou sheet!");
	Tree<std::string> sometree(somestr);

	Node<std::string> s("s");

	Node<std::string> s1("s1");
	Node<std::string> s2("s2");
	Node<std::string> s3("s3");

	Node<std::string> s21("s21");
	Node<std::string> s22("s22");
	Node<std::string> s23("s23");

	Node<std::string> s31("s31");
	Node<std::string> s311("s311");
	Node<std::string> s3111("s3111");



		sometree.appendNode(&s);
		sometree.appendNode(&s1);
		sometree.appendNode(&s2);
		sometree.appendNode(&s3);

		sometree.appendNode(s2, &s21);
		sometree.appendNode(s2, &s22);
		sometree.appendNode(s2, &s23);

		sometree.appendNode(s3, &s31);
		sometree.appendNode(s31, &s311);
		sometree.appendNode(s311, &s3111);

		sometree.traverseTree(sometree.getRoot(),
		// Lambda expression begins
			[](Node<std::string> *pN) {std::cout<<pN->getContent()<<std::endl;}
		// end of lambda expression
		);

	std::cout<< "Bye bye!" <<std::endl;
	return 0;
}
