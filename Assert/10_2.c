#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char* my_strcpy(char* destination, const char* source);
char* my_strcat(char *destination, const char *source);
int my_strcmp (const char* str1, const char* str2);

int main(void)
{
    char str1[100] = "This is ";
    char str2[] = "This is   ";

    assert(strcpy(str2,str1) == my_strcpy(str2,str1));
    //assert(my_strcpy(str2, " sdfasdf as dfa sdf as dfas dfas df asdf ") == NULL);
    //my_strcpy(str2,str1); //works!
    //assert(strcat(str1,str2) == my_strcat(str1,str2));
    //my_strcat(str1, str2); // works
    int val1 = my_strcmp(str1, str2);
    int val2 = strcmp(str1, str2);
    //printf("my_strcmp: %d\nstrcmp: %d", val1, val2);
    //assert(strcmp(str1,str2) == my_strcmp(str1,str2)); //works!!!!

    return 0;
}

int my_strcmp (const char* str1, const char* str2)
{
    int length = str2;
    if(strlen(str1) > strlen(str2))
        length = str1;
    for(int i = 0; i < length; i++)
    {
        if(str1[i] > str2[i])
            return 1;
        if(str1[i] < str2[i])
            return -1;
    }

    return 0;
}

char* my_strcat(char *destination, const char *source)
{
    for(int i = strlen(destination), j = 0; i < strlen(destination), j < strlen(source); i++, j++)
    {
        destination[i] = source[j];
    }

    return destination;
}

char* my_strcpy(char* destination, const char* source)
{
    for(int i = 0 ; i < strlen(source); i++)
    {
        destination[i] = source[i];
    }

    return destination;
    //printf("%d - %d", strlen(source), strlen(destination));
}
