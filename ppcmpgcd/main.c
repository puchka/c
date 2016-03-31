#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    int a,b,x,t,m;
    printf("Entrez le premier entier positif:\t");
    scanf("%d",&a);
    printf("\nEntrez le deuxieme entier positif:\t");
    scanf("%d",&b);
    if (b>a)
    {
        x=b;
        b=a;
        a=x;
    }
    if (a%b==0)
        printf("\nLe PPCM est :\t%d",a);
    else
    {
        t=(a*b);
        while(b != 0)
        {
            x = a%b;
            a = b;
            b = x;
        }
        m=t/a;
        printf("\nLe PPCM est :\t%d ",m);
    }
    while(b != 0)
    {
        x = a%b;
        a = b;
        b = x;
    }
    printf("\nLe PGCD est :\t%d", a);
    getch();
    return EXIT_SUCCESS;
}
