#include <iostream>
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

int main(){
	mTim tim;
	tim.mStart();
	for(int i=0; i < 5000; i++)
		std::cout<<i<<" ";
	std::cout<<std::endl;
	tim.mStop();

	tim.view("Counter");
	std::cout<<"Bye bye!"<<std::endl;
	return 0;
}
