#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

typedef struct Node
{
    int data;                                           // data of the node

    struct Node * next;                                 // pointer to next node in doubly linked list
    struct Node * prev;                                 // pointer to previous node in doubly linked list
} List;

void append (List ** head_ref, int new_data);            // inserts an element to the end in the list

void push (List ** head_ref, int new_data);              // inserts an element to the beginning of the list

void print_list (List * node);                           // prints out the list

void delete_minimum (List ** Node);

#endif // LINKED_LIST_H_INCLUDED
