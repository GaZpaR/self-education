CC	:= g++
CFLAGS	:= -Wextra -std=c++14 -I../
VPATH = ..

bqsort: ifacesort.o  bqsort.cpp 
	$(CC) $(CFLAGS) -o sort bqsort.cpp ifacesort.o

ifacesort.o: ifacesort.cpp
	$(CC) $(CFLAGS) -c ../ifacesort.cpp 

clear:
	rm -f *.o
	rm -f sort
