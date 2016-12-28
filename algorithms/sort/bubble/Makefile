CC	:= clang++
CF	:= -Wextra -std=c++14 #-I./ -L./ -lutil
VPATH = ../
INC = -I../
OBJS = $(patsubst %.cpp, %.o, ifacesort.cpp)

bubble: $(OBJS) bubble.cpp 
	$(CC) $(CF) $(INC) $^ -o sort 

%.o: %.cpp
	$(CC) $(CF) $^ -c 

clear:
	rm -f *.o
	rm -f sort
