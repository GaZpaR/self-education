#include <iostream>
#include <string.h>
#include <vector>

struct leaf{
   char *name;
   uint8_t *content;
   size_t cntnumber;
   leaf* parent;
   std::vector< leaf > child;
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
    virtual void viewSubTree(leaf *choiceleaf);

    // Show tree
    virtual void viewTree(void);

};
