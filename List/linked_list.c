#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

List * detect_minimum (List * node)
{
    List * del;

    int min = node->data;
    del = node;

    while(node != NULL)
    {
        if(min > node->data)
        {
            del = node;
            min = node->data;
        }
        node = node->next;
    }

    return del;
}

void delete_minimum (List ** node)
{

    List * min = detect_minimum(*node);  // creates a node that stores the actual minimum node

    if((*node == NULL) || (min == NULL))             // if both minimum and the argument node are NULL, we end the function
    {
        return;
    }

    if(*node == min)                                 // if true, then the node is assigned to the next pointer of the minimum node
    {
        *node = min->next;
    }

    if((min->next) != NULL)                          // if true, the previous node of the next node becomes the previous node of the minimum
    {
        min->next->prev = min->prev;
    }

    if((min->prev) != NULL)                          // if true, we do the same thing but we switch the next and the previous
    {
        min->prev->next = min->next;
    }

    free(min);

    return;
}



void push(List ** head_ref, int new_data)
{
    List * new_node = (List*) malloc(sizeof(List));

    new_node->data = new_data;                        // assign data to new node
    new_node->prev = NULL;                            // previous node must be null in order for this to be first node
    new_node->next = (*head_ref);                     // the current node is the next node of the newest one

    if((*head_ref) != NULL)                          // changes the previous of head node to the new node
    {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;                           // head ref points to new node
}

void append(List ** head_ref, int new_data)
{
    List * new_node = (List*) malloc(sizeof(List));
    List * last = *head_ref;                          // needed for checking if the entire node is empty

    new_node->data = new_data;                        // inserting new data into the new node
    new_node->next = NULL;                            // next node is NULL, because current node is last one

    if(*head_ref == NULL)
    {
        new_node->prev = NULL;
                                                      // because entire list is empty, previous must be null
        *head_ref = new_node;

        return;
    }

    while((last->next) != NULL)                      // traversing until the last node
    {
        last = last->next;
    }

    last->next = new_node;                            // making the new node be the previous of the current last one
    new_node->prev = last;                            // the previous of the new node is the last one

    return;

}

void print_list(List * node)                         // function that prints the node normally and in reverse order
{
    List * last;

    printf("Doubly Linked List: \n");                // normal order

    while(node != NULL)
    {
        printf("%d ", node->data);

        last = node;

        node = node->next;
    }

    printf("\nReverse Linked List: \n");             // reversed order

    while(last != NULL)
    {
        printf("%d ", last->data);

        last = last->prev;
    }
}
