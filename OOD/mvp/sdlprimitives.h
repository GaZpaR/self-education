#include <stdio.h>
#include <SDL2/SDL.h> // Main SDL header
#include <SDL2/SDL_ttf.h> // SDL header to work with true type fonts

typedef unsigned int uint;

enum{
	NOEVENT = 0,
	KEY,
	CLICK,
	CURSORMOVEMENT,
	NOWINDOW
};

typedef struct{
	uint etype;
	char key;
	double xpos, ypos;	
}viewEvent; 

// Create calculator window
void createWindow();

// Update bar with result or expression
void updateWindow(char *str, uint len);

// Change color of pressed button
void pressButton(char button);

// Change color of released button
void releaseButton(char button);

// View event
viewEvent EventOnView();

// Close window
void closeWindow();
