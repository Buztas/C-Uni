#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{
    List * head = NULL;

    //adds a node to the end of the list


    //pushes a node to the front of the list
    //push(&head, 5);

    //push(&head, -1);

    //push(&head, -5);

    //push(&head, -5);

    //push(&head, -9);

    append(&head, -10);

    append(&head, -9);

    append(&head, -5);

    append(&head, -7);

    append(&head, -11);

    // inserts a new node, after the last node added to the list


    // the functions below delete one node, the one that has the minimum value, from the list

    delete_minimum(&head);

//    delete_minimum(&head);

    // prints the entire list

    print_list(head);

    return 0;
}
