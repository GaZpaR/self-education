CC              := g++
PROJPATH				:= -I./
LIBPATH         := #-L/usr/include/SDL2
OPTS            := -Wextra -std=c++11
LIBRARIES       := -lboost_thread #-lpthread-lSDL2 -lSDL2_image -lSDL2_ttf

all: rout thr
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -o tr thread.o oroutines.o
	rm -f *.o
thr: thread.cpp
		$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c thread.cpp
rout: oroutines.cpp
		$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c oroutines.cpp

clear:
	rm -f *.o
	rm -f tr
