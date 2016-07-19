CC	:= g++
CF	:= -Wextra -std=c++14 -pthread

all: unique shared weak

unique:	unique.cpp
	$(CC) $(CF) -o ue unique.cpp

shared:	shared.cpp
	$(CC) $(CF) -o sd shared.cpp

weak:	weak.cpp
	$(CC) $(CF) -o wk weak.cpp

clear:
	rm -f *.o
	rm -f ue sd wk
