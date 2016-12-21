CC	:= g++
CFLAGS	:= -Wextra -std=c++14 -I../
VPATH = ..

pqsort: ifacesort.o pqsort.cpp 
	$(CC) $(CFLAGS) -o sort pqsort.cpp ifacesort.o

ifacesort.o: ifacesort.cpp
	$(CC) $(CFLAGS) -c ../ifacesort.cpp 

clear:
	rm -f *.o
	rm -f sort
