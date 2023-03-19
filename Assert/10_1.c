#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

size_t my_strlen(char string[]);

int main(void)
{
    char *string = malloc(101 * sizeof(char));

    //char *string;

    printf("Iveskite stringa: \n");
    fgets(string, 101, stdin);

    assert(strlen(string) == my_strlen(string));
    assert("ksjfdlacxvnamfgjvcaklxffc.j,xvafmkgl" == 1); //bad test
    printf("%d", my_strlen(string));

    free(string);

    return 0;
}

size_t my_strlen(char* string) //size_t basically returns the size of the object in bytes
{
    int n = 0;

    while(string[n] != '\0')
    {
        n++;
    }

    return n;
}
