#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int i, pix;
    for (i=0;i<10000;i++)
    {
        srand(time(NULL));
        pix = rand();
        printf("%d ", pix);
    }
    return 0;
}
