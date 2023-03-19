#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void count_and_output(char *string, int *n, FILE *point);

int main(int argc, char **argv)
{
    FILE *ptr;
    ptr = fopen(argv[1], "r");

    FILE *out;
    out = fopen(argv[2], "w");

    char *string = (char*) calloc(255, sizeof(char));

    char *answer = (char*) calloc(255, sizeof(char));
    int n;

    fgets(string, 255, ptr);

    n = strlen(string);

    if(n > 255)
        n = 255;

    if(!ptr)
    {
        printf("KLAIDA SU INPUT FILE'U");
        return 0;
    }
    if(!out)
    {
        printf("KLAIDA SU OUTPUT FILE'U");
        return 0;
    }

    count_and_output(string, &n, out);

    return 0;
}

void count_and_output(char *string, int *n, FILE *point)
{
    int *amount = (int*) calloc(255, sizeof(int));
    int *positions = (int*) calloc(255, sizeof(int));

    int m = 0, len = 1;
    *positions = 0;

    for(int i = 0; i < *n; i++)
    {
        if(string[i] != string[i+1])
        {
            positions[len] = i;
            len++;
        }
    }

    len--;

    for(int i = 0; i < *n; i++)
    {
        if(string[i] != ' ')
        {
            if(string[i] == string[i+1]) //loop to remove duplicate chars
            {
               for(int j = i; j < *n; j++)
               {
                   string[j] = string[j+1];
               }
               (*n)--;
               i--;
            }
        } else
        {
            continue;
        }

    }

    amount[0] = 1;

    for(int i = 0; i < len - 1; i++)
    {
        if(positions[i+1] - positions[i] == 1)
        {
            amount[i] = 1;
        } else
        {
            amount[i] += positions[i + 1] - positions[i];
        }
    }

    (*n)--;


    for(int i = 0; i < (*n); i++)
    {
        if(amount[i] > 1)
        {
            fprintf(point,"%c$%d", string[i], amount[i]);
        } else
        {
            fprintf(point,"%c", string[i]);
        }
    }
    fclose(point);

}
