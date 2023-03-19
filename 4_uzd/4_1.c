#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //rasti kvadratines lygties ats.
    int a,b,c;
    printf("Iveskite a,b,c \n");
    scanf_s("%d%d%d", &a,&b,&c);
    printf("%d %d %d", a,b,c);
    int d = pow(b,2) - 4*a*c;
    int result;
    int result1;
    if(d < 0)
    {
        printf("\n Diskriminantas neigiamas, atsakymu nera arba ju labai daug\n");
    }
    if(d == 0)
    {
        result = (b*(-1)+sqrt(d))/(2*a);
        printf("\n yra 1 atsakymas: %d", result);
    }
    if(d > 0)
    {
        result = (b*(-1)+sqrt(d))/(2*a);
        result1 = (b*(-1)-sqrt(d))/(2*a);
        printf("\nYra 2 atsakymai: %d ir %d", result, result1);
    }
    return 0 ;
}
