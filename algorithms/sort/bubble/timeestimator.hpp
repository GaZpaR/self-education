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
		calcTime();
  }
  float value(){
    float ret = (float)_m;
    return ret;
  }
private:
  std::chrono::high_resolution_clock::time_point _tSta, _tSto;
  float _m;
	void calcTime(){
      auto tT = _tSto - _tSta;

      _m = (float)std::chrono::duration_cast<std::chrono::microseconds>(tT).count()/1000;
  }

};


