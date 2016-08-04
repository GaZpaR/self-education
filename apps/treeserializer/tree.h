#include <iostream>
#include <string.h>
#include <vector>

typedef struct Ncoordinates{
	uint lev;
	uint pos;
}NC;

enum{
	INT = 0,
	FLOAT,
	STR
};

class INode{
public:
	// This func rets void* which should be casted to user defined type
	virtual void* getContent() = 0;
	
	// This funcs setting nodes content.
	// In this case there are 3 types of content.
	// In all successors should be realizations of all this protos
	virtual void setContent(int) = 0;
	virtual void setContent(float) = 0;
	virtual void setContent(std::string) = 0;
	
	// Funcs to operate with child Nodes
	virtual uint getChildrenQ() = 0;
	virtual INode* getChild(uint) = 0;
	virtual INode* cutChild(INode*) = 0;
	virtual void delChild(INode*) = 0;
	virtual void addChild(INode*) = 0;

	// Get link to parent node
	virtual INode* getParent() = 0;
	virtual INode* getParent(INode&) = 0;

	// Func to define type of node
	virtual uint nodeType() = 0;

	// Funcs to determining and geting Node's coordinates
	virtual void setCoordinates(uint, uint) = 0;
	virtual NC getCoordinates() = 0;
};

class NodeInt: public INode{
private:
	typedef int T;
	T content;
	INode *parent;
	std::vector<INode *> children;
	const uint type = INT;
	NC coord;
public:
	NodeInt(){ };
	~NodeInt(){};
	NodeInt(INode *p){ parent = p; };
	NodeInt(INode *p, T c){
		parent = p;
		content = c;
	};

	uint nodeType(){ return type;};

	void* getContent(){ return &content;};

	void setContent(float){};
	void setContent(std::string){};

	void setContent(T c){	content = c;};

	uint getChildrenQ(){ return children.size();};
	
	INode *getChild(uint i){
		uint cq = children.size();
		return (cq > 0 && i < cq)? children.at(i) : (INode *)NULL;
	};
	
	void addChild(INode *pC){	children.push_back(pC);	}
			
	INode *cutChild(INode *p){
		INode *c = p;
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
				children.erase(children.begin()+i);
			};
		}
		return c;
	};
				
	void delChild(INode *p){
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
			 children.erase(children.begin()+i);
			};
		}
	};

	INode* getParent(INode &p){ return p.getParent(); };				
	INode* getParent(){ return parent; };

	void setParent(INode *p){
		parent = p;
	};

	void setCoordinates(uint l, uint p){
		coord.lev = l;
		coord.pos = p;
	}

	NC getCoordinates(){
		return coord;
	}

};

class NodeFl: public INode{
private:
	typedef float T;
	T content;
	INode *parent;
	std::vector<INode *> children;
	const uint type = FLOAT;
	Ncoordinates coord;
public:
	NodeFl(){};
	~NodeFl(){};
	NodeFl(INode *p): parent(p){};
	NodeFl(INode *p, T c): parent(p), content(c){};

	uint nodeType(){ return type;};


	void* getContent(){	return &content;};
	
	void setContent(int){};
	void setContent(std::string){};

	void setContent(T c){	content = c;};
	

	uint getChildrenQ(){return children.size();};
	
	INode *getChild(uint i){
		uint cq = children.size();
		return (cq > 0 && i < cq)? children.at(i) : (INode *)NULL;
	};
		
	void addChild(INode *pC){children.push_back(pC);}
			
	INode *cutChild(INode *p){
		INode *c = p;
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
				children.erase(children.begin()+i);
			};
		}
		return c;
	};
				
	void delChild(INode *p){
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
			 children.erase(children.begin()+i);
			};
		}
	};
	
	INode* getParent(){ return parent; }

	INode* getParent(INode &p){ return p.getParent(); };

	void changeParent(INode &pnode){
		parent = &pnode;
	};
	
	void setCoordinates(uint l, uint p){
		coord.lev = l;
		coord.pos = p;
	}

	NC getCoordinates(){
		return coord;
	}

};

class NodeStr: public INode{
private:
	typedef std::string T;
	T content;
	INode *parent;
	const uint type = STR;
	std::vector<INode *> children;
	Ncoordinates coord;
public:
	NodeStr(){};
	~NodeStr(){};
	NodeStr(INode *p): parent(p){};
	NodeStr(INode *p, T c): parent(p), content(c){};

	uint nodeType(){ return type;};


	void* getContent(){	return &content;};

	void setContent(int){};
	void setContent(float){};

	void setContent(T c){	content = c;};

	uint getChildrenQ(){return children.size();};
	
	INode *getChild(uint i){
		uint cq = children.size();
		return (cq > 0 && i < cq)? children.at(i) : (NodeStr *)NULL;
	};
		
	void addChild(INode *pC){	children.push_back(pC);}
			
	INode *cutChild(INode *p){
		INode *c = p;
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
				children.erase(children.begin()+i);
			};
		}
		return c;
	};
				
	void delChild(INode *p){
		for (uint i=0; i<children.size(); i++){
			if(children.at(i) == p){
				children.erase(children.begin()+i);
			};
		}
	};

	INode* getParent(){ return parent; }
					
	INode* getParent(INode &p){ return p.getParent();};

	void changeParent(INode &pnode){
		parent = &pnode;
	};

	void setCoordinates(uint l, uint p){
		coord.lev = l;
		coord.pos = p;
	}

	NC getCoordinates(){
		return coord;
	}
};

class Tree{
	INode *root;
public:
	Tree(INode *n){
		root = n;
	};

	~Tree(){
		delete root;
	};

	// Appending to the root
	void appendNode(INode *n){
		root->addChild(n);
		n->setCoordinates(1, root->getChildrenQ());
	};

	// Appending to the node
	void appendNode(INode &n, INode *c){
		n.addChild(c);
		c->setCoordinates(n.getCoordinates().lev + 1, n.getChildrenQ());
	};

	void appendNode(INode *n, INode *c){
		n->addChild(c);
		c->setCoordinates(n->getCoordinates().lev + 1, n->getChildrenQ());
	};

	void delNode(INode* n){
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

	INode* cutNode(INode *n){
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

	INode *getRoot(){return root;};

	void* visit(INode *pN){	return pN->getContent();}

	void traverseTree(INode *pN, void (*F)(INode*, std::vector<std::string>&), std::vector<std::string> &v){
		F(pN, v);
		int cq = pN->getChildrenQ();
		// Job with content
		for(int i=0; i<cq; i++){
			traverseTree(pN->getChild(i), F, v);
		}
	};
};

