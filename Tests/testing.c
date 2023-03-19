#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int d    = 15   ; //Day     1-31
    int m    = 5    ; //Month   1-12`
    int y    = 2013 ; //Year    2013`

    int weekday  = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;
    printf("%d", weekday);
}
