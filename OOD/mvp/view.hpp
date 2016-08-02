#include <iostream>

class IView{
public:
	virtual void showBar();
	virtual void onKeyPress();
	virtual void onKeyRelease();
};

class View: public IView{
public:
	View();
	~View();
};
