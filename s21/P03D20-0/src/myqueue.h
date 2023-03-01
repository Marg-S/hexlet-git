#ifndef QUEUE
#define QUEUE

#include "graph.h"

struct queue {
    struct word *operation;
    struct queue *next;
};

void push_q(struct word *w, struct queue **last, struct queue **first);
struct word *pop_q(struct queue **first);

#endif
