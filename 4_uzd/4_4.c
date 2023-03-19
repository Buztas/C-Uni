#include <stdio.h>
#include <stdlib.h>

int divisors[101];
int main(void)
{
    printf("Iveskite tris naturaliuosius skaicius \n");
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int max = (a > c) ? ((a > b) ? a : b) : ((c > b) ? c : b);
    int gcd, lcm;

    for(int i = max; i > 1; i--)
    {
        if((a%i == 0) && (b%i == 0) && (c%i == 0))
        {
            gcd = i;
        }
    }
    for(int i = 1; i < (a*b*c); i++)
    {
        if((i%a == 0) && (i%b == 0) && (i%c == 0))
        {
           lcm = i;
           break;
        }
    }
    printf("\nDBD - %d, MBK - %d", gcd, lcm);
    return 0;
}
