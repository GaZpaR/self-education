CC	:= g++
PT	:=
FL	:= -Wextra -std=c++11
BFL := -lboost_system -lboost_thread

all: server tcpservdemon
	$(CC) $(FL) $(BFL) -o demon tsd.o server.o
	rm -f *.o
tcpservdemon: tsd.cpp
	$(CC) $(FL) -c tsd.cpp

server: server.cpp
	$(CC) $(FL) $(BFL) -c server.cpp
clear:
	rm -f *.o
	rm -f demon
