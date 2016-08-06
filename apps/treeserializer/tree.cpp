#include "tree.hpp"

Tree::Tree(INode *n){
	root = n;
};


Tree::Tree(const Tree &t){
	root = t.root;
};

Tree& Tree::operator=(const Tree &t){
	Tree *p = new Tree(t.root);
	traverseTreeCP(t.root, p);
};

Tree::~Tree(){
	delete root;
};

// Appending to the root
void Tree::appendNode(INode *n){
	root->addChild(n);
	//n->setCoordinates(1, root->getChildrenQ());
	n->setParent(root);
};

// Appending to the node
void Tree::appendNode(INode &n, INode *c){
	n.addChild(c);
	//c->setCoordinates(n.getCoordinates().lev + 1, n.getChildrenQ());
	c->setParent(&n);
};

void Tree::appendNode(INode *n, INode *c){
	n->addChild(c);
	//c->setCoordinates(n->getCoordinates().lev + 1, n->getChildrenQ());
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
	// Here should code to reorder elements of subtree
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

void Tree::traverseTreeCP(INode *sN, Tree *dN){
	//INode cel = *sN;

	static uint level = 0;
	level++;
	uint l = sN->getCoordinates().lev, p = sN->getCoordinates().pos;
/*
	if(l == 1){
		dN.appendNode(sN);
		level = l;
	}

	if(l == level){
		if(p>1)t.appendNode(sN->getParent(), dN.;
		else t.appendNode(sN, p);
		level = l;
	}

	if(l > level){
		t.appendNode(nodes[i-1], p);
		level = l;
	}	
	else{
		t.appendNode( nodes[i-1]->getParent()->getParent(), p);
		level = l;
	}

	uint chq = sN->getChildrenQ();
	if(chq > 0){
		for(uint i=0; i<chq; i++){
			dN->appendNode(sN->getChild(i));
		}
	}*/
	level--;
};

