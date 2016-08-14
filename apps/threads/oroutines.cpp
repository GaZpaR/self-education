#include <oroutines.h>
#include <memory>
#include <chrono>

class mTim{
public:
  mTim(){};
  ~mTim(){};
  void mStart(){
    _tSta = std::chrono::high_resolution_clock::now();
  }
  void mStop(){
    _tSto = std::chrono::high_resolution_clock::now();
  }
  void view(std::string name){
      auto tT = _tSto - _tSta;

      _m = (float)std::chrono::duration_cast<std::chrono::microseconds>(tT).count()/1000;

      std::cout<<"++++" << name<<"++++ spend: " << _m <<"ms" << std::endl;
  }
  float value(){
    float ret = _m;
    return ret;
  }
private:
  std::chrono::high_resolution_clock::time_point _tSta, _tSto;
  float _m;
};

void objSetGenerator(std::vector<Object> *vec, int vecsize)
{
  if(!vec->size() > 0){
    int vs = rand()%vecsize;
    std::cout<<"Vector should be with such size: "<<vs<<std::endl;
    for(int i=0; i < vs; i++){
      int color = rand()%3;
      char sym = 'b';
      switch(color){
        case 1:
          sym = 'r';
          break;
        case 2:
          sym = 'g';
          break;
        case 3:
          sym = 'b';
          break;
        default: break;
      }
      Object o(sym);
      vec->push_back(o);
    };
    std::cout<<"Generated vector size is: "<<vec->size()<<std::endl;
  }
}

std::vector<Object> objSetHandler(std::vector<Object> *vec, pRule some)
{
  mTim timer;

  std::cout<<"Handling vector size is: "<<vec->size()<<std::endl;

  std::cout<<"Unhandled vector is:"<<std::endl;
  // Showing unhandled vector content
  for(std::vector<Object>::iterator it = vec->begin() ; it != vec->end(); ++it)//{
    std::cout<<it->oType();

  std::cout<<std::endl;

  timer.mStart();
  // Local vectors definition
  std::vector<Object>::iterator itm[3] = {vec->begin(), vec->begin(), vec->begin()};

  // Setting sort rule
  const char color[3] ={some.color[0], some.color[1], some.color[2]};
  int shift = 0;

  // Special sorting method for 3 types objects
  for(int i=0; i<3; i++){
    for(std::vector<Object>::iterator it = vec->begin() + shift; it != vec->end(); ++it){
      Object some(it->oType());

      if(some.oType() == color[i]){
        vec->erase(it);
        vec->insert(itm[i], some);

        itm[i]++;
        for(int j=i; j<2; j++){
          itm[j+1]++;
        }
        /*if(i == 0){
          itm[1]++;
          itm[2]++;
        }
        else if(i == 1)itm[2]++;*/

        shift++;
      }
    }
  }

  timer.mStop();
  timer.view("----Meas----");

  std::cout<<"Handled vector size is: "<<vec->size()<<std::endl;

  std::vector<Object> retvec;
  for(std::vector<Object>::iterator it = vec->begin(); it != vec->end(); ++it)
    retvec.push_back(*it);

  vec->erase(vec->begin(), vec->end());

/*  std::cout<<"Handling vector size is: "<<vec->size()<<std::endl;

  // Return vector and local vectors definition
  std::vector<Object> retvec, first, second, third;

  // Setting rule to sort
  const char f = some.color[0], s = some.color[1], t = some.color[2];

  std::cout<<"Unhandled vector is:"<<std::endl;
  // Sorting vector and showing unhandled vector content
  for(std::vector<Object>::iterator it = vec->begin() ; it != vec->end(); ++it){
    std::cout<<it->oType();
    if(it->oType() == f) first.push_back(*it);
    else if(it->oType() == s) second.push_back(*it);
          else if(it->oType() == t) third.push_back(*it);
  }
  std::cout<<std::endl;

  // Filling return vector
  for(std::vector<Object>::iterator it = first.begin(); it != first.end(); ++it){
    retvec.push_back(*it);
  }
  for(std::vector<Object>::iterator it = second.begin(); it != second.end(); ++it){
    retvec.push_back(*it);
  }

  for(std::vector<Object>::iterator it = third.begin(); it != third.end(); ++it){
    retvec.push_back(*it);
  }

  // Clearing handled vector
  vec->erase(vec->begin(), vec->end());
  std::cout<<"Handled vector size is: "<<retvec.size()<<std::endl;*/


  return retvec;
}

// Testing objSetHandler
void objSetHandlerTester()
{
  // Creating vectors<Objects> for test
  std::vector<Object> testSeq, resSeq;

  // Creating test rule
  pRule sR;

  // Seting rule
  sR.color[0] = 'g';
  sR.color[1] = 'r';
  sR.color[2] = 'b';

  // Creating character sequence: 5 red, 7 green and 3 blue
  std::string symSeq = "rgrggggbgbgbrrr";

  // Creating control character sequence
  std::string ctrSeq = "gggggggrrrrrbbb";

  // Temporary string
  std::string tStr;

  // Filling test sequence (using shared pointers)
  for(uint i=0; i < symSeq.size(); i++){
    std::shared_ptr<Object> ptr(new Object(symSeq[i]));
    testSeq.push_back(*ptr);
  }

  // Sorting tesSeq with sR rule
  resSeq = objSetHandler(&testSeq, sR);

  for(std::vector<Object>::iterator it = resSeq.begin(); it != resSeq.end(); ++it)
    tStr.push_back(it->oType());

  std::cout<<"Result string is:"<<std::endl;
  std::cout<<tStr<<std::endl;

  if(ctrSeq.compare(tStr) == 0) std::cout<<"Sorting is right. Func is OK"<<std::endl;
  else std::cout<<"Sorting have mistake. Check this func"<<std::endl;
}
