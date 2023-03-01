CC=gcc
CFLAGS=-c -Wall
OBJECTS=main_executable_module.o data_io.o data_sort.o decision.o
EXECUTABLE=../../build/Quest_3
HEADERS=../data_module/data_process.h ../yet_another_decision_module/decision.h
HEADERSLIBS=../data_libs/data_io.h ../data_libs/data_sort.h
SOURCE=main_executable_module.c ../data_libs/data_io.c ../data_libs/data_sort.c ../yet_another_decision_module/decision.c

all: Quest_3

Quest_3: $(OBJECTS) data_stat.o data_process.o
	$(CC) $(OBJECTS) data_stat.o data_process.o -o $(EXECUTABLE)

main_executable_module.o: main_executable_module.c $(HEADERS) $(HEADERSLIBS)
	$(CC) $(CFLAGS) main_executable_module.c $(HEADERS) $(HEADERSLIBS)

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	$(CC) $(CFLAGS) ../data_libs/data_io.c

data_process.o: ../data_module/data_process.c ../data_module/data_process.h
	$(CC) $(CFLAGS) ../data_module/data_process.c

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	$(CC) $(CFLAGS) ../data_libs/data_stat.c

data_sort.o: ../data_libs/data_sort.c ../data_libs/data_sort.h
	$(CC) $(CFLAGS) ../data_libs/data_sort.c

decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h
	$(CC) $(CFLAGS) ../yet_another_decision_module/decision.c

clean: 
	rm -rf Quest_3 *.o

rebuild:clean all

data_stat.a: data_stat.o
	ar r libdata_stat.a data_stat.o

build_with_static:clean $(OBJECTS) data_process.o data_stat.a
	$(CC) -o $(EXECUTABLE) $(OBJECTS) data_process.o -L. -ldata_stat

data_process.so: data_process.o data_stat.o
	$(CC) -shared -o libdata_process.so data_process.o data_stat.o

build_with_dynamic:data_process.so $(SOURCE)
	$(CC) $(CFLAGS) -fPIC $(SOURCE)
	$(CC) -o $(EXECUTABLE) *.o -L. -ldata_process -Wl,-rpath,'../src/main_executable_module/libdata_process.so'
