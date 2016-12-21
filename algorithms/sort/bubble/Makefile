CC	:= clang++
CF	:= -Wextra -std=c++14 #-I./ -L./ -lutil

bubble: ifacesort.o bubble.cpp 
	$(CC) $(CF) bubble.cpp ifacesort.o -o sort 

ifacesort.o: ifacesort.cpp
	$(CC) $(CF) ifacesort.cpp -c 

clear:
	rm -f *.o
	rm -f sort
