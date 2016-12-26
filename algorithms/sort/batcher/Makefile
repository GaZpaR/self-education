CC	:= g++
CF	:= -Wextra -std=c++14
ADDP := -I../
VPATH := src:..

bathcer: ifacesort.o batcher.cpp 
	$(CC) $(CF) $(ADDP) batcher.cpp ifacesort.o -o sort 

ifacesort.o: ifacesort.cpp
	$(CC) $(CF) $(ADDP) ../ifacesort.cpp -c 

clear:
	rm -f *.o
	rm -f sort
