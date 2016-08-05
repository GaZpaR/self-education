#include "tree.hpp"

Tree::Tree(INode *n){
	root = n;
};

Tree::~Tree(){
	delete root;
};

// Appending to the root
void Tree::appendNode(INode *n){
	root->addChild(n);
	n->setCoordinates(1, root->getChildrenQ());
	n->setParent(root);
};

// Appending to the node
void Tree::appendNode(INode &n, INode *c){
	n.addChild(c);
	c->setCoordinates(n.getCoordinates().lev + 1, n.getChildrenQ());
	c->setParent(&n);
};

void Tree::appendNode(INode *n, INode *c){
	n->addChild(c);
	c->setCoordinates(n->getCoordinates().lev + 1, n->getChildrenQ());
	c->setParent(n);
};

void Tree::delNode(INode* n){
	INode *tn = n->getParent();

	uint i=0;

	while(i < tn->getChildrenQ()){
		if(tn->getChild(i) == n){
			tn->delChild(tn->getChild(i));
			// Shift children positions
			while(i < tn->getChildrenQ()){
				INode *p = tn->getChild(i);
				p->setCoordinates(p->getCoordinates().lev, p->getCoordinates().pos-1);
				i++;
			}
			return;
		}
		i++;
	}
	std::cout << "We can't delete unexist Node" << std::endl;
};

INode* Tree::cutNode(INode *n){
	INode *tn = n->getParent();

	uint i=0;

	while(i < tn->getChildrenQ()){
		if(tn->getChild(i) == n){
			INode *retNode = tn->getChild(i);
			tn->delChild(tn->getChild(i));
			return retNode;
		}
		i++;
	}
	// TODO
	// Here should code to order elements of subtree
	// which we get by cutNode() operation
	return (INode*)NULL;
};

INode* Tree::getRoot(){return root;};

void* Tree::visit(INode *pN){	return pN->getContent();}

void Tree::traverseTree(INode *pN, void (*F)(INode*, std::vector<std::string>&), std::vector<std::string> &v){
		F(pN, v);
		int cq = pN->getChildrenQ();
		// Job with content
		for(int i=0; i<cq; i++){
			traverseTree(pN->getChild(i), F, v);
		}
	};

