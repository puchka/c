#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    a = 1;
    b = 2;
    a = a^b;
    b = b^a;
    a = a^b;
    printf("a = %d ; b = %d", a, b);
    return 0;
}
