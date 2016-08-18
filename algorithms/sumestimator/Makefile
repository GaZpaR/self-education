CC              := g++
PROJPATH				:= -I./
LIBPATH         := -L/usr/include
OPTS            := -Wextra -std=c++14
LIBRARIES       :=

all: sumest.cpp 
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -o se sumest.cpp
	rm -f *.o

clear:
	rm -f se
