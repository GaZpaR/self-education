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
	virtual void setParent(INode*) = 0;

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
	NodeInt();
	~NodeInt();
	NodeInt(T c);
	NodeInt(INode *p);
	NodeInt(INode *p, T c);

	NodeInt(INode &n);
	INode& operator=(INode &n);

	uint nodeType();

	void* getContent();

	void setContent(float);
	void setContent(std::string);

	void setContent(T c);

	uint getChildrenQ();
	
	INode *getChild(uint i);
	
	void addChild(INode *pC);
			
	INode *cutChild(INode *p);
				
	void delChild(INode *p);

	INode* getParent(INode &p);
	INode* getParent();

	void setParent(INode *p);

	void setCoordinates(uint l, uint p);

	NC getCoordinates();
};

class NodeFl: public INode{
private:
	typedef float T;
	T content;
	INode *parent;
	std::vector<INode *> children;
	const uint type = FLOAT;
	NC coord;
public:
	NodeFl();
	~NodeFl();
	NodeFl(T c);
	NodeFl(INode *p, T c);

	NodeFl(INode &n);
	INode& operator=(INode &n);

	uint nodeType();

	void* getContent();

	void setContent(int);
	void setContent(std::string);

	void setContent(T c);

	uint getChildrenQ();
	
	INode *getChild(uint i);
	
	void addChild(INode *pC);
			
	INode *cutChild(INode *p);
				
	void delChild(INode *p);

	INode* getParent(INode &p);
	INode* getParent();

	void setParent(INode *p);

	void setCoordinates(uint l, uint p);

	NC getCoordinates();
};


class NodeStr: public INode{
private:
	typedef std::string T;
	T content;
	INode *parent;
	std::vector<INode *> children;
	const uint type = STR;
	NC coord;
public:
	NodeStr();
	~NodeStr();
	NodeStr(T c);
	NodeStr(INode *p);
	NodeStr(INode *p, T c);

	NodeStr(INode &n);
	INode& operator=(INode &n);

	uint nodeType();

	void* getContent();

	void setContent(float);
	void setContent(int);

	void setContent(T c);

	uint getChildrenQ();
	
	INode *getChild(uint i);
	
	void addChild(INode *pC);
			
	INode *cutChild(INode *p);
				
	void delChild(INode *p);

	INode* getParent(INode &p);
	INode* getParent();

	void setParent(INode *p);

	void setCoordinates(uint l, uint p);

	NC getCoordinates();
};

