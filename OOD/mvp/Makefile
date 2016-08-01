CC              := g++
PROJPATH				:= -I./
LIBPATH         := -L/usr/include
OPTS            := -Wextra -std=c++11
LIBRARIES       := -lSDL2 -lSDL2_image -lSDL2_ttf

all: mvp mainfile
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -o pr mainfile.o mvp.o primsdl.o
	rm -f *.o
mainfile: mainfile.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c mainfile.cpp
mvp: primsdl mvp.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c mvp.cpp
primsdl: primsdl.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c primsdl.cpp

clear:
	rm -f *.o
	rm -f pr
