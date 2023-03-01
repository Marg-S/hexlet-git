#include "state_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256
#define DIR "../"

int main() {
    int n = -1;
    char c, fname[MAXLEN] = {'\0'}, filename[MAXLEN] = {'\0'};
    strcpy(filename, DIR);

    scanf("%255s", fname);
    if (strcmp(fname, "")) {
        FILE *p_file = fopen(fname, "r+b");
        if (p_file == NULL) {
            strcat(filename, fname);
            p_file = fopen(filename, "r+b");
        }
        if (p_file != NULL) {
            scanf("%1d%c", &n, &c);
            if (c == '\n') {
                switch (n) {
                    case 0:
                        output(p_file);
                        break;
                    case 1:
                        sort(p_file);
                        output(p_file);
                        break;
                    case 2:
                        add_data(p_file);
                        sort(p_file);
                        output(p_file);
                        break;
                    default:
                        printf("n/a");
                }
            } else
                printf("n/a");

            fclose(p_file);
        } else
            printf("n/a");
    } else
        printf("n/a");

    return 0;
}

void output(FILE *p_file) {
    struct Data d = get_by_id(p_file, 0);
    if (!feof(p_file)) {
        for (int id = 0; !feof(p_file); id++) {
            printf("%d %d %d %d %d %d %d %d\n", d.year, d.month, d.day, d.hour, d.minute, d.second, d.status,
                   d.code);
            d = get_by_id(p_file, id + 1);
        }
    } else
        printf("n/a");
}

void sort(FILE *p_file) {
    if (!feof(p_file)) {
        fseek(p_file, 0, SEEK_END);
        int n = ftell(p_file) / sizeof(struct Data);

        for (int i = 0; i < n - 1; i++) {
            for (int id = 0; id < n - i - 1; id++) {
                struct Data a = get_by_id(p_file, id), b;

                if (!feof(p_file)) {
                    b = get_by_id(p_file, id + 1);

                    if ((a.year > b.year) || (a.year == b.year && a.month > b.month) ||
                        (a.year == b.year && a.month == b.month && a.day > b.day) ||
                        (a.year == b.year && a.month == b.month && a.day == b.day && a.hour > b.hour) ||
                        (a.year == b.year && a.month == b.month && a.day == b.day && a.hour == b.hour &&
                         a.minute > b.minute) ||
                        (a.year == b.year && a.month == b.month && a.day == b.day && a.hour == b.hour &&
                         a.minute == b.minute && a.second > b.second)) {
                        set_by_id(p_file, id, &b);
                        set_by_id(p_file, id + 1, &a);
                    }
                }
            }
        }
    } else
        printf("n/a");
}

void add_data(FILE *p_file) {
    char c;
    struct Data d;

    fseek(p_file, 0, SEEK_END);
    long int k = ftell(p_file) / sizeof(struct Data);

    int n = scanf("%4d%2d%2d%2d%2d%2d%1d%d%c", &(d.year), &(d.month), &(d.day), &(d.hour), &(d.minute),
                  &(d.second), &(d.status), &(d.code), &c);
    if (c == '\n' && n == 9 && d.year > 0 && d.year < 2023 && d.month > 0 && d.month < 13 && d.day > 0 &&
        d.day < 32 && d.hour >= 0 && d.hour < 25 && d.minute >= 0 && d.minute < 60 && d.second >= 0 &&
        d.second < 60) {
        if ((d.month == 2 && d.day > 29) ||
            ((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && d.day > 30))
            printf("n/a");
        else
            set_by_id(p_file, k, &d);
    } else
        printf("n/a");
}

struct Data get_by_id(FILE *stream, long int id) {
    struct Data data;
    fseek(stream, id * sizeof(struct Data), SEEK_SET);
    fread(&data, sizeof(struct Data), 1, stream);

    return data;
}

void set_by_id(FILE *stream, long int id, struct Data *data) {
    fseek(stream, id * sizeof(struct Data), SEEK_SET);
    fwrite(data, sizeof(struct Data), 1, stream);
}
