#include "view.hpp"
#include "sdlprimitives.h"


View::View(){
	createWindow();
};

View::~View(){
	closeWindow();
};
