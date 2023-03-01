CC=gcc
SOURCES=s21_string_test.c s21_string.c
HEADERS=s21_string.h

all: strlen_tests strcmp_tests strcpy_tests

strlen_tests: $(SOURCES) $(HEADERS)
	$(CC) -w -DLEN $(SOURCES) -o ../build/Quest_1

clean: 
	rm -rf *.o

rebuild:clean all

strcmp_tests: $(SOURCES) $(HEADERS)
	$(CC) -w -DCMP $(SOURCES) -o ../build/Quest_2

strcpy_tests: $(SOURCES) $(HEADERS)
	$(CC) -w -DCPY $(SOURCES) -o ../build/Quest_3
