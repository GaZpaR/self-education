CC	:= g++
CFLAGS	:= -Wextra -std=c++14 -I../
VPATH = ..

mergebase: ifacesort.o mergeb.cpp 
	$(CC) $(CFLAGS) -o sort mergeb.cpp ifacesort.o

ifacesort.o: ifacesort.cpp
	$(CC) $(CFLAGS) -c ../ifacesort.cpp 

clear:
	rm -f *.o
	rm -f sort
