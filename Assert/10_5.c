#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void *my_memcpy(void *dest, const void * src, size_t n);
int my_memcmp(const void *str1, const void *str2, size_t n);
void *my_memset(void *str, int c, size_t n);
void *my_memchr(const void *str, int c, size_t n);

int main(void)
{
    char str[] = "hey";
    char str1[] = "helbo it is me";

    int value = 0x1934523;

    assert(my_memcpy(str, str1, 5) == memcpy(str, str1, 5));
    assert(my_memcmp(str, str1, 5) == memcmp(str, str1, 5));
    assert(my_memset(str, 'z', 2) == memset(str, value, 2));
    assert(my_memchr(str, 'b', 5) == memchr(str, 'b', 5));

    printf("%s", str);

    return 0;
}

void *my_memcpy(void *dest, const void * src, size_t n)
{
    size_t type_given = (sizeof(n)/8);

    char *cdest = (char*) dest;
    char *csrc = (char*) src;

    int *idest = (int*) dest;
    int *isrc = (int*) src;

    for(size_t i = 0; i < n; i++)
    {
        if(type_given == 1)
        {
            cdest[i] = csrc[i];
        }
        if(type_given == 4)
        {
            idest[i] = isrc[i];
        }
    }

    return dest;
}

int my_memcmp(const void *str1, const void *str2, size_t n)
{
    char* cstr1 = (char*) str1;
    char* cstr2 = (char*) str2;

    for(size_t i = 0; i < n; i++)
    {
        if(cstr1[i] < cstr2[i])
            return -1;
        if(cstr1[i] > cstr2[i])
            return 1;
    }

    return 0;
}

void *my_memset(void *str, int c, size_t n)
{
    char* cstr = (char*) str;

    for(size_t i = 0; i < n; i++)
    {
        cstr[i] = c;
    }

    return str;
}

void *my_memchr(const void *str, int c, size_t n)
{
    const unsigned char *p = (const unsigned char*) str;

    for(size_t i = 0; i < n; i++)
    {
        if(p[i] == (unsigned char) c)
            return (void*)(p+i);
    }

    return NULL;
}
