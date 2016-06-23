CC	:= g++
CF	:= -Wextra -std=c++14

all: serial chained

serial: queueserial.cpp
	$(CC) $(CF) -o qs queueserial.cpp

chained: queuechained.cpp
		$(CC) $(CF) -o qc queuechained.cpp

clear:
	rm -f *.o
	rm -f qs qc
