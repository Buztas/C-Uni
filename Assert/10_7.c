#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//THIS FUNCTION finds the first character in the string str1 that matches any character specified in str2. This does not include the terminating null-characters.
char *my_strpbrk(const char *s1, const char *s2);

int main(void)
{
   const char str1[] = "abcde2fghi3jk4l";
   const char str2[] = "34";
   char *ret;

   ret = my_strpbrk(str1, str2);
   assert(my_strpbrk(str1,str2) == strpbrk(str1,str2));

   printf("%c", *ret);

    return 0;
}

char *my_strpbrk(const char *s1, const char *s2)
{
    for(int i = 0; i <  strlen(s1); i++)
    {
        for(int j = 0; j < strlen(s2); j++)
        {
            if(s1[i] == s2[j])
                return &s1[i];
        }
    }

    return NULL;
}
