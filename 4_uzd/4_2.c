#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Iveskite a,b,c \n");
    int a,b,c; scanf("%d%d%d", &a,&b,&c);
    printf("Skaiciai, kurie dalijasi is c su liekana 1: \n");
    for(int i = a+1; i <= b; i++)
    {
        if(i % c == 1)
        printf("%d \n", i);
    }
}
