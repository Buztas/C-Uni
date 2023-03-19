//UNFINISHED, CODE HAS ERRORS LOL


#include <stdio.h>
#include <stdlib.h>

typedef struct Point{
    float x,y;
} Point;

typedef struct Stack
{
    //Point **coords;
    Point *coords;
    int *n;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point p);
void top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);

int main(void)
{
    Stack s1;
    Point p1 = {2.4, 3.6};
    Point p2 = {4.7, 2.5};
    Point p3 = {6.3, 1.2};
    initStack(&s1);
    push(&s1, p1);
    push(&s1, p2);
    push(&s1, p3);
    int m = getStackSize(&s1);
    Point val = pop(&s1);
    destroyStack(&s1);

    printStack(&s1);

    return 0;
}

void initStack(Stack *stack)
{
    stack->coords = NULL;
    stack->n = 0;
}

void printStack(Stack *stack)
{
    printf("%d", stack->n);
    for(int i = 0; i < stack->n; i++)
        printf("%.2f", stack->coords[i]);
}

int getStackSize(Stack *stack)
{

    return stack->n;
}

void push(Stack *stack, Point p)
{
    stack->n += 1;

    if((stack->n) > 1)
    {
        stack->coords = realloc((stack->coords), (stack->n) * sizeof(*stack));
        stack->coords[(stack->n)-1] = p;
    }
    else
    {
        stack->coords = (Stack*) malloc((stack->n) * sizeof(*stack));
        stack->coords[(stack->n)-1] = p;
    }

}

void top(Stack *stack)
{
    return stack->coords[(stack->n) - 1];
}

Point pop(Stack *stack)
{
    Point deleted_val = stack->coords[(stack->n) - 1];
    stack->n -= 1;
    stack->coords = realloc((stack->coords), (stack->n) * sizeof(*stack));

    return deleted_val;
}

void destroyStack(Stack *stack)
{
    free(stack->coords);
    stack->n = NULL;
}
