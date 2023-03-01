CC=gcc

all: door_struct

door_struct:door_struct_build clean 

door_struct_build: dmanager_module.o 
	$(CC) dmanager_module.o -o ../build/Quest_1

dmanager_module.o: 
	$(CC) -c dmanager_module.c

clean: 
	rm -rf *.o

rebuild:clean all

list_test: 
	$(CC) list.c list.h list_test.c -o ../build/Quest_2