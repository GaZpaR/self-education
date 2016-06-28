#include <iostream>
#include <string.h>
#include <vector>

template<typename T>
class Node{
private:
	T content;
	Node<T> *parent;
	std::vector<Node<T>*> children;
public:

	Node(){};
	Node(Node<T> *par): parent(par){};
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

	Node<T> getParent(Node<T> node){
		return node.parent;
	};

	void setParent(Node<T> pnode){
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
		root->children.push_back(node);
	};

	// Appending to the node
	void appendNode(Node<T> node, Node<T> *child){
		node.children.push_back(child);
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
};

struct leaf{
   char *name;
   uint8_t *content;
   size_t cntnumber;
   leaf* parent;
   std::vector< leaf > children;
};

class arbitarytree{
  private:

    // List with all links of tree
    std::vector<leaf*> links;

    // Nodes quantity
    size_t nqnt;

    leaf root;
    // Create arbitary leaf
    virtual leaf* createLeaf(char *leafname, uint8_t *file, size_t size);

    // Append arbitary leaf to the parent
    virtual void appendLeaf(leaf *parent, leaf *newleaf);

    // Searching parentleaf
    virtual leaf* searchLeaf(char *leafname);

    // Deleting root and all subtrees
    virtual void delTree(void);

  public:
    arbitarytree(char *rootfile, uint8_t *file, size_t size){
      root.name = new char(strlen(rootfile)+1);
      memcpy(root.name, rootfile, strlen(rootfile));

      nqnt = 0;

      root.cntnumber = nqnt;

      root.parent = &root;

      root.content = new uint8_t[size+1];
      memcpy(root.content, file, size);

      links.push_back(&root);
    }

    virtual ~arbitarytree(){
      //delTree();
    }

    // Adding new leaf to the root
    virtual void addLeaf(char *leafname, uint8_t *file, size_t size);
    // Adding new leaf to the parent leaf
    virtual void addLeaf(char *parentleaf, char *leafname, uint8_t *file, size_t size);

    // Deleting leaf and it's children
    virtual void delLeaf(leaf *choiceleaf);

    // Geting leaf by it's name
    virtual leaf* getLeaf(char *filename);

    // Show subtree
    virtual void viewSubTree(leaf *choiseleaf);

    // Show tree
    virtual void viewTree(void);

};
