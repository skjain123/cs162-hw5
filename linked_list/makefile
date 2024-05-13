OBJS	= linked_list.o test_linked_list.o
SOURCE	= linked_list.cpp test_linked_list.cpp
HEADER	= linked_list.h node.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

linked_list.o: linked_list.cpp
	$(CC) $(FLAGS) linked_list.cpp 

test_linked_list.o: test_linked_list.cpp
	$(CC) $(FLAGS) test_linked_list.cpp 


clean:
	rm -f $(OBJS) $(OUT)