CC	:= g++
CF	:= -Wextra -std=c++14

simple: graph.cpp
	$(CC) $(CF) -o gh graph.cpp

dense: dense.cpp
	$(CC) $(CF) -o de dense.cpp

sparse: sparse.cpp
	$(CC) $(CF) -o se sparse.cpp

clear:
	rm -f *.o
	rm -f gh se de
