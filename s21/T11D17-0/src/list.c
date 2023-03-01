#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

struct node* init(struct door* door1) {
    struct node* node1 = malloc(sizeof(struct node));
    (*node1).info = door1;
    (*node1).next = NULL;

    return node1;
}

struct node* add_door(struct node* elem, struct door* door_add) {
    struct node* node_add = malloc(sizeof(struct node));
    (*node_add).next = (*elem).next;
    (*elem).next = node_add;

    (*node_add).info = door_add;

    return node_add;
}

struct node* find_door(int door_id, struct node* root) {
    struct node *p = root, *door_find = NULL;
    while (p) {
        if ((*(*p).info).id == door_id) {
            door_find = p;
            break;
        }
        p = (*p).next;
    }

    return door_find;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node *p = root, *node_next = NULL;

    if (elem != root)
        while (elem && p && (*p).next != elem) p = (*p).next;
    if (p && elem && root) {
        (*p).next = (*elem).next;
        // free((*elem).info);
        free(elem);
        node_next = (*p).next;
    }

    return node_next;
}

void destroy(struct node* root) {
    struct node* p = root;
    while (p) {
        // free((*p).info);
        free(p);
        p = (*p).next;
    }
}
