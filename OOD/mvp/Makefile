CC              := g++
PROJPATH				:= -I./
LIBPATH         := -L/usr/include
OPTS            := -Wextra -std=c++11
LIBRARIES       := -lSDL2  -lSDL2_ttf #-lSDL2_image

all: sdl view presenter model main
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -o mvp mainfile.o mvp.o primsdl.o
	rm -f *.o
main: main.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c main.cpp

model: model.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c model.cpp

presenter: presenter.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c presenter.cpp

view: view.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c view.cpp

sdl: sdlprimitives.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c sdlprimitives.c

clear:
	rm -f *.o
	rm -f mvp
