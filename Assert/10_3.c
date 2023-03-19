#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define SIZE 40

char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strncat(char *dest, const char *src, size_t n);
int my_strncmp(const char *str1, const char *str2, size_t n);

int main(void)
{
    char str1[SIZE] = "thing";
    char str3[SIZE] = "thing";
    const char str2[SIZE] = "copy this";
    assert(strncpy(str1, str2, 6) == my_strncpy(str1,str2,6));
    //assert("dfklvsxfgl" == my_strncpy(str1, str2, 8));
    //assert(strncat(str1, str2, 6) == my_strncat(str1,str2, 6));
    assert(my_strncat(str1,str2, 5) == strncat(str1, str2, 5));
    assert(my_strncmp(str1, str2, 5) == strncmp(str1, str2, 5));
    //assert(my_strncmp(str1, str2, 5) == 1);
    //assert(strncmp(str1, str2, 5) == -1);
    //strncat(str1, str2, 11);
    printf("%s", str1);

    return 0;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    for(int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    return dest;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
    for(int i = strlen(dest), j = 0; i < strlen(dest) + n, j < n; i++, j++)
    {
        dest[i] = src[j];
    }

    return dest;
}

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    for(int i = 0; i < n; i++)
    {
        if(str1[i] > str2[i])
            return 1;
        if(str1[i] < str2[i])
            return -1;
    }

    return 0;
}
