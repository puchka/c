#include <stdio.h>
#include <stdlib.h>

void dec2bin(int dec, int tab[8]);

int main()
{
    int dec = 255;
    int bin[8]={0};
    dec2bin(dec, bin);
    int j;
    for (j=0;j<8;j++)
    {
        printf("%d\n",bin [j]);
    }
    return 0;
}

void  dec2bin(int dec, int tab[8])
{
    int i=7, b=0;
    while(dec>=1)
    {
        b=dec%2;
        tab[i]=b;
        dec=dec/2;
        i--;
    }
}
