CC              := g++
PROJPATH				:= -I./
LIBPATH         := -L/usr/include
OPTS            := -Wextra -std=c++14
LIBRARIES       :=

all: nodes tree des ser main
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -o sr main.o serializer.o deserializer.o tree.o nodes.o
	rm -f *.o

main: main.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c main.cpp

ser: serializer.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c serializer.cpp

des: deserializer.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c deserializer.cpp

tree: tree.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c tree.cpp

nodes: nodes.cpp
	$(CC) $(PROJPATH) $(OPTS) $(LIBRARIES) $(LIBPATH) -c nodes.cpp

clear:
	rm -f *.o
	rm -f sr
