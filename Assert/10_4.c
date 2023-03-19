#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 40

//FUNCTIONS THAT

char *my_strchr(const char *str, int c); //searches for the first occurrence of the character c
char *my_strrchr(const char *str, int c); //serrches for the last occurence in string
char *my_strstr(const char *haystack, const char *needle); //basically searcher  for a substring and then prints the entire string from it, returns pointer

int main(void)
{
    char *ret, *ret1, *ret2, *ret3;
    const char str[] = "tihis is byber";
    const char str1[] = "is";
    const char c = 'b';
    ret = my_strchr(str, c);
    ret1 = my_strrchr(str, c);

    assert(my_strrchr(str,c) == strrchr(str, c));
    assert(my_strchr(str, c) == strchr(str, c));

    ret2 = strstr(str, str1);

    //printf("%s", ret2);

    ret3 = my_strstr(str, str1);

    //assert(strstr(str, str1) == my_strstr(str, str1));
    //assert(my_strstr(str, str1) == strstr(str, str1));

    printf("%s \n", ret2);
    printf("%-s", ret3);

    return 0;
}

char *my_strchr(const char *str, int c)
{
    //returns NULL if nothing found, returns pointer to the character
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == c)
            return &str[i];
    }

    return NULL;
}

char *my_strrchr(const char *str, int c)
{
    for(int i = strlen(str); i > 0; i--)
    {
        if(str[i] == c)
            return &str[i];
    }

    return NULL;
}

char *my_strstr(const char *haystack, const char *needle)
{
    int i = 0, j = 0, firstOccurence;

    while(haystack[i] != '\0')
    {
        while(haystack[i] != needle[0] && haystack[i] != '\0')
        {
            i++;
        }

        if(haystack[i] == '\0')
            return NULL;

        firstOccurence = i;

        while(haystack[i] == needle[j] && haystack[i] != '\0' && needle[j] != '\0')
        {
            i++;
            j++;
        }

        if(needle[j] == '\0')
            return &(needle[firstOccurence]);

        if(haystack[i] == '\0')
            return NULL;

        i = firstOccurence + 1;
        j = 0;
    }

    return NULL;
}
