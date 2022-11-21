#include <stdio.h>
#include <stdlib.h>

void change(char *string, int *n);

int main(void)
{
    char string[1001];
    printf("Iveskite stringa: \n");
    gets(string);
    int len = strlen(string);

    change(string, &len);

    return 0;
}
void change(char *string, int *n)
{
    int i, j;
    int pos = 1;
    int *kiekis = (int*) calloc(n, sizeof(int));
    int m = 0;
    int kiek = 0;
    printf("%d\n", *n);
    for(i = 0; i < *n; i++)
    {
        if(string[i] == string[i+1])
        {
           for(j = i; j < *n; j++)
           {
               string[j] = string[j+1];
               kiekis[m]++;
           }
           (*n)--;
           i--;
           m++;
        }
    }
    for(int i = 0; i < *n; i++)
    {
        printf("%c", string[i]);
    }
    for(int i = 0; i < m; i++)
    {
        printf("\n%d", kiekis[i]);
    }
    //printf("%d", kiek);
}
