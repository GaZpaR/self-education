#include "nodes.hpp"

NodeInt::NodeInt(){ };
NodeInt::~NodeInt(){ delete this;};
NodeInt::NodeInt(T c): content(c){};
NodeInt::NodeInt(INode *p){ parent = p; };
NodeInt::NodeInt(INode *p, T c){
	parent = p;
	content = c;
};

NodeInt::NodeInt(INode &n){
	parent = n.getParent();
	content = *(int*)n.getContent();
	coord = n.getCoordinates();
};

INode& NodeInt::operator=(INode &n){
	INode *p = new NodeInt (*(int*)n.getContent());
	p->setParent(n.getParent());
	p->setCoordinates(n.getCoordinates().lev, n.getCoordinates().pos);
	return *p;
};

uint NodeInt::nodeType(){ return type;};

void* NodeInt::getContent(){ return &content;};

void NodeInt::setContent(float){};
void NodeInt::setContent(std::string){};

void NodeInt::setContent(T c){	content = c;};

uint NodeInt::getChildrenQ(){ return children.size();};
	
INode* NodeInt::getChild(uint i){
	uint cq = children.size();
	return (cq > 0 && i < cq)? children.at(i) : (INode *)NULL;
};
	
void NodeInt::addChild(INode *pC){	children.push_back(pC);	}
		
INode* NodeInt::cutChild(INode *p){
	INode *c = p;
	for (uint i=0; i<children.size(); i++){
		if(children.at(i) == p){
			children.erase(children.begin()+i);
		};
	}
	return c;
};
				
void NodeInt::delChild(INode *p){
	for (uint i=0; i<children.size(); i++){
		if(children.at(i) == p){
		 children.erase(children.begin()+i);
		};
	}
};

INode* NodeInt::getParent(INode &p){ return p.getParent(); };				
INode* NodeInt::getParent(){ return parent; };

void NodeInt::setParent(INode *p){
	parent = p;
};

void NodeInt::setCoordinates(uint l, uint p){
	coord.lev = l;
	coord.pos = p;
}

NC NodeInt::getCoordinates(){
	return coord;
}

NodeFl::NodeFl(){ };
NodeFl::~NodeFl(){ delete this;};
NodeFl::NodeFl(T c): content(c){};

NodeFl::NodeFl(INode *p, T c){
	parent = p;
	content = c;
};

NodeFl::NodeFl(INode &n){
	parent = n.getParent();
	content = *(float*)n.getContent();
	coord = n.getCoordinates();
};

INode& NodeFl::operator=(INode &n){
	INode *p = new NodeFl(*(float*)n.getContent());
	p->setParent(n.getParent());
	p->setCoordinates(n.getCoordinates().lev, n.getCoordinates().pos);
	return *p;
};

uint NodeFl::nodeType(){ return type;};

void* NodeFl::getContent(){ return &content;};

void NodeFl::setContent(T c){ content = c;};
void NodeFl::setContent(std::string){};

void NodeFl::setContent(int){};

uint NodeFl::getChildrenQ(){ return children.size();};
	
INode* NodeFl::getChild(uint i){
	uint cq = children.size();
	return (cq > 0 && i < cq)? children.at(i) : (INode *)NULL;
};
	
void NodeFl::addChild(INode *pC){	children.push_back(pC);	}
			
INode *NodeFl::cutChild(INode *p){
	INode *c = p;
	for (uint i=0; i<children.size(); i++){
		if(children.at(i) == p){
			children.erase(children.begin()+i);
		};
	}
	return c;
};
				
void NodeFl::delChild(INode *p){
	for (uint i=0; i<children.size(); i++){
		if(children.at(i) == p){
		 children.erase(children.begin()+i);
		};
	}
};

INode* NodeFl::getParent(INode &p){ return p.getParent(); };				
INode* NodeFl::getParent(){ return parent; };

void NodeFl::setParent(INode *p){
		parent = p;
};

void NodeFl::setCoordinates(uint l, uint p){
		coord.lev = l;
		coord.pos = p;
}

NC NodeFl::getCoordinates(){
	return coord;
}



NodeStr::NodeStr(){ };
NodeStr::~NodeStr(){ delete this;};
NodeStr::NodeStr(T c): content(c){};
NodeStr::NodeStr(INode *p){ parent = p; };
NodeStr::NodeStr(INode *p, T c){
	parent = p;
	content = c;
};

NodeStr::NodeStr(INode &n){
	parent = n.getParent();
	content = *(std::string*)n.getContent();
	coord = n.getCoordinates();
};

INode& NodeStr::operator=(INode &n){
	INode *p = new NodeStr(*(std::string*)n.getContent());
	p->setParent(n.getParent());
	p->setCoordinates(n.getCoordinates().lev, n.getCoordinates().pos);
	return *p;
};

uint NodeStr::nodeType(){ return type;};

void* NodeStr::getContent(){ return &content;};

void NodeStr::setContent(float){};
void NodeStr::setContent(int){};

void NodeStr::setContent(T c){	content = c;};

uint NodeStr::getChildrenQ(){ return children.size();};
	
INode* NodeStr::getChild(uint i){
	uint cq = children.size();
	return (cq > 0 && i < cq)? children.at(i) : (INode *)NULL;
};
	
void NodeStr::addChild(INode *pC){	children.push_back(pC);	}
			
INode *NodeStr::cutChild(INode *p){
	INode *c = p;
	for (uint i=0; i<children.size(); i++){
		if(children.at(i) == p){
			children.erase(children.begin()+i);
		};
	}
	return c;
};
				
void NodeStr::delChild(INode *p){
	for (uint i=0; i<children.size(); i++){
		if(children.at(i) == p){
		 children.erase(children.begin()+i);
		};
	}
};

INode* NodeStr::getParent(INode &p){ return p.getParent(); };				
INode* NodeStr::getParent(){ return parent; };

void NodeStr::setParent(INode *p){
	parent = p;
};

void NodeStr::setCoordinates(uint l, uint p){
	coord.lev = l;
	coord.pos = p;
}

NC NodeStr::getCoordinates(){
	return coord;
}

