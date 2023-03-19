#include "deque.h"


int main(void)
{

    int front, rear;
    int *deque = (int*)calloc(N,sizeof(int));

    int c = count(deque);

    front = rear = -1;


    addFront(deque, 6, &front, &rear);
    addFront(deque, 6, &front, &rear);
    addRear(deque, 7, &front, &rear);
    addRear(deque, 10, &front, &rear);

    addFront(deque, -1, &front, &rear);

    delFront(deque, &front, &rear);

    delFront(deque, &front, &rear); //5 7 10

    delRear(deque, &front, &rear);

    delRear(deque, &front, &rear);

    addRear(deque,10,&front,&rear);
    addFront(deque,15,&front,&rear);
    addRear(deque,102,&front,&rear);
    addFront(deque,82,&front,&rear);
    addRear(deque,70,&front,&rear);
    addFront(deque,17,&front,&rear);
    delFront(deque,&front,&rear);
    delRear(deque,&front,&rear);
    delFront(deque, &front, &rear);
    addFront(deque, 203, &front, &rear);
    display(deque);

    free(deque);
    return 0;
}
