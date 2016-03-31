#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 2;
    while(n<(8*(log(n)/log(2))))
        n++;
    printf("n = %d\n", n);
    return 0;
}
