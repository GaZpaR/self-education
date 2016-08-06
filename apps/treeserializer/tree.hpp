#include <iostream>
#include <string.h>
#include <vector>

#include "nodes.hpp"

class Tree{
	INode *root;
public:
	Tree(INode *n);
	Tree& operator=(const Tree &t);

	// Appending to the root
	void appendNode(INode *n);

	// Appending to the node
	void appendNode(INode &n, INode *c);

	void appendNode(INode *n, INode *c);

	void delNode(INode* n);

	INode* cutNode(INode *n);

	INode *getRoot();

	void* visit(INode *pN);

	void traverseTree(INode *pN, void (*F)(INode*, std::vector<std::string>&), std::vector<std::string> &v);

	void traverseTreeCP(INode *sN, Tree *dN, INode *lN);
};
