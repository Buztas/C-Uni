#include <stdio.h>
#include <stdlib.h>

int nums[100001];

int main(void)
{
    int n;
    printf("Iveskite n \n");
    scanf("%d", &n);
    printf("veskite skaicius \n");
    int sum, avg, min,max;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        sum+= nums[i];
    }
    avg = sum / n;
    max = 0; min = 1000000;
    for(int i = 0; i < n; i++)
    {
        if(min> nums[i]) min = nums[i];
        if(max < nums[i]) max = nums[i];
    }
    printf("Suma: %d \nVidurkis: %d \nMin: %d \nMax: %d", sum,avg,max,min);
    return 0;

}
