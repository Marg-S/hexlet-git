CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: state_sort

state_sort: state_sort.c state_sort.h
	$(CC) $(CFLAGS) state_sort.c -o ../build/Quest_1

clean: 
	rm -rf *.o

rebuild:clean all
