#include <iostream>
#include <vector>
#include <stdlib.h>

class Object{
public:
  Object(char t):_o(t){};
  ~Object(){};
  char oType(){return _o;}
private:
  char _o;
};


struct pRule{
  char color[3];
};

void objSetGenerator(std::vector<Object> *vec, int vecsize);

std::vector<Object> objSetHandler(std::vector<Object> *vec, pRule some);

void objSetHandlerTester();
