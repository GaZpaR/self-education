#include <iostream>
#include <vector>

#include <stdlib.h>

#include <boost/thread.hpp>

#include "oroutines.h"

// Mutexes to working with massive of objects, sorting rule and start/stop generator and handler
boost::condition_variable   data_ready_cond;
boost::mutex                data_ready_mutex;
bool                        data_ready = false;

// Flag to start/stop process
std::unique_ptr<bool> proc(new bool);

// Structure with sorting rule
std::shared_ptr<pRule> someRule(new pRule);//

// This is container for objects
std::vector<Object> dataSet;



// Functions for program interface
void setNewRule();
void showHelp();


void genThread()
{
  std::cout<<"Generator thread: Making new set of objects!"<<std::endl;

  objSetGenerator(&dataSet, 10 + rand()%120);


  data_ready = true;
  data_ready_cond.notify_all();
}

void hanThread()
{
  boost::unique_lock<boost::mutex> lock(data_ready_mutex);
  while (!data_ready)
  {
      data_ready_cond.wait(lock);
  }

  std::cout<<"Handler thread: Handling generated set of objects!"<<std::endl;
  std::vector<Object> some = objSetHandler(&dataSet, *someRule);
  std::cout<<"Sorted values"<<std::endl;

  // Show result of handling
  for(std::vector<Object>::iterator it = some.begin(); it != some.end(); ++it)
    std::cout<<it->oType();
  std::cout<<std::endl;

}

void processing(){

  while((*proc)){
    boost::thread g(genThread), h(hanThread);
    g.join();
    h.join();
  }
}
// Main thread controll all application
void mainThread()
{
  char sym = 0;
  // Set default sort rule
  someRule->color[0] = 'r';someRule->color[1] = 'g';someRule->color[2] = 'b';
  std::cout<<"Hello! This is test task for SD or SDT!"<<std::endl<<"Main thread..."<<std::endl;
  showHelp();
  bool quit = false;
  (*proc) = false;
  for(;;){
    // UI realization
    std::cin>>sym;
    switch(sym){
      case 'e':{
        if(!(*proc)){
          (*proc) = true;
          boost::thread p(processing);
          p.detach();
        }
        break;
      }

      case 's':{
        (*proc) = false;
        break;
      }

      case 'r':{
        setNewRule();
      }
        break;

      case 'h':
        showHelp();
        break;
      case 'q':
        quit = true;
        break;

      default: break;
    }

    boost::this_thread::sleep(boost::posix_time::milliseconds(100));

    if(quit){
       (*proc) = false;
       break;
     }
  }

}



int main(int argc, char* argv[])
{
  // Test for handler
  objSetHandlerTester();

  // Creating threads
  boost::thread m(mainThread);

  // Strarting threads
  m.join();


  std::cout<<"End program. Bye, Bye!"<<std::endl;
  return 0;
}

// UI functions
void setNewRule()
{
    std::cout<<"Main thread: Setting new rule!"<<std::endl;

    std::cout<<"0 is RGB; 1 is RBG"<<std::endl;
    std::cout<<"2 is GRB; 3 is GBR"<<std::endl;
    std::cout<<"4 is BGR; 5 is BRG"<<std::endl;
    std::cout<<"Default rule is 0"<<std::endl;
    char sym = '0';
    std::cin>>sym;
    if(sym != '0' && sym != '1' && sym != '2' && sym != '3' && sym != '4' && sym != '5')std::cout<<"New rule is: "<<'0'<<std::endl;
    else std::cout<<"New rule is: "<<sym<<std::endl;
    switch(sym){
      case '1':
        someRule->color[0] = 'r';someRule->color[1] = 'b';someRule->color[2] = 'g';
        break;
      case '2':
        someRule->color[0] = 'g';someRule->color[1] = 'r';someRule->color[2] = 'b';
        break;
      case '3':
        someRule->color[0] = 'g';someRule->color[1] = 'b';someRule->color[2] = 'r';
        break;
      case '4':
        someRule->color[0] = 'b';someRule->color[1] = 'g';someRule->color[2] = 'r';
        break;
      case '5':
        someRule->color[0] = 'b';someRule->color[1] = 'r';someRule->color[2] = 'g';
        break;
      default:
        someRule->color[0] = 'r';someRule->color[1] = 'g';someRule->color[2] = 'b';
        break;
    }
}

void showHelp()
{
  std::cout<<"To start process enter: \"e\""<<std::endl;
  std::cout<<"To stop process enter: \"s\""<<std::endl;
  std::cout<<"To change rule enter: \"r\""<<std::endl;
  std::cout<<"To quit enter: \"q\""<<std::endl;
  std::cout<<"To see this help enter: \"h\""<<std::endl;
}
