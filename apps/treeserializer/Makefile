CC              := g++
PROJPATH				:= -I./
LIBPATH         := -L/usr/include
OPTS            := -Wextra -std=c++11
LIBRARIES       :=

all: 
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -o sr serializer.cpp
	rm -f *.o

clear:
	rm -f *.o
	rm -f sr
