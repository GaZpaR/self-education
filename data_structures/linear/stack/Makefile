CC	:= g++
CF	:= -Wextra -std=c++14
all: serial chained

serial: stackserial.cpp
	$(CC) $(CF) -o ss stackserial.cpp

chained: stackchained.cpp
		$(CC) $(CF) -o sc stackchained.cpp
clear:
	rm -f *.o
	rm -f ss sc
