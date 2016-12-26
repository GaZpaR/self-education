CC	:= g++
CFLAGS	:= -Wextra -std=c++14 -I../
VPATH = ..

insertion: ifacesort.o  lsd.cpp 
	$(CC) $(CFLAGS) -o sort lsd.cpp ifacesort.o

ifacesort.o: ifacesort.cpp
	$(CC) $(CFLAGS) -c ../ifacesort.cpp 

clear:
	rm -f *.o
	rm -f sort
