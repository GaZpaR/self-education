CC	:= g++
CFLAGS	:= -Wextra -std=c++14 -I../
VPATH = ..

comparison: ifacesort.o  comparison.cpp 
	$(CC) $(CFLAGS) -o sort comparison.cpp ifacesort.o

ifacesort.o: ifacesort.cpp
	$(CC) $(CFLAGS) -c ../ifacesort.cpp 

clear:
	rm -f *.o
	rm -f sort
