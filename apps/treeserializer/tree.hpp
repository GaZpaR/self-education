#include <iostream>
#include <string.h>
#include <vector>

#ifndef MAIN
#include "nodes.hpp"
#endif

class Tree{
	INode *root;
public:
	Tree(INode *n);

	~Tree();

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
};
