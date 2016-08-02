#include <iostream>
#include <string.h>
#include <vector>

class INode{
public:
	virtual ~INode();
	virtual void getContent(INode *n);
	virtual void setContent(void *p);
	virtual uint getChildrenQ(INode *n);
	virtual INode* getParent(INode *n);
	virtual INode* getChild(uint i);
};

class NodeInt: public INode{
private:
	int content;
	NodeInt *parent;
	std::vector<NodeInt *> children;
public:
	NodeInt(){};
	~NodeInt(){};
	NodeInt(NodeInt *p): parent(p){};
	NodeInt(NodeInt *p, int c): parent(p), content(c){};

	int getContent(){
		return content;
	};

	void setContent(int c){
		content = c;
	};

	uint getChildrenQ(){
		return children.size();
	};

	NodeInt *getChild(uint i){
		uint cq = children.size();
		return (cq > 0 && i < cq)? children.at(i) : (NodeInt *)NULL;
	};

	void addChild(NodeInt *pC){
		children.push_back(pC);
	}

	NodeInt *cutChild(NodeInt *p){
		NodeInt *c = p;
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
				 children.erase(children.begin()+i);
			};
		}
		return c;
	};

	void delChild(NodeInt *p){
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
				 children.erase(children.begin()+i);
			};
		}
	};

	NodeInt* getParent(NodeInt node){
		return node.parent;
	};

	void changeParent(NodeInt pnode){
		parent = &pnode;
	};

	
};

template<typename T>
class Node{
private:
	T content;
	Node<T> *parent;
	std::vector<Node<T> *> children;
public:

	Node(){};
	Node(Node<T> *par): parent(par){};
	Node(T val): content(val){};
	Node(Node<T> *par, T val): parent(par), content(val){};
	~Node(){};

	T getContent(){
		return content;
	};

	void setContent(T val){
		content = val;
	};

	uint getChildrenQ(){
		return children.size();
	};

	Node<T> *getChild(int i){
		int cq = children.size();
		return (cq > 0 && i <= cq)? children.at(i) : (Node<T> *)NULL;
	};

	void addChild(Node<T> *pC){
		children.push_back(pC);
	}

	Node<T> cutChild(Node<T> *p){
		Node<T> *c = p;
		for (int i=0; i<children.size(); i++){
			if(children.at(i) == p){
				 children.erase(children.at(i));
			};
		}
		return c;
	}

	void delChild(Node<T> *p){
		for (int i=0; i<children.size(); i++){
			if(children.at(i) == p){
				 children.erase(children.at(i));
			};
		}
	}

	Node<T> getParent(Node<T> node){
		return node.parent;
	};

	void changeParent(Node<T> pnode){
		parent = &pnode;
	};

};

template<typename T>
class Tree{
	Node<T> *root;
public:
	Tree(){
		root = new Node<T>(root);
	};
	Tree(T val){
		root = new Node<T>(root, val);
	};

	~Tree(){
		delete root;
	};

	// Appending to the root
	void appendNode(Node<T> *node){
		root->addChild(node);
	};

	// Appending to the node
	void appendNode(Node<T> &node, Node<T> *child){
		node.addChild(child);
	};

	void appendNode(Node<T> *node, Node<T> *child){
		node->addChild(child);
	};

	void delNode(Node<T> *node){
		Node<T> *tnode = node->getParent();

		uint i=0;

		while(i < tnode->children.size()){
			if(tnode->children[i] == &node){
				tnode->children.erase(tnode->children[i]);
				break;
			}
			i++;
		}
	};

	Node<T> cutNode(Node<T> *node){
		Node<T> *tnode = node->getParent();
		Node<T> retNode = NULL;

		uint i=0;

		while(i < tnode->children.size()){
			if(tnode->children[i] == &node){
				retNode = tnode->children[i];
				tnode->children.erase(tnode->children[i]);
				break;
			}
			i++;
		}

		return retNode;
	};

	Node<T> *getRoot(){
		return root;
	};

	T visit(Node<T> *pN){
		T c = pN->getContent();
		return c;
	}

	void traverseTree(Node<T> *pN, void (*F)(Node<T>*)){
		F(pN);
		int cq = pN->getChildrenQ();
		// Job with content
		for(int i=0; i<cq; i++){
			traverseTree(pN->getChild(i), F);
		}
	};
};
