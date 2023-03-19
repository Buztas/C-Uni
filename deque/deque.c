#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

#define N 10

void addFront(int *arr, int item, int *pfront, int *prear)
{
    int c, k;
    if(*pfront == 0 && *prear == N - 1)
    {
        printf("\nDeque is full.\n");
        return;
    }
    if(*pfront == -1)
    {
        *pfront = *prear = 0;
        arr[*pfront] = item;
        return;
    }
    if(*prear != N - 1)
    {
        c = count(arr);
        k = *prear + 1;
        for(int i = 0; i < c; i++)
        {
            arr[k] = arr[k - 1];
            k--;
        }
        arr[k] = item;
        *pfront = k;
        (*prear)++;
    } else
    {
        (*pfront)--;
        arr[*pfront] = item;
    }

    //printf("%d\n", item);
}
void addRear(int *arr, int item, int *pfront, int *prear)
{
    int c, k;
    if(*pfront == 0 && *prear == N - 1)
    {
        printf("\nDeque is full.\n");
        return;
    }

    if(*pfront == -1)
    {
        *pfront = *prear = 0;
        arr = (int*) realloc(arr, *prear+1);
        arr[*prear] = item;
    }

    if(*prear == N - 1)
    {
        for(int i = *pfront - 1; i < *prear; i++)
        {
            k = i;
            if(k == N - 1)
                arr[k] = 0;
            else
                arr[k] = arr[i+1];
        }
        (*prear)--;
        (*pfront)--;
    }
    (*prear)++;
    arr[*prear] = item;

    //printf("%d\n", item);
}
void delFront(int *arr, int *pfront, int *prear)
{

    if(*pfront == -1 )
    {
        printf("\nDeque is empty.\n");
        return;
    }

    for(int i = *pfront ; i < *prear ; i++)
    {
        arr[i] = arr[i+1];
    }

    arr[*prear] = 0;

    (*prear)--;
}
void delRear(int *arr, int *pfront, int *prear)
{
    if(*pfront == -1 && *prear == -1)
    {
        printf("\nDeque is empty.\n");
        return;
    }
    arr[*prear] = 0;

    (*prear)--;

}
void display(int *arr)
{
    int c = count(arr);
    FILE *fp;
    fp = fopen("test.txt", "w+");
    //printf("%d\n",c);
    for(int i = 0; i < c; i++)
    {
        printf("%d ", arr[i]);
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
}
int count(int *arr)
{
    int c = 0;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] != 0)
            c++;
    }
    return c;
}
