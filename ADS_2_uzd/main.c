#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 13.	Turime N darbų, kurių atlikimo trukmė t1, t2,..tN¬, kurių baigimo terminai d1, d2,..dN. 
// Jei darbai neatliekami laiku, bauda atitinkamai b1, b2,..bN. 
// Kokia eilės tvarka atlikti darbus, kad bauda būtų minimali.
typedef struct jobs
{
    int time;
    int deadline;
    int penalty;
} Job;

int compare(const void* a_ptr, const void* b_ptr);
int max(int num1, int num2);
void printOptimal(Job arr[], int n);

int main(void)
{
    Job arr[] = { { 1, 2, 100 },
                  { 4, 3, 19 },
                  { 3, 2, 27 },
                  { 7, 20, 25 },
                  { 3, 11, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Optimal solution: \n");
    printOptimal(arr, n);

    return 0;
}

//important to check for used
int compare(const void* a, const void* b)
{
    Job *temp1 = (Job*)a;
    Job *temp2 = (Job*)b;
    return(temp2->penalty - temp1->penalty);
}

int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

void printOptimal(Job arr[], int n)
{
    qsort(arr, n, sizeof(Job), compare);
    int result[n]; // To store result (Sequence of jobs)
    bool slot[n]; // To keep track of free time slots
    int optimal[n];

    for(int i = 0; i < n; i++)
        slot[i] = false;

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i].deadline > arr[i].time)
        {
            slot[i] = true;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(slot[i] == true)
        {
            for(int j = i; j < n; j++)
            {
                if(sum < arr[j].deadline)
                {
                    sum += arr[j].time;
                    result[j] = i;
                    slot[j] = true;
                    printf("%d ", sum);
                    break;
                }
            }
        }
    }

    printf("\n");
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(slot[i])
        {
            printf("%d-uzdavinys, kurio trukme: %d \n", result[i] + 1, arr[result[i]].time);
        }
    }
}

