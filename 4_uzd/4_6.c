#include <stdio.h>
#include <stdlib.h>

int nums[101];
int temps[101];
int divs[101] = {0};

int main(void)
{
    int a = 5; int i = 0;
    int max_count = 0, max_pos;
    printf("Veskite skaicius, rasykite neigiama, jei norite baigti seka \n");
    while(a > 0)
    {
        scanf("%d", &a);
        nums[i] = a;
        i++;
    }
    int n = i -1;
    for(int i = 0; i < n; i++)
    {
        temps[i] = nums[i];
        while(nums[i] != 0)
        {
            nums[i] /= 10;
            divs[i]++;
        }
        if(max_count < divs[i]) {max_count = divs[i]; max_pos = i;}
    }
    printf("%d - %d", temps[max_pos], max_count);
    return 0;
}
