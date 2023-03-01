#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void close(struct door* doors);
void output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    close(doors);
    output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* doors) {
    for (struct door* left = doors; left - doors < DOORS_COUNT; left++) {
        int min_id = (*left).id;
        struct door* p_min = left;

        for (struct door* right = left + 1; right - doors < DOORS_COUNT; right++) {
            if ((*right).id < min_id) {
                min_id = (*right).id;
                p_min = right;
            }
        }

        if (p_min != left) {
            int temp = (*left).id;
            (*left).id = min_id;
            (*p_min).id = temp;
        }
    }
}

void close(struct door* doors) {
    for (struct door* p = doors; p - doors < DOORS_COUNT; p++) (*p).status = 0;
}

void output(struct door* doors) {
    for (struct door* p = doors; p - doors < DOORS_COUNT; p++) printf("%d, %d\n", (*p).id, (*p).status);
}
