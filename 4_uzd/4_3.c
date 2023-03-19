#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Iveskite tris neneigiamus sveikuosius skaicius \n");
    signed int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d %d %d \n",a,b,c);
    int elements[101] = {a,b};
    int temp;
    //f0 = a; f1 = b; fc = ?
    //fc = fc-1 fc-2;
    for(int i = 2; i < c; i++)
    {
        elements[i] = elements[i-1] + elements[i-2];
        temp = elements[i];
    }
    printf("c = %d", temp);
}
