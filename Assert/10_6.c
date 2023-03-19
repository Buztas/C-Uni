#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//THIS FUNCTION COUNTS THE AMOUNT OF CHARACTERS UNTIL THE FIRST CHARACTER THAT MATCHES
size_t my_strcspn(const char *str1, const char *str2);

int main(void)
{
    const char str1[] = "ABCDEF4960910";
    const char str2[] = "013";

    size_t len = my_strcspn(str1, str2);
    size_t len1 = strcspn(str1, str2);

    assert(my_strcspn(str1, str2) == strcspn(str1, str2));

    printf("my: %d -  C: %d", len, len1);

    return 0;
}

size_t my_strcspn(const char *str1, const char *str2)
{
    size_t amount = 0;
    for(int i = 0; i < strlen(str1); i++)
    {
        if(str1[i] != str2[0])
            amount++;
        else
            return amount;
    }

    return 0;
}
