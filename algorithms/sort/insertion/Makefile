CC	:= g++
CFLAGS	:= -Wextra -std=c++14 -I../
VPATH = ..

insertion: ifacesort.o  insertion.cpp 
	$(CC) $(CFLAGS) -o sort insertion.cpp ifacesort.o

ifacesort.o: ifacesort.cpp
	$(CC) $(CFLAGS) -c ../ifacesort.cpp 

clear:
	rm -f *.o
	rm -f sort
