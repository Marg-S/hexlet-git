#ifndef STACK
#define STACK

#include "graph.h"

struct stack {
    struct word *operation;
    struct stack *next;
};

void push(struct stack **top, struct word *w);
struct word *pop(struct stack **top);

#endif
