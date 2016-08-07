CC	:= g++
PT	:=
FL	:= -Wextra -std=c++11

tcpservdemon: tsd.cpp
	$(CC) $(FL) -o tsd tsd.cpp
server: server.cpp
	$(CC) $(FL) -lboost_system -c server.cpp
clear:
	rm -f *.o
	rm -f tsd
