#ifndef LIST
#define LIST
#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

struct node* init(struct door* doors);
struct node* add_door(struct node* elem, struct door* doors);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);

struct node {
    struct door* info;
    struct node* next;
};

#endif
