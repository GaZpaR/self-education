CC	:= g++
CFLAGS	:= -Wextra -std=c++14 -I../
VPATH = ..

shell: ifacesort.o shell.cpp 
	$(CC) $(CFLAGS) -o sort shell.cpp ifacesort.o

ifacesort.o: ifacesort.cpp
	$(CC) $(CFLAGS) -c ../ifacesort.cpp 

clear:
	rm -f *.o
	rm -f sort
