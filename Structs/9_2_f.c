#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *numbers;
    int n;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main(void)
{
    Stack s1;
    initStack(&s1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    int m = getStackSize(&s1);
    int val = pop(&s1);
    destroyStack(&s1);
    //printf("%d", val);
    printStack(&s1);

    return 0;
}

void initStack(Stack *stack)
{
    stack->numbers = NULL;
    stack->n = 0;
}

void printStack(Stack *stack)
{

    for(int i = 0; i < stack->n; i++)
        printf("%d ", stack->numbers[i]);
}

int getStackSize(Stack *stack)
{
    return stack->n;
}

void push(Stack *stack, int value)
{

    stack->n += 1;
    if((stack->n) > 1)
    {
        stack->numbers = realloc((stack->numbers), (stack->n) * sizeof(*stack));
        stack->numbers[(stack->n) - 1] = value;
    }
    else
    {
        stack->numbers = (Stack*) malloc((stack->n) * sizeof(*stack));
        stack->numbers[(stack->n)-1] = value;
    }

}

int top(Stack *stack)
{
    return stack->numbers[(stack->n) - 1];
}

int pop(Stack *stack)
{
    int deleted_val = stack->numbers[(stack->n) - 1];
    stack->n -= 1;
    stack->numbers = realloc((stack->numbers), (stack->n) * sizeof(*stack));

    return deleted_val;
}

void destroyStack(Stack *stack)
{
    free(stack->numbers);
    stack->n = NULL;
}
/*

    stack->n += 1;
    stack->numbers = (Stack*) malloc((stack->n) * sizeof(*stack));
    stack->numbers[(stack->n)-1] = value;

*/
