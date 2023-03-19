#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#define N 10
#include <stdlib.h>
#include <stdio.h>

void addFront(int *arr, int item, int *pfront, int *prear);
void addRear(int *arr, int item, int *pfront, int *prear);
void delFront(int *arr, int *pfront, int *prear);
void delRear(int *arr, int *pfront, int *prear);
int count(int *arr);
void display(int *arr);

#endif // DEQUE_H_INCLUDED
