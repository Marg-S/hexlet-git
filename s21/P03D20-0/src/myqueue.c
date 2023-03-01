#include "myqueue.h"

#include <stdio.h>
#include <stdlib.h>

void push_q(struct word *w, struct queue **last, struct queue **first) {
    if (*last != NULL) {
        struct queue *tmp = malloc(sizeof(struct queue));
        tmp->operation = w;
        tmp->next = NULL;
        (*last)->next = tmp;
        *last = tmp;
    } else {
        *last = malloc(sizeof(struct queue));
        (*last)->operation = w;
        (*last)->next = NULL;
        *first = *last;
    }
}

struct word *pop_q(struct queue **first) {
    if (*first != NULL) {
        struct queue *tmp = *first;
        struct word *w = (*first)->operation;
        *first = (*first)->next;
        free(tmp);
        return w;
    } else
        return NULL;
}