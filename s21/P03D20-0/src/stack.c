#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push(struct stack **top, struct word *w) {
    struct stack *tmp = (struct stack *)malloc(sizeof(struct stack));
    if (tmp == NULL) {
        puts("STACK_OVERFLOW");
        exit(1);
    } else {
        tmp->next = *top;
        tmp->operation = w;
        *top = tmp;
    }
}

struct word *pop(struct stack **top) {
    if (*top != NULL) {
        struct stack *tmp = *top;
        struct word *w = (*top)->operation;
        *top = (*top)->next;
        free(tmp);
        return w;
    } else
        return NULL;
}
