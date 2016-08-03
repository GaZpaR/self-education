#include <iostream>
#include <string.h>
#include <vector>

enum{
	INT = 0,
	FLOAT,
	STR
};

class INode{
public:
	// This func rets void*
	// which should be casted to user defined type
	virtual void* getContent() = 0;
	
	// This funcs setting nodes content.
	// In this case there are 3 types of content
	virtual void setContent(int) = 0;
	virtual void setContent(float) = 0;
	virtual void setContent(std::string) = 0;
	
	// Funcs to operate with child Nodes
	virtual uint getChildrenQ(INode *n) = 0;
	virtual INode* getChild(uint) = 0;
	virtual void addChild(INode) = 0;

	// Get link to parent node
	virtual INode* getParent() = 0;

	// Func to define type of node
	virtual uint nodeType() = 0;
};

class NodeInt: public INode{
private:
	typedef int T;
	T content;
	NodeInt *parent;
	std::vector<NodeInt *> children;
	const uint type = INT;
public:
	NodeInt(){ };
	~NodeInt(){};
	NodeInt(NodeInt *p): parent(p){ };
	NodeInt(NodeInt *p, T c): parent(p), content(c){ };

	int getContent(){ return content;};

	void setContent(T c){
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

class NodeFl: public INode{
private:
	typedef float T;
	T content;
	NodeFl *parent;
public:
	std::vector<NodeFl *> children;
	NodeFl(){ type = FLOAT; };
	~NodeFl(){};
	NodeFl(NodeFl *p): parent(p){ type = FLOAT; };
	NodeFl(NodeFl *p, T c): parent(p), content(c){ type = FLOAT; };

	T getContent(){
		return content;
	};

	void setContent(T c){
		content = c;
	};

	uint getChildrenQ(){
		return children.size();
	};
	
	NodeFl *getChild(uint i){
		uint cq = children.size();
		return (cq > 0 && i < cq)? children.at(i) : (NodeFl *)NULL;
	};
		
	void addChild(NodeFl *pC){
		children.push_back(pC);
	}
			
	NodeFl *cutChild(NodeFl *p){
		NodeFl *c = p;
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
				children.erase(children.begin()+i);
			};
		}
		return c;
	};
				
	void delChild(NodeFl *p){
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
			 children.erase(children.begin()+i);
			};
		}
	};
					
	NodeFl* getParent(NodeFl node){
		return node.parent;
	};

	void changeParent(NodeFl pnode){
		parent = &pnode;
	};
};

class NodeStr: public INode{
private:
	typedef std::string T;
	T content;
	NodeStr *parent;
public:
	std::vector<NodeStr *> children;
	NodeStr(){ type = STR; };
	~NodeStr(){};
	NodeStr(NodeStr *p): parent(p){ type = STR; };
	NodeStr(NodeStr *p, T c): parent(p), content(c){ type = STR; };

	T getContent(){
		return content;
	};

	void setContent(T c){
		content = c;
	};

	uint getChildrenQ(){
		return children.size();
	};
	
	NodeStr *getChild(uint i){
		uint cq = children.size();
		return (cq > 0 && i < cq)? children.at(i) : (NodeStr *)NULL;
	};
		
	void addChild(NodeStr *pC){
		children.push_back(pC);
	}
			
	NodeStr *cutChild(NodeStr *p){
		NodeStr *c = p;
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
				children.erase(children.begin()+i);
			};
		}
		return c;
	};
				
	void delChild(NodeStr *p){
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
				children.erase(children.begin()+i);
			};
		}
	};
					
	NodeStr* getParent(NodeStr node){
		return node.parent;
	};

	void changeParent(NodeStr pnode){
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
/*
class TreeT{
	INode *root;
public:
	TreeT(){
		root = new NodeInt((NodeInt*)root, (int)NULL);
	};

	TreeT(int val){
		root = new NodeInt((NodeInt*)root, val);
	};


	TreeT(float val){
		root = new NodeFl((NodeFl*)root, val);
	};


	TreeT(std::string val){
		root = new NodeStr((NodeStr*)root, val);
	};

	~TreeT(){
		delete root;
	};

	// Appending to the root
	void appendNode(INode *node){
		root->addChild(node);
	};

	// Appending to the node
	void appendNode(INode &node, INode *child){
		node.addChild(child);
	};

	void appendNode(INode *node, INode *child){
		node->addChild(child);
	};

	void delNode(auto* node){
		auto *tnode = node->getParent();

		uint i=0;

		while(i < tnode->getChildreQ()){
			if(tnode->children[i] == &node){
				tnode->children.erase(tnode->children[i]);
				break;
			}
			i++;
		}
	};

	auto cutNode(auto *node){
		auto *tnode = node->getParent();
		auto retNode = NULL;

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

	auto *getRoot(){
		return root;
	};

	auto visit(auto *pN){
		auto c = pN->getContent();
		return c;
	}

	void traverseTree(auto *pN, void (*F)(auto*)){
		F(pN);
		int cq = pN->getChildrenQ();
		// Job with content
		for(int i=0; i<cq; i++){
			traverseTree(pN->getChild(i), F);
		}
	};

};
*/
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
