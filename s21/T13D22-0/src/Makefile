CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: cipher

cipher: cipher.c 
	$(CC) $(CFLAGS) cipher.c -o ../build/cipher


clean: 
	rm -rf *.o

rebuild:clean all
