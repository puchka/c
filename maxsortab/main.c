#include <stdio.h>
#include <stdlib.h>

void maximumTableau(int tableau[], int tailleTableau, int valeurMax);

void ordonnerTableau (int tableau [],int tailleTableau);


int main()
{
    int tableau[10]={14,8,3,4,56,22,0,76,45,2};
    ordonnerTableau(tableau,10);
    int i;
    for (i=0;i<10;i++)
    {
        printf("%d\n",tableau[i]);
    }
    return 0;
}

void maximumTableau(int tableau[], int tailleTableau, int valeurMax)
{
    int i;
    for (i=0;i<tailleTableau;i++)
    {
        if (tableau[i]>valeurMax) tableau[i]=0;
    }
}


