OBJS	= recurse.o stairs.o
SOURCE	= recurse.cpp stairs.cpp
HEADER	= stairs.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

recurse.o: recurse.cpp
	$(CC) $(FLAGS) recurse.cpp 

stairs.o: stairs.cpp
	$(CC) $(FLAGS) stairs.cpp 


clean:
	rm -f $(OBJS) $(OUT)