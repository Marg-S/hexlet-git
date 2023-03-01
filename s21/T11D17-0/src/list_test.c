#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

void add_door_test(struct node* elem, struct door* doors);
void remove_door_test(struct node* elem, struct node* root);
struct door* init_door(int i);

int main() {
    struct door door1 = {1, 0};
    struct node* node1 = init(&door1);
    struct door door2 = {2, 0};
    struct door door3 = {3, 0};
    struct door door4 = {4, 0};
    struct door door5 = {5, 0};

    add_door_test(node1, &door2);
    add_door_test(find_door(2, node1), &door3);
    add_door_test(find_door(3, node1), &door4);
    add_door_test(find_door(4, node1), &door5);

    remove_door_test(find_door(2, node1), node1);
    remove_door_test(find_door(4, node1), node1);
    remove_door_test(find_door(5, node1), node1);

    destroy(node1);

    return 0;
}

void add_door_test(struct node* elem, struct door* doors) {
    struct node* return_function = add_door(elem, doors);

    if (return_function == (*elem).next)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void remove_door_test(struct node* elem, struct node* root) {
    struct node* return_function = remove_door(elem, root);

    if (return_function == (*elem).next)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}
