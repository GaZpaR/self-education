#include "sdlprimitives.h"
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 330;

typedef struct{
	bool pressed;
	char sym[1];
	SDL_Rect pos;
}btn;

btn keyBoard[15];

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

SDL_Surface *message = NULL;

//The font that's going to be used
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 255, 255, 255 };


//Main loop flag
bool quit = false;

//Event handler
SDL_Event e;

bool initSDL(void)
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf("SDL could not initialize! SDL_Error: %s\r\n", SDL_GetError());
		success = false;
	}
	else{
			//Create window
			gWindow = SDL_CreateWindow( "calcView", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL ){
			printf("Window could not be created! SDL_Error: %s\r\n", SDL_GetError());
			success = false;
		}

		//Get window surface
		gScreenSurface = SDL_GetWindowSurface( gWindow );

		//Initialize SDL_ttf
		if( TTF_Init() == -1 ){
			printf("Cant't init TTF\r\n");
			success = false;
		}
	}

  return success;
}

void initBtn(btn *b, const char *c)
{
	*b->sym = *c;
	// get the width and height of a string as it would be rendered in a loaded font
	int w,h;
	if(TTF_SizeText(font, c, &w, &h)) {
		// perhaps print the current TTF_GetError(), the string can't be rendered...
	} 
	else {
		b->pos.h = h;
		b->pos.w = w;
	}
	b->pressed = false;
}
//The window renderer
SDL_Renderer* gRenderer = NULL;

void createWindow(void)
{
	//Start up SDL and create window
	if( !initSDL() ){
		printf("Failed to init SDL windowi\r\n");
	}
	else{
		//Open the font
		font = TTF_OpenFont( "/usr/share/fonts/gnu-free/FreeMono.ttf", 22 );

		//If there was an error in loading the font
		if( font == NULL ){
			printf("Can't load FreeMono.ttf\r\n");
		}

		TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
	
		// Creating keyboard
		initBtn(&keyBoard[0], "0");		initBtn(&keyBoard[1], "1");		initBtn(&keyBoard[2], "2");		initBtn(&keyBoard[3], "3");
		initBtn(&keyBoard[4], "4");		initBtn(&keyBoard[5], "5");		initBtn(&keyBoard[6], "6");		initBtn(&keyBoard[7], "7");
		initBtn(&keyBoard[8], "8");		initBtn(&keyBoard[9], "9");		initBtn(&keyBoard[10], "+");	initBtn(&keyBoard[11], "-");
		initBtn(&keyBoard[12], "/");	initBtn(&keyBoard[13], "*");	initBtn(&keyBoard[14], "=");
		
		
		//Render the text
		message = TTF_RenderText_Solid( font, "Hello, this is MVP example", textColor );
		
		//If there was an error in rendering the text
		if( message == NULL ){
			printf("createWindow: Can't create message\r\n");
		}
		//Fill the surface with black color 
	  SDL_FillRect( gScreenSurface, NULL, SDL_MapRGB( gScreenSurface->format, 0x00, 0x00, 0x00 ) );
	
		//Apply greetings
		SDL_BlitSurface( message, NULL, gScreenSurface, NULL );
		//Update the surface
		SDL_UpdateWindowSurface( gWindow );
		
	}
}


void drawButton(btn bt, int x, int y){

	SDL_Surface *b = NULL;
	SDL_Color col;
	if(bt.pressed){
		col.r = 0x55;
		col.b = 0x66;
		col.g = 0x88;
	}
	else col = textColor;
	b = TTF_RenderText_Solid( font, bt.sym, col);

	SDL_Rect DestR;
	
	DestR.x = x;
	DestR.y = y;
	SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
	SDL_BlitSurface( b, NULL, gScreenSurface, &DestR );
}


void updateWindow(char *str, uint len)
{
	message = TTF_RenderText_Solid( font,(const char*) str, textColor );

	//If there was an error in rendering the text
	if( message == NULL){
		printf("updateWindow: Can't create message\r\n");
	}
	
	//Fill the surface white
	SDL_FillRect( gScreenSurface, NULL, SDL_MapRGB( gScreenSurface->format, 0x00, 0x00, 0x00 ) );

	SDL_Rect DestR;

	DestR.x = 120;
	DestR.y = 60;

	for(uint j=0; j<1+sizeof(keyBoard)/sizeof(btn)/4; j++)
		for(uint i=0; i<4; i++){
			drawButton(keyBoard[4*j+i],i*20, 20*(j+1));
		}

	SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
	SDL_BlitSurface( message, NULL, gScreenSurface, &DestR );
	
	
	//Update the surface
	SDL_UpdateWindowSurface( gWindow );
}

void pressButton(char button){
}

void releaseButton(char button){

}

void closeWindow(void)
{
	//Deallocate surface
	SDL_FreeSurface( gHelloWorld );
	SDL_DestroyRenderer( gRenderer );
	gRenderer = NULL;
	gHelloWorld = NULL;

	//Close the font that was used
	TTF_CloseFont( font );

	//Quit SDL_ttf
	TTF_Quit();

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
float elapsed = 0.0;

#include <pthread.h>


int main(){
	createWindow();
	printf("This is SDL primitives\r\n");
	//pthread_t t1, t2, th;

	while( !quit ) {
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 ){
			//User requests quit
			if( e.type == SDL_QUIT ){
				quit = true;
			}
		}
		char str[56];
		uint len = snprintf(str, sizeof(str),"%0.2f", elapsed);
		updateWindow(str, len);
		for(uint i=0; i<5; i++)keyBoard[i*2].pressed ^= true; 
		SDL_Delay(500);
		elapsed += 0.5;
	}		
	closeWindow();
	return 0;
}
