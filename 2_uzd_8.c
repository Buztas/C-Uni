#include <stdio.h>
#include <stdlib.h>

//lyg_nelyg[0] = lyg sk. lyg_nelyg[1] = nelyg sk.
int min(int a, int b);
void skaitymas(int *lyg, int *nelyg, int n, int no[], int l[]);
int suma(int p, int lyg[], int nelyg[]);
int main(void)
{
    int n;
    scanf("%d", &n);
    int mini;
    int lyg ;
    int nelyg ;
    int lyginiai[101];
    int nelyginiai[101];
    skaitymas(&lyg,&nelyg,n,lyginiai, nelyginiai);
    //printf("lyg %d - nelyg %d \n", lyg_nelyg[0], lyg_nelyg[1]);
    if(lyg == 0 && nelyg > 0)
        {printf("visi skaiciai nelyginiai."); return 0;}
    else if(nelyg == 0 && lyg > 0)
        {printf("visi skaiciai lyginiai."); return 0;}

    int p = min(lyg,nelyg);
    int sum = suma(p, lyginiai, nelyginiai);
    printf("skaiciu suma = %d", sum);
    return 0;
}
int min(int a, int b)
{
    int mini;
    if(a < b) mini = a;
    else mini = b;

    return mini;
}
void skaitymas(int *lyg, int *nelyg, int n, int no[], int l[])
{
    int number;
    *lyg = 0, *nelyg = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &number);
        if(number % 2 == 0)
        {
            no[*lyg] = number;
            (*lyg)++;
        }
        else
        {
            l[*nelyg] = number;
            (*nelyg)++;
        }
    }
    //printf("%d - %d\n", *lyg, *nelyg);
}
int suma(int p, int lyg[], int nelyg[])
{
    int sum = 0;
    for(int i = 0; i < p; i++)
    {
        sum += lyg[i] * nelyg[i];
    }
    return sum;
}
