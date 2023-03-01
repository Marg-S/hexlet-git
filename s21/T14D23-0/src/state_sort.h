#include <stdio.h>

#ifndef STATE_SORT
#define STATE_SORT

struct Data {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

void output(FILE *p_file);
void sort(FILE *p_file);
void add_data(FILE *p_file);
struct Data get_by_id(FILE *stream, long int id);
void set_by_id(FILE *stream, long int id, struct Data *data);
int counter(FILE *stream);

#endif